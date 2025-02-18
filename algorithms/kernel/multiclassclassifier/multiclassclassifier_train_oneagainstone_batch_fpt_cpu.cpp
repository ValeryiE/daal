/* file: multiclassclassifier_train_oneagainstone_batch_fpt_cpu.cpp */
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
//  Implementation of One-Against-One method for Multi-class classifier
//  training algorithm.
//--
*/

#include "multiclassclassifier_train_batch_container.h"
#include "multiclassclassifier_train_kernel.h"
#include "multiclassclassifier_train_oneagainstone_kernel.h"
#include "multiclassclassifier_train_oneagainstone_impl.i"

namespace daal
{
namespace algorithms
{
namespace multi_class_classifier
{
namespace training
{
namespace interface1
{
template class BatchContainer<DAAL_FPTYPE, oneAgainstOne,    DAAL_CPU>;
}
namespace interface2
{
template class BatchContainer<DAAL_FPTYPE, oneAgainstOne,    DAAL_CPU>;
}
namespace internal
{

template class MultiClassClassifierTrainKernel<oneAgainstOne,    DAAL_FPTYPE, classifier::training::interface1::Batch, multi_class_classifier::interface1::Parameter, DAAL_CPU>;
template class MultiClassClassifierTrainKernel<oneAgainstOne,    DAAL_FPTYPE, classifier::training::Batch, multi_class_classifier::Parameter, DAAL_CPU>;

} // namespace internal

} // namespace training

} // namespace multi_class_classifier

} // namespace algorithms

} // namespace daal
