/* file: pooling2d_layer_forward_types.h */
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
//  Implementation of the forward 2D pooling layer types.
//--
*/

#ifndef __POOLING2D_LAYER_FORWARD_TYPES_H__
#define __POOLING2D_LAYER_FORWARD_TYPES_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "data_management/data/homogen_tensor.h"
#include "data_management/data/homogen_numeric_table.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/layer_forward_types.h"
#include "algorithms/neural_networks/layers/pooling2d/pooling2d_layer_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace pooling2d
{
/**
 * @defgroup pooling2d_forward Forward Two-dimensional Pooling Layer
 * \copydoc daal::algorithms::neural_networks::layers::pooling2d::forward
 * @ingroup pooling2d
 * @{
 */
/**
 * \brief Contains classes for the forward two-dimensional (2D) pooling layer
 */
namespace forward
{
/**
 * \brief Contains version 1.0 of Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface1
{
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__POOLING2D__FORWARD__INPUT"></a>
 * \brief %Input objects for the forward 2D pooling layer
 * \DAAL_DEPRECATED
 */
class DAAL_EXPORT Input : public layers::forward::Input
{
public:
    typedef layers::forward::Input super;
    /**
     * Default constructor
     * \DAAL_DEPRECATED
     */
    Input();

    /**
     * Copy constructor
     * \DAAL_DEPRECATED
     */
    Input(const Input& other);

    virtual ~Input() {}

    /**
     * Returns dimensions of weights tensor
     * \return Dimensions of weights tensor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual const services::Collection<size_t> getWeightsSizes(const layers::Parameter *parameter) const DAAL_C11_OVERRIDE;

    /**
     * Returns dimensions of biases tensor
     * \return Dimensions of biases tensor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual const services::Collection<size_t> getBiasesSizes(const layers::Parameter *parameter) const DAAL_C11_OVERRIDE;

    /**
     * Checks an input object for the 2D pooling layer
     * \param[in] parameter %Parameter of the layer
     * \param[in] method    Computation method of the layer
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status check(const daal::algorithms::Parameter *parameter, int method) const DAAL_C11_OVERRIDE;
};


/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__POOLING2D__FORWARD__RESULT"></a>
 * \brief Provides methods to access the result obtained with the compute() method
 *        of the forward 2D pooling layer
 * \DAAL_DEPRECATED
 */
class DAAL_EXPORT Result : public layers::forward::Result
{
public:
    /**
     * Default constructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Result();
    /*
     * \DAAL_DEPRECATED
     */
    virtual ~Result() {}

    /**
     * Returns dimensions of value tensor
     * \return Dimensions of value tensor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual const services::Collection<size_t> getValueSize(const services::Collection<size_t> &inputSize,
                                                            const daal::algorithms::Parameter *par, const int method) const DAAL_C11_OVERRIDE;
    /**
     * Allocates memory to store the result of the forward 2D pooling layer
     * \param[in] input Pointer to an object containing the input data
     * \param[in] method Computation method for the layer
     * \param[in] parameter %Parameter of the forward 2D pooling layer
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    template <typename algorithmFPType>
    DAAL_EXPORT services::Status allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method);

    /**
     * Checks the result of the forward 2D pooling layer
     * \param[in] input %Input object for the layer
     * \param[in] parameter %Parameter of the layer
     * \param[in] method Computation method
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    services::Status check(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, int method) const DAAL_C11_OVERRIDE;

protected:
    /*
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED size_t computeValueDimension(size_t dataDim, size_t kernelSize, size_t padding, size_t stride) const;

    /*
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED void computeValueDimensions(services::Collection<size_t> &dims, const Parameter *param) const;

    /*
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED data_management::NumericTablePtr createAuxInputDimensions(const services::Collection<size_t> &dataDims) const;
};

} // namespace interface1
using interface1::Input;
using interface1::Result;

} // namespace forward
/** @} */
} // namespace pooling2d
} // namespace layers
} // namespace neural_networks
} // namespace algorithm
} // namespace daal

#endif
