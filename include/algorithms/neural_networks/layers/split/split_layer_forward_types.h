/* file: split_layer_forward_types.h */
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
//  Implementation of the forward split layer
//--
*/

#ifndef __SPLIT_LAYER_FORWARD_TYPES_H__
#define __SPLIT_LAYER_FORWARD_TYPES_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "data_management/data/homogen_tensor.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/layer_forward_types.h"
#include "algorithms/neural_networks/layers/split/split_layer_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
/**
 * \brief Contains classes for the split layer
 */
namespace split
{
/**
 * @defgroup split_forward Forward Split Layer
 * \copydoc daal::algorithms::neural_networks::layers::split::forward
 * @ingroup split
 * @{
 */
/**
 * \brief Contains classes for the forward split layer
 */
namespace forward
{
/**
 * <a name="DAAL-ENUM-ALGORITHMS__NEURAL_NETWORKS__LAYERS__SPLIT__FORWARD__RESULTLAYERDATAID"></a>
 * Available identifiers of results for the forward split layer
 */
enum ResultLayerDataId
{
    valueCollection = 1     /*!< Data for backward step */
};

/**
 * \brief Contains version 1.0 of Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface1
{
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__SPLIT__FORWARD__INPUT"></a>
 * \brief %Input objects for the forward split layer
 * \DAAL_DEPRECATED
 */
class DAAL_EXPORT Input : public layers::forward::Input
{
public:
    typedef layers::forward::Input super;
    /**
     * \brief Default constructor
     * \DAAL_DEPRECATED
     */
    Input();

    /**
     * Copy constructor
     * \DAAL_DEPRECATED
     */
    Input(const Input& other);

    /**
    * Gets the input of the forward split layer
    */
    using layers::forward::Input::get;

    /**
    * Sets the input of the forward split layer
    */
    using layers::forward::Input::set;

    /*
     * \DAAL_DEPRECATED
     */
    virtual ~Input() {}
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__SPLIT__FORWARD__RESULT"></a>
 * \brief Provides methods to access the result obtained with the compute() method of the forward split layer
 * \DAAL_DEPRECATED
 */
class DAAL_EXPORT Result : public layers::forward::Result
{
public:
    DECLARE_SERIALIZABLE_CAST(Result);
    /**
     * \brief Default constructor
     * \DAAL_DEPRECATED
     */
    Result();
    /*
     * \DAAL_DEPRECATED
     */
    virtual ~Result() {};

    /**
     * Returns the result of the forward split layer
     */
    using layers::forward::Result::get;

    /**
    * Sets the result of the forward split layer
    */
    using layers::forward::Result::set;

    /**
     * Returns a tensor with a given index from the result
     * \param[in] id    Identifier of the collection of input tensors
     * \param[in] index Index of the tensor to be returned
     * \return          Pointer to the table with the input tensor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED data_management::TensorPtr get(ResultLayerDataId id, size_t index) const;

    /**
     * Returns result of the layer algorithm
     * \param[in] id   Identifier of the result
     * \return         Result that corresponds to the given identifier
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED LayerDataPtr get(ResultLayerDataId id) const;

    /**
     * Sets the result of the forward split layer
     * \param[in] id      Identifier of the result
     * \param[in] value   Result
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED void set(ResultLayerDataId id, const LayerDataPtr &value);

    /**
     * Sets the result of the forward split layer
     * \param[in] id      Identifier of the result
     * \param[in] value   Result
     * \param[in] index   Index of the result
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED void set(ResultLayerDataId id, const data_management::TensorPtr &value, size_t index);

    /**
     * Returns the layout of the result object for the layer algorithm
     * \return Layout of the result object for the layer algorithm
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED LayerResultLayout getLayout() DAAL_C11_OVERRIDE;

    /**
     * Returns resulting value of the forward split layer
     * \param[in] index Index of the tensor with value
     * \return Resulting value that corresponds to the given index
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual data_management::TensorPtr getValue(size_t index) const DAAL_C11_OVERRIDE;

    /**
     * Checks the result of the forward split layer
     * \param[in] input   %Input object for the algorithm
     * \param[in] par     %Parameter of the algorithm
     * \param[in] method  Computation method
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status check(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, int method) const DAAL_C11_OVERRIDE;

    /**
    * Returns collection of dimensions of split layer output
    * \param[in] inputSize   Collection of input tensor dimensions
    * \param[in] par         Parameters of the algorithm
    * \param[in] method      Method of the algorithm
    * \return    Collection of dimensions of split layer output
     * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED_VIRTUAL virtual const services::Collection<size_t> getValueSize(const services::Collection<size_t> &inputSize,
                                                            const daal::algorithms::Parameter *par, const int method) const DAAL_C11_OVERRIDE;

    /**
    * Returns collection of dimensions of split layer output
    * \param[in] inputSize   Collection of input tensor dimensions
    * \param[in] parameter   Parameters of the algorithm
    * \param[in] method      Method of the algorithm
    * \return    Collection of dimensions of split layer output
     * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED services::Collection< services::Collection<size_t> > getValueCollectionSize(const services::Collection<size_t> &inputSize,
                                                                                const daal::algorithms::Parameter *parameter, const int method) DAAL_C11_OVERRIDE;

    /**
    * Allocates memory to store the result of the forward split layer
    * \param[in] input        Pointer to an object containing the input data
    * \param[in] parameter    %Parameter of the algorithm
    * \param[in] method       Computation method for the algorithm
    *
    * \return Status of computations
     * \DAAL_DEPRECATED
    */
    template <typename algorithmFPType>
    DAAL_EXPORT services::Status allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method);

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
} // namespace interface1
using interface1::Input;
using interface1::Result;
using interface1::ResultPtr;
} // namespace forward
/** @} */
} // namespace split
} // namespace layers
} // namespace neural_networks
} // namespace algorithm
} // namespace daal
#endif
