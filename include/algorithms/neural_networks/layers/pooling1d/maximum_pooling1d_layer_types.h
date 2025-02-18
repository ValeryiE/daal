/* file: maximum_pooling1d_layer_types.h */
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
//  Implementation of maximum 1D pooling layer.
//--
*/

#ifndef __MAXIMUM_POOLING1D_LAYER_TYPES_H__
#define __MAXIMUM_POOLING1D_LAYER_TYPES_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "data_management/data/homogen_tensor.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/pooling1d/pooling1d_layer_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
/**
 * @defgroup maximum_pooling1d One-dimensional Max Pooling Layer
 * \copydoc daal::algorithms::neural_networks::layers::maximum_pooling1d
 * @ingroup pooling1d
 * @{
 */
namespace maximum_pooling1d
{
/**
 * <a name="DAAL-ENUM-ALGORITHMS__NEURAL_NETWORKS__LAYERS__MAXIMUM_POOLING1D__METHOD"></a>
 * \brief Computation methods for the maximum 1D pooling layer
 */
enum Method
{
    defaultDense = 0    /*!< Default: performance-oriented method */
};

/**
 * \brief Identifiers of input tensors for the backward maximum 1D pooling layer
 *        and results for the forward maximum 1D pooling layer
 */
enum LayerDataId
{
    auxSelectedIndices,         /*!< p-dimensional tensor that stores the positions of maximum elements */
    lastLayerDataId = auxSelectedIndices
};

/**
 * \brief Identifiers of input numeric tables for the backward maximum 1D pooling layer
 *        and results for the forward maximum 1D pooling layer
 */
enum LayerDataNumericTableId
{
    auxInputDimensions  = lastLayerDataId + 1,         /*!< Numeric table of size 1 x p that contains the sizes
                                          of the dimensions of the input data tensor */
    lastLayerDataNumericTableId = auxInputDimensions
};

/**
 * \brief Contains version 1.0 of Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface1
{

/**
 * <a name="DAAL-STRUCT-ALGORITHMS__NEURAL_NETWORKS__LAYERS__MAXIMUM_POOLING1D__PARAMETER"></a>
 * \brief Parameters for the maximum 1D pooling layer
 *
 * \snippet neural_networks/layers/pooling1d/maximum_pooling1d_layer_types.h Parameter source code
 * \DAAL_DEPRECATED
 */
/* [Parameter source code] */
struct DAAL_EXPORT Parameter: public pooling1d::Parameter
{
    /**
     * Constructs the parameters of maximum 1D pooling layer
     * \param[in] index        Index of the dimension on which pooling is performed
     * \param[in] kernelSize   Size of 1D subtensor for which the maximum element is selected
     * \param[in] stride       Interval over the dimension on which the pooling is performed
     * \param[in] padding      Number of data elements to implicitly add to the the dimension
     *                         of the 1D subtensor on which the pooling is performed
     * \DAAL_DEPRECATED
     */
    Parameter(size_t index, size_t kernelSize = 2, size_t stride = 2, size_t padding = 0);
};
/* [Parameter source code] */

} // interface1
using interface1::Parameter;

} // namespace maximum_pooling1d
/** @} */
} // namespace layers
} // namespace neural_networks
} // namespace algorithm
} // namespace daal

#endif
