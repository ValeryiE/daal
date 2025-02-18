/* file: logistic_layer_forward.h */
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
//  Implementation of the interface for the forward logistic layer in the batch processing mode
//--
*/

#ifndef __LOGISTIC_LAYER_FORWARD_H__
#define __LOGISTIC_LAYER_FORWARD_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/layer.h"
#include "algorithms/neural_networks/layers/logistic/logistic_layer_types.h"
#include "algorithms/neural_networks/layers/logistic/logistic_layer_forward_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
/**
 * \brief Contains classes for the logistic layer
 */
namespace logistic
{
/**
 * \brief Contains classes for the forward logistic layer
 */
namespace forward
{
namespace interface1
{
/**
 * @defgroup logistic_layers_forward_batch Batch
 * @ingroup logistic_layers_forward
 * @{
 */
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LOGISTIC__FORWARD__BATCHCONTAINER"></a>
* \brief Provides methods to run implementations of the of the forward logistic layer
*        This class is associated with the daal::algorithms::neural_networks::layers::logistic::forward::Batch class
*        and supports the method of forward logistic layer computation in the batch processing mode
*
* \tparam algorithmFPType  Data type to use in intermediate computations of forward logistic layer, double or float
* \tparam method           Computation method of the layer, \ref daal::algorithms::neural_networks::layers::logistic::Method
* \tparam cpu              Version of the cpu-specific implementation of the layer, \ref daal::CpuType
*
* \DAAL_DEPRECATED
*/
template<typename algorithmFPType, Method method, CpuType cpu>
class BatchContainer : public layers::forward::LayerContainerIfaceImpl
{
public:
    /**
    * Constructs a container for the forward logistic layer with a specified environment
    * in the batch processing mode
    * \param[in] daalEnv   Environment object
     * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED BatchContainer(daal::services::Environment::env *daalEnv);
    /**
     * Default destructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED ~BatchContainer();
    /**
     * Computes the result of the forward logistic layer in the batch processing mode
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status compute() DAAL_C11_OVERRIDE;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LOGISTIC__FORWARD__BATCH"></a>
 * \brief Computes the results of the forward logistic layer in the batch processing mode
 * <!-- \n<a href="DAAL-REF-LOGISTICFORWARD-ALGORITHM">Forward logistic layer description and usage models</a> -->
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations for the forward logistic layer, double or float
 * \tparam method           The forward logistic layer computation method, \ref Method
 *
 * \par Enumerations
 *      - \ref Method                     Computation methods for the forward logistic layer
 *      - \ref forward::InputId           Identifiers of input objects for the forward logistic layer
 *      - \ref forward::ResultId          Identifiers of result objects for the forward logistic layer
 *      - \ref forward::ResultLayerDataId Identifiers of extra results computed by the forward logistic layer
 *      - \ref LayerDataId                Identifiers of collection in result objects for the forward logistic layer
 *
 * \par References
 *      - \ref backward::interface1::Batch "backward::Batch" class
 *
 * \DAAL_DEPRECATED
 */
template<typename algorithmFPType = DAAL_ALGORITHM_FP_TYPE, Method method = defaultDense>
class Batch : public layers::forward::LayerIfaceImpl
{
public:
    typedef layers::forward::LayerIfaceImpl super;

    typedef algorithms::neural_networks::layers::logistic::forward::Input     InputType;
    typedef algorithms::neural_networks::layers::logistic::Parameter          ParameterType;
    typedef algorithms::neural_networks::layers::logistic::forward::Result    ResultType;

    ParameterType &parameter;  /*!< logistic layer \ref interface1::Parameter "parameters" structure */
    InputType input;          /*!< %Input objects of the layer */

    /**
     * Default constructor
     * \DAAL_DEPRECATED
     */
    Batch() : parameter(_defaultParameter)
    {
        initialize();
    };

    /**
     * Constructs a forward logistic layer in the batch processing mode
     * and initializes its parameter with the provided parameter
     * \param[in] parameter Parameter to initialize the parameter of the layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Batch(ParameterType& parameter) : parameter(parameter), _defaultParameter(parameter)
    {
        initialize();
    }

    /**
     * Constructs a forward logistic layer by copying input objects
     * and parameters of another forward logistic layer in the batch processing mode
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
    * Returns method of the forward logistic layer
    * \return Method of the forward logistic layer
     * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED_VIRTUAL virtual int getMethod() const DAAL_C11_OVERRIDE { return(int) method; }

    /**
     * Returns the structure that contains input objects of the forward logistic layer
     * \return Structure that contains input objects of the forward logistic layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual InputType *getLayerInput() DAAL_C11_OVERRIDE { return &input; }

    /**
     * Returns the structure that contains parameters of the forward logistic layer
     * \return Structure that contains parameters of the forward logistic layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual ParameterType *getLayerParameter() DAAL_C11_OVERRIDE { return &parameter; };

    /**
     * Returns the structure that contains results of the forward logistic layer
     * \return Structure that contains results of the forward logistic layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED layers::forward::ResultPtr getLayerResult() DAAL_C11_OVERRIDE
    {
        return getResult();
    }

    /**
     * Returns the structure that contains the result of the forward logistic layer
     * \return Structure that contains the result of forward logistic layer
     * \DAAL_DEPRECATED
     */
    ResultPtr getResult()
    {
        return _result;
    }

    /**
     * Registers user-allocated memory to store results of the forward logistic layer
     * \param[in] result  Structure to store  results of the forward logistic layer
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
     * Returns a pointer to the newly allocated forward logistic layer
     * with a copy of input objects of this forward logistic layer
     * \return Pointer to the newly allocated algorithm
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::SharedPtr<Batch<algorithmFPType, method> > clone() const
    {
        return services::SharedPtr<Batch<algorithmFPType, method> >(cloneImpl());
    }

    /**
     * Allocates memory to store the result of the forward logistic layer
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
        Analysis<batch>::_ac = new __DAAL_ALGORITHM_LAYER_CONTAINER(BatchContainer, algorithmFPType, method)(&_env);
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
} // namespace forward
} // namespace logistic
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal
#endif
