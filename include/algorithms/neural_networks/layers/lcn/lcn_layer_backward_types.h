/* file: lcn_layer_backward_types.h */
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
//  Implementation of backward local contrast normalization layer.
//--
*/

#ifndef __LCN_LAYER_BACKWARD_TYPES_H__
#define __LCN_LAYER_BACKWARD_TYPES_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "data_management/data/homogen_tensor.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/layer_backward_types.h"
#include "algorithms/neural_networks/layers/lcn/lcn_layer_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace lcn
{
/**
 * @defgroup lcn_layers_backward Backward Local contrast normalization (LCN) Layer
 * \copydoc daal::algorithms::neural_networks::layers::lcn::backward
 * @ingroup lcn_layers
 * @{
 */
/**
 * \brief Contains classes for the backward local contrast normalization layer
 */
namespace backward
{
/**
 * \brief Contains version 1.0 of Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface1
{

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LCN__BACKWARD__INPUT"></a>
 * \brief %Input objects for the backward local contrast normalization layer
 * \DAAL_DEPRECATED
 */
class DAAL_EXPORT Input : public layers::backward::Input
{
public:
    typedef layers::backward::Input super;
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

    /*
     * \DAAL_DEPRECATED
     */
    virtual ~Input() {}

    /**
     * Sets an input object for the backward local contrast normalization layer
     */
    using layers::backward::Input::get;

    /**
     * Returns an input object for the backward local contrast normalization layer
    */
    using layers::backward::Input::set;

    /**
     * Returns an input object for backward local contrast normalization layer
     * \param[in] id    Identifier of the input object
     * \return          %Input object that corresponds to the given identifier
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED data_management::TensorPtr get(LayerDataId id) const;

    /**
     * Sets input for the backward local contrast normalization layer
     * \param[in] id    Identifier of the input  object
     * \param[in] value Input object to set
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED void set(LayerDataId id, const data_management::TensorPtr &value);

    /**
     * Checks an input object of the local contrast normalization layer
     * \param[in] parameter %Parameter of layer
     * \param[in] method    Computation method of the layer
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status check(const daal::algorithms::Parameter *parameter, int method) const DAAL_C11_OVERRIDE;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LCN__BACKWARD__RESULT"></a>
 * \brief Results obtained with the compute() method of the backward local contrast normalization layer
 * \DAAL_DEPRECATED
 */
class DAAL_EXPORT Result : public layers::backward::Result
{
public:
    DECLARE_SERIALIZABLE_CAST(Result);
    /**
     * Default constructor
     * \DAAL_DEPRECATED
     */
    Result();

    /*
     * \DAAL_DEPRECATED
     */
    virtual ~Result() {}

    /**
     * Returns the result of the backward local contrast normalization layer
     * \DAAL_DEPRECATED
     */
    using layers::backward::Result::get;

    /**
     * Sets the result of the backward local contrast normalization layer
     * \DAAL_DEPRECATED
     */
    using layers::backward::Result::set;

    /**
     * Allocates memory to store the result of backward local contrast normalization layer
     * \param[in] input     Object containing the input data
     * \param[in] parameter %Parameter of backward local contrast normalization layer
     * \param[in] method    Computation method
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    template <typename algorithmFPType>
    DAAL_EXPORT services::Status allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method);

    /**
     * Checks the result of the local contrast normalization layer
     * \param[in] input   %Input object of the layer
     * \param[in] par     %Parameter of the layer
     * \param[in] method  Computation method of the layer
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status check(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, int method) const DAAL_C11_OVERRIDE;

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
} // namespace backward
/** @} */
} // namespace lcn
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal
#endif
