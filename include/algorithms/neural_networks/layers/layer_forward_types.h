/* file: layer_forward_types.h */
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

#ifndef __LAYERS__FORWARD__TYPES__H__
#define __LAYERS__FORWARD__TYPES__H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "services/daal_defines.h"
#include "services/collection.h"
#include "data_management/data/data_collection.h"
#include "algorithms/neural_networks/layers/layer_types.h"

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
 * \brief Contains classes for neural network layers
 */
namespace layers
{
/**
 * @defgroup layers_forward Forward Base Layer
 * \copydoc daal::algorithms::neural_networks::layers::forward
 * @ingroup layers
 * @{
 */
/**
 * \brief Contains classes for the forward stage of the neural network layer
 */
namespace forward
{
/**
 * <a name="DAAL-ENUM-ALGORITHMS__NEURAL_NETWORKS__LAYERS__FORWARD__INPUTID"></a>
 * Available identifiers of input objects for the layer algorithm
 */
enum InputId
{
    data,       /*!< Input data */
    weights,    /* Weights of the neural network layer */
    biases,       /* Biases of the neural network layer */
    lastInputId = biases
};

/**
 * <a name="DAAL-ENUM-ALGORITHMS__NEURAL_NETWORKS__LAYERS__FORWARD__INPUTLAYERDATAID"></a>
 * Available identifiers of input objects for the layer algorithm
 */
enum InputLayerDataId
{
    inputLayerData = lastInputId + 1,
    lastInputLayerDataId = inputLayerData
};

/**
 * <a name="DAAL-ENUM-ALGORITHMS__NEURAL_NETWORKS__LAYERS__FORWARD__RESULTID"></a>
 * Available identifiers of results for the layer algorithm
 */
enum ResultId
{
    value,      /*!< Table to store the result */
    lastResultId = value
};

/**
 * <a name="DAAL-ENUM-ALGORITHMS__NEURAL_NETWORKS__LAYERS__FORWARD__RESULTLAYERDATAID"></a>
 * Available identifiers of results for the layer algorithm
 */
enum ResultLayerDataId
{
    resultForBackward = lastResultId + 1,  /*!< Data for backward step */
    lastResultLayerDataId = resultForBackward
};

/**
 * \brief Contains version 1.0 of Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface1
{
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__FORWARD__INPUTIFACE"></a>
 * \brief Abstract class that specifies interface of the input objects for the neural network layer
 * \DAAL_DEPRECATED
 */
class DAAL_EXPORT InputIface : public daal::algorithms::Input
{
public:
    /** \brief Constructor
     * \param[in] nElements    Number of elements in Input structure
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED InputIface(size_t nElements) : daal::algorithms::Input(nElements) {}
    /*
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED InputIface(const InputIface& other);
    /*
     * \DAAL_DEPRECATED
     */
    virtual ~InputIface() {}
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__FORWARD__INPUT"></a>
 * \brief %Input objects for layer algorithm
 * \DAAL_DEPRECATED
 */
class DAAL_EXPORT Input : public InputIface
{
public:
    /**
     * Constructs input objects for the forward layer of neural network
     * \param[in] nElements     Number of input objects for the forward layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Input(size_t nElements = lastInputLayerDataId + 1);
    /*
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Input(const Input& other);

    /*
     * \DAAL_DEPRECATED
     */
    virtual ~Input() {}

    /**
     * Returns input Tensor of the layer algorithm
     * \param[in] id    Identifier of the input tensor
     * \return          %Input tensor that corresponds to the given identifier
     * \DAAL_DEPRECATED
     */
    data_management::TensorPtr get(forward::InputId id) const;

    /**
     * Sets input for the layer algorithm
     * \param[in] id    Identifier of the input object
     * \param[in] ptr   Pointer to the object
     * \DAAL_DEPRECATED
     */
    void set(InputId id, const data_management::TensorPtr &ptr);

    /**
    * Returns input InputLayerData of the layer algorithm
    * \param[in] id    Identifier of the input object
    * \return          %Input InputLayerData that corresponds to the given identifier
    * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED LayerDataPtr get(forward::InputLayerDataId id) const;

    /**
     * Sets input for the layer algorithm
     * \param[in] id    Identifier of the input object
     * \param[in] ptr   Pointer to the object
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED void set(InputLayerDataId id, const LayerDataPtr &ptr);

    /**
     * Checks an input object for the layer algorithm
     * \param[in] par     %Parameter of algorithm
     * \param[in] method  Computation method of the algorithm
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    services::Status check(const daal::algorithms::Parameter *par, int method) const DAAL_C11_OVERRIDE;

    /**
     * Returns the layout of the input object for the layer algorithm
     * \return Layout of the input object for the layer algorithm
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual LayerInputLayout getLayout();

    /**
     * Returns dimensions of weights tensor
     * \return Dimensions of weights tensor
     * \DAAL_DEPRECATED
     */
    virtual const services::Collection<size_t> getWeightsSizes(const layers::Parameter *parameter) const;

    /**
     * Returns dimensions of biases tensor
     * \return Dimensions of biases tensor
     * \DAAL_DEPRECATED
     */
    virtual const services::Collection<size_t> getBiasesSizes(const layers::Parameter *parameter) const;

    /**
     * Adds tensor with data to the input object of the layer algorithm
     * \param[in] dataTensor    Tensor with data
     * \param[in] index         Index of the tensor with data
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status addData(const data_management::TensorPtr &dataTensor, size_t index);

    /**
     * Erases input data tensor from the input of the forward layer
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status eraseInputData()
    {
        set(layers::forward::data, data_management::TensorPtr());
        return services::Status();
    }
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__FORWARD__RESULT"></a>
 * \brief Provides methods to access the result obtained with the compute() method of the layer algorithm
 * \DAAL_DEPRECATED
 */
class DAAL_EXPORT Result : public daal::algorithms::Result
{
    DECLARE_SERIALIZABLE_IMPL();
public:
    DAAL_CAST_OPERATOR(Result);
    /**
     * \brief Constructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Result();

    /*
     * \DAAL_DEPRECATED
     */
    virtual ~Result() {};

    /**
     * Allocates memory to store the results of layer
     * \param[in] input  Pointer to the input structure
     * \param[in] par    Pointer to the parameter structure
     * \param[in] method Computation method of the algorithm
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    template <typename algorithmFPType>
    services::Status allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, const int method)
    {
        return services::Status();
    }

    /**
    * Returns collection of dimensions of layer output
    * \param[in] inputSize   Collection of input tensor dimensions
    * \param[in] par         Parameters of the algorithm
    * \param[in] method      Method of the algorithm
    * \return    Collection of dimensions of layer output
    * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED_VIRTUAL virtual const services::Collection<size_t> getValueSize(const services::Collection<size_t> &inputSize,
                                                            const daal::algorithms::Parameter *par, const int method) const = 0;

    /**
    * Returns collection of dimensions of layer output
    * \param[in] inputSize Collection of input tensors dimensions
    * \param[in] par       Parameters of the algorithm
    * \param[in] method    Method of the algorithm
    * \return    Collection of dimensions of layer output
    * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED_VIRTUAL virtual services::Collection<size_t> getValueSize(const services::Collection< services::Collection<size_t> > &inputSize,
                                                      const daal::algorithms::Parameter *par, const int method);

    /**
    * Returns collection of dimensions of layer output
    * \param[in] inputSize   Collection of input tensor dimensions
    * \param[in] par         Parameters of the algorithm
    * \param[in] method      Method of the algorithm
    * \return    Collection of dimensions of layer output
    * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED_VIRTUAL virtual services::Collection< services::Collection<size_t> > getValueCollectionSize(const services::Collection<size_t> &inputSize,
                                                                                        const daal::algorithms::Parameter *par, const int method);

    /**
     * Returns result of the layer algorithm
     * \param[in] id   Identifier of the result
     * \return         Result that corresponds to the given identifier
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED data_management::TensorPtr get(ResultId id) const;

    /**
     * Returns result of the layer algorithm
     * \param[in] id   Identifier of the result
     * \return         Result that corresponds to the given identifier
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED LayerDataPtr get(ResultLayerDataId id) const;

    /**
     * Sets the result of the layer algorithm
     * \param[in] id    Identifier of the result
     * \param[in] ptr   Pointer to the result
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED void set(ResultId id, const data_management::TensorPtr &ptr);

    /**
    * Sets the result of the layer algorithm
    * \param[in] id    Identifier of the result
    * \param[in] ptr   Pointer to the result
    * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED void set(ResultLayerDataId id, const LayerDataPtr &ptr);

    /**
     * \copydoc daal::data_management::interface1::SerializationIface::getSerializationTag()
     * \DAAL_DEPRECATED
     */
    int getSerializationTag() const DAAL_C11_OVERRIDE  { return SERIALIZATION_NEURAL_NETWORKS_LAYERS_FORWARD_RESULT_ID; }

    /**
     * Checks the result object for the layer algorithm
     * \param[in] input         %Input of the algorithm
     * \param[in] parameter     %Parameter of algorithm
     * \param[in] method        Computation method of the algorithm
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status check(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter,
                                   int method) const DAAL_C11_OVERRIDE;

    /**
     * Returns the layout of the result object for the layer algorithm
     * \return Layout of the result object for the layer algorithm
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual LayerResultLayout getLayout();

    /**
     * Sets the result that is used in backward layer
     * \param[in] input     Pointer to an object containing the input data
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status setResultForBackward(const daal::algorithms::Input *input)
    {
        return services::Status();
    }

    /**
     * Returns resulting value of the layer algorithm
     * \param[in] index Index of the tensor with value
     * \return Resulting value that corresponds to the given index
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual data_management::TensorPtr getValue(size_t index) const;

protected:
    /**
     * \private
     * \DAAL_DEPRECATED
     */
    template<typename Archive, bool onDeserialize>
    services::Status serialImpl(Archive *arch)
    {
        return daal::algorithms::Result::serialImpl<Archive, onDeserialize>(arch);
    }
};
typedef services::SharedPtr<Result> ResultPtr;
} // interface1
using interface1::InputIface;
using interface1::Input;
using interface1::Result;
using interface1::ResultPtr;
} // forward
/** @} */
} // namespace layer
} // namespace neural_networks
} // namespace algorithm
} // namespace daal
#endif
