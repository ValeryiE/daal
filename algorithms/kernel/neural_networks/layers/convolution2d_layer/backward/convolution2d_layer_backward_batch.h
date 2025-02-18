/* file: convolution2d_layer_backward_batch.h */
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
//  Implementation of onvolution2d calculation algorithm and types methods.
//--
*/

#include "convolution2d_layer_backward_types.h"
#include "convolution2d_layer_types.h"

#include "service_mkl_tensor.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace convolution2d
{
namespace backward
{
namespace interface1
{
/**
 * Allocates memory to store the result of backward 2D convolution layer
 * \param[in] input     Object containing the input data
 * \param[in] parameter %Parameter of backward 2D convolution layer
 * \param[in] method    Computation method
 */
template <typename algorithmFPType>
DAAL_EXPORT services::Status Result::allocate(const daal::algorithms::Input *input,
                                              const daal::algorithms::Parameter *parameter,
                                              const int method)
{
    using namespace daal::data_management;
    using daal::data_management::TensorPtr;
    using daal::internal::MklTensor;

    const Input *in = static_cast<const Input *>(input);
    const Parameter *param =  static_cast<const Parameter * >(parameter);

    services::Collection<size_t> bDims;
    bDims.push_back(param->nKernels);

    TensorPtr valueTable = in->get(auxData);
    TensorPtr wTable     = in->get(auxWeights);

    if(valueTable == 0 || wTable == 0) return services::Status(services::ErrorNullInputNumericTable);

    if (param->propagateGradient && !get(layers::backward::gradient))
    {
        set(layers::backward::gradient, TensorPtr(
                        new MklTensor<algorithmFPType>(valueTable->getDimensions(), Tensor::doAllocate)));
    }
    if (!get(layers::backward::weightDerivatives))
    {
        set(layers::backward::weightDerivatives, TensorPtr(
                        new MklTensor<algorithmFPType>(wTable->getDimensions(), Tensor::doAllocate)));
    }
    if (!get(layers::backward::biasDerivatives))
    {
        set(layers::backward::biasDerivatives, TensorPtr(
                        new MklTensor<algorithmFPType>(bDims, Tensor::doAllocate)));
    }
    return services::Status();
}

}// namespace interface1
}// namespace forward
}// namespace convolution2d
}// namespace layers
}// namespace neural_networks
}// namespace algorithms
}// namespace daal
