/* file: logistic_cross_layer_backward_impl.i */
/*******************************************************************************
* Copyright 2014-2019 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of the backward logistic cross layer
//--
*/

#ifndef __LOGISTIC_CROSS_LAYER_BACKWARD_IMPL_I__
#define __LOGISTIC_CROSS_LAYER_BACKWARD_IMPL_I__

using namespace daal::internal;
using namespace daal::services;

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace loss
{
namespace logistic_cross
{
namespace backward
{
namespace internal
{

template<typename algorithmFPType, Method method, CpuType cpu>
services::Status LogisticCrossKernel<algorithmFPType, method, cpu>::compute(
    const Tensor &inputTensor,
    const Tensor &groundTruthTensor,
    Tensor &resultTensor)
{
    size_t nRowsToProcess = inputTensor.getDimensionSize(0);
    ReadSubtensor<algorithmFPType, cpu, Tensor> inputBlock(const_cast<Tensor &>(inputTensor), 0, 0, 0, nRowsToProcess);
    DAAL_CHECK_BLOCK_STATUS(inputBlock);
    const algorithmFPType *inputArray = inputBlock.get();

    ReadSubtensor<algorithmFPType, cpu, Tensor> groundTruthBlock(const_cast<Tensor &>(groundTruthTensor), 0, 0, 0, nRowsToProcess);
    DAAL_CHECK_BLOCK_STATUS(groundTruthBlock);
    const algorithmFPType *groundTruthArray = groundTruthBlock.get();

    WriteSubtensor<algorithmFPType, cpu, Tensor> resultBlock(resultTensor, 0, 0, 0, nRowsToProcess);
    DAAL_CHECK_BLOCK_STATUS(resultBlock);
    algorithmFPType *resultArray = resultBlock.get();

    logistic::forward::internal::LogisticKernel<algorithmFPType, logistic::defaultDense, cpu> logisticKernel;
    logisticKernel.compute(inputTensor, resultTensor);

    size_t nDataElements = inputBlock.getSize();
    algorithmFPType invBatchSize = 1.0 / (inputTensor.getDimensionSize(0));
    for(size_t i = 0; i < nDataElements; i++)
    {
        resultArray[i] = invBatchSize * (resultArray[i] - groundTruthArray[i]);
    }
    return services::Status();
}

} // internal
} // backward
} // namespace logistic_cross
} // namespace loss
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal

#endif
