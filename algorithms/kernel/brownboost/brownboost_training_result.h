/* file: brownboost_training_result.h */
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
//  Implementation of the interface for BrownBoost model-based training
//--
*/

#ifndef __BROWNBOOST_TRAINING_RESULT_
#define __BROWNBOOST_TRAINING_RESULT_

#include "algorithms/boosting/brownboost_training_types.h"

namespace daal
{
namespace algorithms
{
namespace brownboost
{
namespace training
{

namespace interface1
{
/**
 * Allocates memory to store final results of BrownBoost training
 * \param[in] input        %Input of the BrownBoost training algorithm
 * \param[in] parameter     Parameters of the algorithm
 * \param[in] method        BrownBoost computation method
 */
template <typename algorithmFPType>
DAAL_EXPORT services::Status Result::allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method)
{
    services::Status s;
    const classifier::training::interface1::Input *algInput = static_cast<const classifier::training::interface1::Input *>(input);
    set(classifier::training::model, brownboost::interface1::Model::create<algorithmFPType>(algInput->getNumberOfFeatures(), &s));
    return s;
}
}

namespace interface2
{
/**
 * Allocates memory to store final results of BrownBoost training
 * \param[in] input        %Input of the BrownBoost training algorithm
 * \param[in] parameter     Parameters of the algorithm
 * \param[in] method        BrownBoost computation method
 */
template <typename algorithmFPType>
DAAL_EXPORT services::Status Result::allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method)
{
    services::Status s;
    const classifier::training::Input *algInput = static_cast<const classifier::training::Input *>(input);
    set(classifier::training::model, Model::create<algorithmFPType>(algInput->getNumberOfFeatures(), &s));
    return s;
}
}

} // namespace training
} // namespace brownboost
} // namespace algorithms
} // namespace daal

#endif
