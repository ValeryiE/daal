/* file: abs_layer_backward.h */
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
//  Implementation of the interface for the backward absolute value (abs) layer
//  in the batch processing mode
//--
*/

#ifndef __ABS_LAYER_BACKWARD_H__
#define __ABS_LAYER_BACKWARD_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/layer.h"
#include "algorithms/neural_networks/layers/abs/abs_layer_types.h"
#include "algorithms/neural_networks/layers/abs/abs_layer_backward_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace abs
{
namespace backward
{
namespace interface1
{
/**
 * @defgroup abs_layers_backward_batch Batch
 * @ingroup abs_layers_backward
 * @{
 */
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__ABS__BACKWARD__BATCHCONTAINER"></a>
* \brief Provides methods to run implementations of the of the backward abs layer
*        This class is associated with the daal::algorithms::neural_networks::layers::abs::backward::Batch class
*        and supports the method of backward abs layer computation in the batch processing mode
*
* \tparam algorithmFPType  Data type to use in intermediate computations of backward abs layer, double or float
* \tparam method           Computation method of the layer, \ref daal::algorithms::neural_networks::layers::abs::Method
* \tparam cpu              Version of the cpu-specific implementation of the layer, \ref daal::CpuType
*
* \DAAL_DEPRECATED
*/
template<typename algorithmFPType, Method method, CpuType cpu>
class BatchContainer : public AnalysisContainerIface<batch>
{
public:
    /**
    * Constructs a container for the backward abs layer with a specified environment
    * \param[in] daalEnv   Environment object
    * \DAAL_DEPRECATED
    */
    BatchContainer(daal::services::Environment::env *daalEnv);
    /**
     * Default destructor
     * \DAAL_DEPRECATED
     */
    ~BatchContainer();
    /**
     * Computes the result of the backward abs layer in the batch processing mode
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    services::Status compute() DAAL_C11_OVERRIDE;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__ABS__BACKWARD__BATCH"></a>
 * \brief Computes the results of the backward abs layer in the batch processing mode
 * <!-- \n<a href="DAAL-REF-ABSBACKWARD-ALGORITHM">Backward abs layer description and usage models</a> -->
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations of the backward abs layer, double or float
 * \tparam method           Backward abs layer method, \ref Method
 *
 * \par Enumerations
 *      - \ref Method            Computation methods for the backward abs layer
 *      - \ref backward::InputId           Identifiers of input objects for the backward abs layer
 *      - \ref LayerDataId                 Identifiers of extra results computed by the forward abs layer
 *      - \ref backward::ResultId          Identifiers of result objects for the backward abs layer
 *
 * \par References
 *      - \ref forward::interface1::Batch "forward::Batch" class
 *
 * \DAAL_DEPRECATED
 */
template<typename algorithmFPType = DAAL_ALGORITHM_FP_TYPE, Method method = defaultDense>
class Batch : public layers::backward::LayerIfaceImpl
{
public:
    typedef layers::backward::LayerIfaceImpl super;

    typedef algorithms::neural_networks::layers::abs::backward::Input     InputType;
    typedef algorithms::neural_networks::layers::abs::Parameter           ParameterType;
    typedef algorithms::neural_networks::layers::abs::backward::Result    ResultType;

    ParameterType &parameter; /*!< Abs layer \ref interface1::Parameter "parameters" structure */
    InputType input;         /*!< %Input objects of the layer */

    /**
     * Default constructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Batch() : parameter(_defaultParameter)
    {
        initialize();
    }

    /**
     * Constructs a backward abs layer in the batch processing mode
     * and initializes its parameter with the provided parameter
     * \param[in] parameter Parameter to initialize the parameter of the layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Batch(ParameterType& parameter) : parameter(parameter), _defaultParameter(parameter)
    {
        initialize();
    }

    /**
     * Constructs backward abs layer by copying input objects
     * and parameters of another backward abs layer in the batch processing mode
     * \param[in] other Algorithm to use as the source to initialize the input objects
     *                  and parameters of the algorithm
     * \DAAL_DEPRECATED
     */
    Batch(const Batch<algorithmFPType, method> &other) : super(other),
        _defaultParameter(other.parameter), parameter(_defaultParameter), input(other.input)
    {
        initialize();
    }

    /**
    * Returns the method of the algorithm
    * \return Method of the algorithm
    * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED_VIRTUAL virtual int getMethod() const DAAL_C11_OVERRIDE { return(int) method; }

    /**
     * Returns the structure that contains input objects of the abs backward layer
     * \return Structure that contains input objects of the abs backward layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual InputType *getLayerInput() DAAL_C11_OVERRIDE { return &input; }

    /**
     * Returns the structure that contains prameters of the backward abs layer
     * \return Structure that contains parameters of the backward abs layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual ParameterType *getLayerParameter() DAAL_C11_OVERRIDE { return &parameter; };

    /**
     * Returns the structure that contains result of the backward abs layer
     * \return Structure that contains result of the backward abs layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED layers::backward::ResultPtr getLayerResult() DAAL_C11_OVERRIDE
    {
        return _result;
    }

    /**
     * Returns the structure that contains result of the backward abs layer
     * \return Structure that contains result of the backward abs layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED ResultPtr getResult()
    {
        return _result;
    }

    /**
     * Registers user-allocated memory to store results of the backward abs layer
     * \param[in] result  Structure to store result of the backward abs layer
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status setResult(const ResultPtr& result)
    {
        DAAL_CHECK(result, services::ErrorNullResult)
        _result = result;
        _res = _result.get();
        return services::Status();
    }

    /**
     * Returns a pointer to the newly allocated the backward abs layer
     * with a copy of input objects and parameters of this backward abs layer
     * in the batch processing mode
     * \return Pointer to the newly allocated layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::SharedPtr<Batch<algorithmFPType, method> > clone() const
    {
        return services::SharedPtr<Batch<algorithmFPType, method> >(cloneImpl());
    }

    /**
    * Allocates memory to store the result of the backward abs layer
    *
     * \return Status of computations
     * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status allocateResult() DAAL_C11_OVERRIDE
    {
        services::Status s = this->_result->template allocate<algorithmFPType>(&(this->input), &parameter, (int) method);
        this->_res = this->_result.get();
        return s;
    }

protected:
    /*
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual Batch<algorithmFPType, method> *cloneImpl() const DAAL_C11_OVERRIDE
    {
        return new Batch<algorithmFPType, method>(*this);
    }

    /*
     * \DAAL_DEPRECATED
     */
    void initialize()
    {
        Analysis<batch>::_ac = new __DAAL_ALGORITHM_CONTAINER(batch, BatchContainer, algorithmFPType, method)(&_env);
        _in = &input;
        _par = &parameter;
        _result.reset(new ResultType());
    }

private:
    ResultPtr _result;
    ParameterType _defaultParameter;
};
/** @} */
} // namespace interface1
using interface1::BatchContainer;
using interface1::Batch;
} // namespace backward
} // namespace abs
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal
#endif
