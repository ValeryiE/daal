/* file: maximum_pooling2d_layer_backward_batch_container.h */
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
//  Implementation of backward pooling layer container.
//--
*/

#ifndef __MAXIMUM_POOLING2D_LAYER_BACKWARD_BATCH_CONTAINER_H__
#define __MAXIMUM_POOLING2D_LAYER_BACKWARD_BATCH_CONTAINER_H__

#include "neural_networks/layers/pooling2d/maximum_pooling2d_layer.h"
#include "maximum_pooling2d_layer_backward_kernel.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace maximum_pooling2d
{
namespace backward
{
namespace interface1
{
template<typename algorithmFPType, Method method, CpuType cpu>
BatchContainer<algorithmFPType, method, cpu>::BatchContainer(daal::services::Environment::env *daalEnv)
{
    __DAAL_INITIALIZE_KERNELS(internal::PoolingKernel, algorithmFPType, method);
}

template<typename algorithmFPType, Method method, CpuType cpu>
BatchContainer<algorithmFPType, method, cpu>::~BatchContainer()
{
    __DAAL_DEINITIALIZE_KERNELS();
}

template<typename algorithmFPType, Method method, CpuType cpu>
services::Status BatchContainer<algorithmFPType, method, cpu>::setupCompute()
{
    maximum_pooling2d::backward::Input *input = static_cast<maximum_pooling2d::backward::Input *>(_in);
    maximum_pooling2d::backward::Result *result = static_cast<maximum_pooling2d::backward::Result *>(_res);

    daal::services::Environment::env &env = *_env;

    const services::Collection<size_t>& inDimsFull  = input->get(layers::backward::inputGradient)->getDimensions();
    const services::Collection<size_t>& outDimsFull = result->get(layers::backward::gradient)->getDimensions();

    __DAAL_CALL_KERNEL(env, internal::PoolingKernel, __DAAL_KERNEL_ARGUMENTS(algorithmFPType, method), initialize, inDimsFull, outDimsFull);
}

template<typename algorithmFPType, Method method, CpuType cpu>
services::Status BatchContainer<algorithmFPType, method, cpu>::compute()
{
    maximum_pooling2d::backward::Input  *input  = static_cast<maximum_pooling2d::backward::Input *>(_in);
    maximum_pooling2d::backward::Result *result = static_cast<maximum_pooling2d::backward::Result *>(_res);

    Tensor *dataTensor = input->get(auxData).get();
    Tensor *inputGradTensor   = input->get(layers::backward::inputGradient).get();
    Tensor *selectedPosTensor = input->get(auxSelectedIndices).get();
    Tensor *gradTensor = result->get(layers::backward::gradient).get();

    maximum_pooling2d::Parameter *parameter = static_cast<maximum_pooling2d::Parameter *>(_par);
    if (!parameter->propagateGradient) { return services::Status(); }

    daal::services::Environment::env &env = *_env;

    __DAAL_CALL_KERNEL(env, internal::PoolingKernel, __DAAL_KERNEL_ARGUMENTS(algorithmFPType, method),   \
                       compute, *inputGradTensor, *selectedPosTensor, *gradTensor, dataTensor, *parameter);
}
} // namespace interface1
} // namespace backward

} // namespace maximum_pooling2d
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal

#endif
