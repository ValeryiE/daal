/* file: tanh_base.h */
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

//++
//  Declaration of template function that calculate hyperbolic tangent.
//--


#ifndef __TANH_BASE_H__
#define __TANH_BASE_H__

#include "math/tanh.h"
#include "kernel.h"
#include "numeric_table.h"
#include "service_numeric_table.h"
#include "service_error_handling.h"
#include "service_math.h"
#include "threading.h"

using namespace daal::data_management;
using namespace daal::services;
using namespace daal::internal;

namespace daal
{
namespace algorithms
{
namespace math
{
namespace tanh
{
namespace internal
{
/**
 *  \brief Kernel for tanh calculation
 *  in case floating point type of intermediate calculations
 *  and method of calculations are different
 */
template<typename algorithmFPType, Method method, CpuType cpu>
class TanhKernelBase : public Kernel
{
public:
    Status compute(const NumericTable *inputTable, NumericTable *resultTable);

protected:
    static const size_t _nRowsInBlock = 5000;

    virtual Status processBlock(const NumericTable &inputTable, size_t nInputColumns, size_t nProcessedRows, size_t nRowsInCurrentBlock,
                                NumericTable &resultTable) = 0;
};

template<typename algorithmFPType, Method method, CpuType cpu>
class TanhKernel {};

} // namespace daal::internal
} // namespace tanh
} // namespace math
} // namespace algorithms
} // namespace daal

#endif
