/* file: batch_normalization_layer_types.h */
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
//  Implementation of the batch normalization layer.
//--
*/

#ifndef __BATCH_NORMALIZATION_LAYER_TYPES_H__
#define __BATCH_NORMALIZATION_LAYER_TYPES_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "data_management/data/homogen_tensor.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/layer_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
/**
 * @defgroup batch_normalization Batch Normalization Layer
 * \copydoc daal::algorithms::neural_networks::layers::batch_normalization
 * @ingroup layers
 * @{
 */
namespace batch_normalization
{
/**
 * <a name="DAAL-ENUM-ALGORITHMS__NEURAL_NETWORKS__LAYERS__BATCH_NORMALIZATION__METHOD"></a>
 * \brief Computation methods for the batch normalization layer
 */
enum Method
{
    defaultDense = 0    /*!< Default: performance-oriented method. */
};

/**
 * \brief Identifiers of input objects for the backward batch normalization layer
 *        and results for the forward batch normalization layer
 */
enum LayerDataId
{
    auxData,               /*!< p-dimensional tensor that stores forward batch normalization layer input data */
    auxWeights,            /*!< 1-dimensional tensor of size \f$n_k\f$ that stores input weights for forward batch normalization layer */
    auxMean,               /*!< 1-dimensional tensor of size \f$n_k\f$ that stores mini-batch mean */
    auxStandardDeviation,  /*!< 1-dimensional tensor of size \f$n_k\f$ that stores mini-batch standard deviation */
    auxPopulationMean,     /*!< 1-dimensional tensor of size \f$n_k\f$ that stores resulting population mean */
    auxPopulationVariance, /*!< 1-dimensional tensor of size \f$n_k\f$ that stores resulting population variance */
    lastLayerDataId = auxPopulationVariance
};

/**
 * \brief Contains version 1.0 of Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface1
{
/**
 * <a name="DAAL-STRUCT-ALGORITHMS__NEURAL_NETWORKS__LAYERS__BATCH_NORMALIZATION__PARAMETER"></a>
 * \brief Parameters for the forward and backward batch normalization layers
 *
 * \snippet neural_networks/layers/batch_normalization/batch_normalization_layer_types.h Parameter source code
 * \DAAL_DEPRECATED
 */
/* [Parameter source code] */
struct DAAL_EXPORT Parameter: public layers::Parameter
{
    /**
     * Constructs the parameters of the batch normalization layer
     * \param[in] alpha             Smoothing factor that is used in population mean and population variance computations
     * \param[in] epsilon           A constant added to the mini-batch variance for numerical stability
     * \param[in] dimension         Index of the dimension for which the normalization is performed
     * \DAAL_DEPRECATED
     */
    Parameter(double alpha = 0.01, double epsilon = 0.00001, size_t dimension = 1);

    double alpha;           /*!< Smoothing factor that is used in population mean and population variance computations */
    double epsilon;         /*!< A constant added to the mini-batch variance for numerical stability */
    size_t dimension;       /*!< Index of the dimension for which the normalization is performed */
};
/* [Parameter source code] */
} // interface1
using interface1::Parameter;

} // namespace batch_normalization
/** @} */
} // namespace layers
} // namespace neural_networks
} // namespace algorithm
} // namespace daal

#endif
