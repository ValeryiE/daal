/* file: layer_types.h */
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
//  Implementation of neural_networks Network layer.
//--
*/

#ifndef __LAYERS_TYPES_H__
#define __LAYERS_TYPES_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "services/daal_defines.h"
#include "services/collection.h"
#include "data_management/data/data_collection.h"
#include "algorithms/neural_networks/initializers/initializer.h"
#include "algorithms/neural_networks/initializers/uniform/uniform_initializer.h"

namespace daal
{
namespace algorithms
{
/**
 * \brief Contains classes for training and prediction using neural network
 */
namespace neural_networks
{
/**
 * @defgroup layers Layers
 * \copydoc daal::algorithms::neural_networks::layers
 * @ingroup neural_networks
 * @{
 */
/**
 * \brief Contains classes for neural network layers
 */
namespace layers
{
/**
 * <a name="DAAL-ENUM-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LAYERINPUTLAYOUT"></a>
 * Available identifiers of layouts of the input of the layer
 */
enum LayerInputLayout
{
    tensorInput,
    collectionInput,
    lastLayerInputLayout = collectionInput
};

/**
 * <a name="DAAL-ENUM-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LAYERRESULTLAYOUT"></a>
 * Available identifiers of layouts of the result of the layer
 */
enum LayerResultLayout
{
    tensorResult,
    collectionResult,
    lastLayerResultLayout = collectionResult
};
/**
 * \brief Contains version 1.0 of Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface1
{

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__PARAMETER"></a>
 * Parameters of the neural network layer
 * \DAAL_DEPRECATED
 */
class DAAL_EXPORT Parameter: public daal::algorithms::Parameter
{
public:
    /**
     * Default constructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Parameter();

    /** Layer weights initializer */
    initializers::InitializerIfacePtr weightsInitializer;
    /** Layer biases initializer */
    initializers::InitializerIfacePtr biasesInitializer;
    /** Flag specifying whether the layer is used for the prediction stage or not */
    bool predictionStage;
    /** Flag specifying whether backward layer propagates the gradient */
    bool propagateGradient;
    /** Weights and biases initialization status. True if weights and biases are initialized, false otherwise. */
    bool weightsAndBiasesInitialized;
    /** Flag specifying whether the layer can use inplace computations */
    bool allowInplaceComputation;
};

/**
 * \brief Contains extra input and output object of neural network layer
 */
typedef data_management::KeyValueDataCollection LayerData;
typedef services::SharedPtr<LayerData> LayerDataPtr;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__NEXTLAYERS"></a>
 * \brief Contains list of layer indices of layers following the current layer
 */
class NextLayers
{
public:
    /**
     * \brief Constructs empty list of layer indices of layers following the current layer
     * \DAAL_DEPRECATED
     */
    NextLayers() : _indices(0)
    {}

    /**
     * \brief Constructs the list of layer indices by copying the indices from another list of layer indices
     * \param[in] other List of layer indices to use as the source to initialize
     *                  the list of layer indices of layers following the current layer
     * \DAAL_DEPRECATED
     */
     NextLayers(const NextLayers &other) : _indices(other._indices)
    {}

    /**
     * \brief Constructs the list of layer indices from one index of the next layer
     * \param[in] index1    First index of the next layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED NextLayers(const size_t index1) : _indices()
    {
        _indices.push_back(index1);
    }

    /**
     * \brief Constructs the list of layer indices from two indices of the next layers
     * \param[in] index1    First index of the next layer
     * \param[in] index2    Second index of the next layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED NextLayers(const size_t index1, const size_t index2) : _indices()
    {
        _indices.push_back(index1);
        _indices.push_back(index2);
    }

    /**
     * \brief Constructs the list of layer indices from three indices of the next layers
     * \param[in] index1    First index of the next layer
     * \param[in] index2    Second index of the next layer
     * \param[in] index3    Third index of the next layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED NextLayers(const size_t index1, const size_t index2, const size_t index3) : _indices()
    {
        _indices.push_back(index1);
        _indices.push_back(index2);
        _indices.push_back(index3);
    }

    /**
     * \brief Constructs the list of layer indices from four indices of the next layers
     * \param[in] index1    First index of the next layer
     * \param[in] index2    Second index of the next layer
     * \param[in] index3    Third index of the next layer
     * \param[in] index4    Fourth index of the next layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED NextLayers(const size_t index1, const size_t index2, const size_t index3, const size_t index4) : _indices()
    {
        _indices.push_back(index1);
        _indices.push_back(index2);
        _indices.push_back(index3);
        _indices.push_back(index4);
    }

    /**
     * \brief Constructs the list of layer indices from five indices of the next layers
     * \param[in] index1    First index of the next layer
     * \param[in] index2    Second index of the next layer
     * \param[in] index3    Third index of the next layer
     * \param[in] index4    Fourth index of the next layer
     * \param[in] index5    Fifth index of the next layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED NextLayers(const size_t index1, const size_t index2, const size_t index3, const size_t index4,
               const size_t index5) : _indices()
    {
        _indices.push_back(index1);
        _indices.push_back(index2);
        _indices.push_back(index3);
        _indices.push_back(index4);
        _indices.push_back(index5);
    }

    /**
     * \brief Constructs the list of layer indices from six indices of the next layers
     * \param[in] index1    First index of the next layer
     * \param[in] index2    Second index of the next layer
     * \param[in] index3    Third index of the next layer
     * \param[in] index4    Fourth index of the next layer
     * \param[in] index5    Fifth index of the next layer
     * \param[in] index6    Sixth index of the next layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED NextLayers(const size_t index1, const size_t index2, const size_t index3, const size_t index4, const size_t index5,
               const size_t index6) : _indices()
    {
        _indices.push_back(index1);
        _indices.push_back(index2);
        _indices.push_back(index3);
        _indices.push_back(index4);
        _indices.push_back(index5);
        _indices.push_back(index6);
    }

    /*
     * \DAAL_DEPRECATED
     */
    virtual ~NextLayers()
    {}

    /**
     * Size of the list of indices
     * \return Size of the list of indices
     * \DAAL_DEPRECATED
     */
    size_t size() const { return _indices.size(); }

    /**
     * Element access
     * \param[in] index Index of an accessed element
     * \return    Reference to the element
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED size_t & operator [] (size_t index)
    {
        return _indices[index];
    }

    /**
     * Const element access
     * \param[in] index Index of the element to return
     * \return    Const reference to the element
     * \DAAL_DEPRECATED
     */
    const size_t & operator [] (size_t index) const
    {
        return _indices[index];
    }

    /**
    *  Adds an element to the end of the collection
    *  \param[in] index Element to add
    *  \DAAL_DEPRECATED
    */
    void push_back(size_t index) { _indices.push_back(index); }

    /**
    *  Adds an element to the end of the collection
    *  \param[in] index Element to add
    *  \DAAL_DEPRECATED
    */
    void add(size_t index) { _indices.push_back(index); }

protected:
    services::Collection<size_t> _indices;
};

}
using interface1::LayerData;
using interface1::LayerDataPtr;
using interface1::NextLayers;
using interface1::Parameter;

} // namespace layers
/** @} */
} // namespace neural_networks
} // namespace algorithm
} // namespace daal
#endif
