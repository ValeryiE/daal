/* file: spatial_maximum_pooling2d_layer_types.h */
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
//  Implementation of spatial pyramid maximum 2D pooling layer.
//--
*/

#ifndef __SPATIAL_MAXIMUM_POOLING2D_LAYER_TYPES_H__
#define __SPATIAL_MAXIMUM_POOLING2D_LAYER_TYPES_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "data_management/data/homogen_tensor.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/spatial_pooling2d/spatial_pooling2d_layer_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
/**
 * @defgroup spatial_maximum_pooling2d Two-dimensional Spatial pyramid maximum Pooling Layer
 * \copydoc daal::algorithms::neural_networks::layers::spatial_maximum_pooling2d
 * @ingroup spatial_pooling2d
 * @{
 */
namespace spatial_maximum_pooling2d
{
/**
 * <a name="DAAL-ENUM-ALGORITHMS__NEURAL_NETWORKS__LAYERS__SPATIAL_MAXIMUM_POOLING2D__METHOD"></a>
 * \brief Computation methods for the spatial pyramid maximum 2D pooling layer
 */
enum Method
{
    defaultDense = 0    /*!< Default: performance-oriented method */
};

/**
 * \brief Identifiers of input tensors for the backward spatial pyramid maximum 2D pooling layer
 *        and results for the forward spatial pyramid maximum 2D pooling layer
 */
enum LayerDataId
{
    auxSelectedIndices,         /*!< p-dimensional tensor that stores the positions of spatial pyramid maximum elements */
    lastLayerDataId = auxSelectedIndices
};

/**
 * \brief Identifiers of input numeric tables for the backward spatial pyramid maximum 2D pooling layer
 *        and results for the forward spatial pyramid maximum 2D pooling layer
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
 * <a name="DAAL-STRUCT-ALGORITHMS__NEURAL_NETWORKS__LAYERS__SPATIAL_MAXIMUM_POOLING2D__PARAMETER"></a>
 * \brief Parameters for the spatial pyramid maximum 2D pooling layer
 *
 * \snippet neural_networks/layers/spatial_pooling2d/spatial_maximum_pooling2d_layer_types.h Parameter source code
 * \DAAL_DEPRECATED
 */
/* [Parameter source code] */
struct DAAL_EXPORT Parameter: public spatial_pooling2d::Parameter
{
    /*
     * \DAAL_DEPRECATED
     */
    Parameter(size_t pyramidHeight, size_t firstIndex, size_t secondIndex);
};
/* [Parameter source code] */

} // interface1
using interface1::Parameter;

} // namespace spatial_maximum_pooling2d
/** @} */
} // namespace layers
} // namespace neural_networks
} // namespace algorithm
} // namespace daal

#endif
