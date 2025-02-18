/* file: lrn_layer_backward.cpp */
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
//  Implementation of lrn calculation algorithm and types methods.
//--
*/

#include "lrn_layer_backward_types.h"
#include "lrn_layer_types.h"
#include "serialization_utils.h"
#include "daal_strings.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace lrn
{
namespace backward
{
namespace interface1
{
__DAAL_REGISTER_SERIALIZATION_CLASS(Result, SERIALIZATION_NEURAL_NETWORKS_LAYERS_LRN_BACKWARD_RESULT_ID);
/** Default constructor */
Input::Input() {};
Input::Input(const Input& other) : super(other) {}

/**
 * Returns an input object for the backward local response normalization layer
 * \param[in] id    Identifier of the input object
 * \return          %Input object that corresponds to the given identifier
 */
data_management::TensorPtr Input::get(LayerDataId id) const
{
    layers::LayerDataPtr layerData =
        services::staticPointerCast<layers::LayerData, data_management::SerializationIface>(Argument::get(layers::backward::inputFromForward));
    return services::staticPointerCast<data_management::Tensor, data_management::SerializationIface>((*layerData)[id]);
}

/**
 * Sets an input object for the backward local response normalization layer
 * \param[in] id      Identifier of the input object
 * \param[in] value   Pointer to the object
 */
void Input::set(LayerDataId id, const data_management::TensorPtr &value)
{
    layers::LayerDataPtr layerData =
        services::staticPointerCast<layers::LayerData, data_management::SerializationIface>(Argument::get(layers::backward::inputFromForward));
    (*layerData)[id] = value;
}

/**
 * Checks an input object for the backward local response normalization layer
 * \param[in] par     Algorithm parameter
 * \param[in] method  Computation method
 */
services::Status Input::check(const daal::algorithms::Parameter *par, int method) const
{
    const layers::Parameter *param = static_cast<const Parameter *>(par);
    if (!param->propagateGradient) { return services::Status(); }
    services::Status s;
    DAAL_CHECK_STATUS(s, layers::backward::Input::check(par, method));

    data_management::TensorPtr inputGradientTensor = get(layers::backward::inputGradient);
    DAAL_CHECK_STATUS(s, data_management::checkTensor(inputGradientTensor.get(), inputGradientStr()));

    const services::Collection<size_t> &dataDims = inputGradientTensor->getDimensions();
    DAAL_CHECK_STATUS(s, data_management::checkTensor(get(auxData).get(),   auxDataStr(), &dataDims));
    DAAL_CHECK_STATUS(s, data_management::checkTensor(get(auxSmBeta).get(), auxSmBetaStr(), &dataDims));
    return s;
}

    /** Default constructor */
Result::Result() : layers::backward::Result() {}

/**
 * Checks the result of the backward local response normalization layer
 * \param[in] input   %Input object for the layer
 * \param[in] par     %Parameter of the layer
 * \param[in] method  Computation method
 */
services::Status Result::check(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, int method) const
{
    const layers::Parameter *param = static_cast<const Parameter *>(par);
    return services::Status();
}

}// namespace interface1
}// namespace backward
}// namespace lrn
}// namespace layers
}// namespace neural_networks
}// namespace algorithms
}// namespace daal
