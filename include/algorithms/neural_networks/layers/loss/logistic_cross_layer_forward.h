/* file: logistic_cross_layer_forward.h */
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
//  Implementation of the interface for the forward logistic cross-entropy layer in the batch processing mode
//--
*/

#ifndef __LOSS_LOGISTIC_CROSS_LAYER_FORWARD_H__
#define __LOSS_LOGISTIC_CROSS_LAYER_FORWARD_H__

#include "algorithms/algorithm.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/layer.h"
#include "algorithms/neural_networks/layers/loss/loss_layer_forward.h"
#include "algorithms/neural_networks/layers/loss/logistic_cross_layer_types.h"
#include "algorithms/neural_networks/layers/loss/logistic_cross_layer_forward_types.h"
#include "algorithms/neural_networks/layers/logistic/logistic_layer_forward.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace loss
{
namespace logistic_cross
{
namespace forward
{
namespace interface1
{
/**
 * @defgroup logistic_cross_forward_batch Batch
 * @ingroup logistic_cross_forward
 * @{
 */
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LOSS__LOGISTIC_CROSS__FORWARD__BATCHCONTAINER"></a>
* \brief Provides methods to run implementations of the of the forward logistic cross-entropy layer
*        This class is associated with the daal::algorithms::neural_networks::layers::loss::logistic_cross::forward::Batch class
*        and supports the method of forward logistic cross-entropy layer computation in the batch processing mode
*
* \tparam algorithmFPType  Data type to use in intermediate computations of forward logistic cross-entropy layer, double or float
* \tparam method           Computation method of the layer, \ref daal::algorithms::neural_networks::layers::loss::logistic_cross::Method
* \tparam cpu              Version of the cpu-specific implementation of the layer, \ref daal::CpuType
*
* \DAAL_DEPRECATED
*/
template<typename algorithmFPType, Method method, CpuType cpu>
class BatchContainer : public layers::forward::LayerContainerIfaceImpl
{
public:
    /**
     * Constructs a container for the forward logistic cross-entropy with a specified environment
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
     * Computes the result of the forward logistic cross-entropy layer in the batch processing mode
     *
     * \return Status of computation
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status compute() DAAL_C11_OVERRIDE;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LOSS__LOGISTIC_CROSS__FORWARD__BATCH"></a>
 * \brief Provides methods for the forward logistic cross layer in the batch processing mode
 * <!-- \n<a href="DAAL-REF-LOGISTIC_CROSSFORWARD-ALGORITHM">Forward logistic cross-entropy layer description and usage models</a> -->
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations for the forward logistic cross-entropy layer, double or float
 * \tparam method           Forward logistic cross-entropy layer method, \ref Method
 *
 * \par Enumerations
 *      - \ref Method                     Computation methods for the forward logistic cross-entropy layer
 *      - \ref forward::InputId           Identifiers of input objects for the forward logistic cross-entropy layer
 *      - \ref forward::ResultId          Identifiers of result objects for the forward logistic cross-entropy layer
 *      - \ref forward::ResultLayerDataId Identifiers of extra results computed by the forward logistic cross-entropy layer
 *      - \ref LayerDataId                Identifiers of collection in result objects for the forward logistic cross-entropy layer
 *
 * \par References
 *      - \ref backward::interface1::Batch "backward::Batch" class
 *
 * \DAAL_DEPRECATED
 */
template<typename algorithmFPType = DAAL_ALGORITHM_FP_TYPE, Method method = defaultDense>
class Batch : public loss::forward::Batch
{
public:
    typedef loss::forward::Batch super;

    typedef algorithms::neural_networks::layers::loss::logistic_cross::forward::Input     InputType;
    typedef algorithms::neural_networks::layers::loss::logistic_cross::Parameter          ParameterType;
    typedef algorithms::neural_networks::layers::loss::logistic_cross::forward::Result    ResultType;

    ParameterType &parameter; /*!< Forward logistic cross-entropy layer \ref interface1::Parameter "parameters" */
    InputType input;          /*!< Forward logistic cross-entropy layer input */

    /**
     * Default constructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Batch() : parameter(_defaultParameter)
    {
        initialize();
    };

    /**
     * Constructs a forward logistic cross-entropy layer in the batch processing mode
     * and initializes its parameter with the provided parameter
     * \param[in] parameter Parameter to initialize the parameter of the layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Batch(ParameterType& parameter) : parameter(parameter), _defaultParameter(parameter)
    {
        initialize();
    }

    /**
     * Constructs a forward logistic cross-entropy layer by copying input objects
     * and parameters of another forward logistic cross-entropy layer in the batch processing mode
     * \param[in] other Algorithm to use as the source to initialize the input objects
     *                  and parameters of the layer
     * \DAAL_DEPRECATED
     */
    Batch(const Batch<algorithmFPType, method> &other) : super(other),
        _defaultParameter(other.parameter), parameter(_defaultParameter), input(other.input)
    {
        initialize();
    }

    /**
    * Returns the method of the layer
    * \return Method of the layer
     * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED_VIRTUAL virtual int getMethod() const DAAL_C11_OVERRIDE { return(int) method; }

    /**
     * Returns the structure that contains the input objects of the forward logistic cross-entropy layer
     * \return Structure that contains the input objects of the forward logistic cross-entropy layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual InputType *getLayerInput() DAAL_C11_OVERRIDE { return &input; }

    /**
     * Returns the structure that contains the parameters of the forward logistic cross-entropy layer
     * \return Structure that contains the parameters of the forward logistic cross-entropy layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual ParameterType *getLayerParameter() DAAL_C11_OVERRIDE { return &parameter; };

    /**
     * Returns the structure that contains result of the forward logistic cross-entropy layer
     * \return Structure that contains result of the forward logistic cross-entropy layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED layers::forward::ResultPtr getLayerResult() DAAL_C11_OVERRIDE
    {
        return getResult();
    }

    /**
     * Returns the structure that contains the result of the forward logistic cross-entropy layer
     * \return Structure that contains the result of the forward logistic cross-entropy layer
     * \DAAL_DEPRECATED
     */
    ResultPtr getResult()
    {
        return _result;
    }

    /**
     * Registers user-allocated memory to store the result of the forward logistic cross-entropy layer
     * \param[in] result Structure to store the result of the forward logistic cross-entropy layer
     *
     * \return Status of computation
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
     * Returns a pointer to a newly allocated forward logistic cross-entropy layer
     * with a copy of the input objects and parameters for this forward logistic cross-entropy layer
     * in the batch processing mode
     * \return Pointer to the newly allocated algorithm
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::SharedPtr<Batch<algorithmFPType, method> > clone() const
    {
        return services::SharedPtr<Batch<algorithmFPType, method> >(cloneImpl());
    }

    /**
     * Allocates memory to store the result of the forward logistic cross-entropy layer
     *
     * \return Status of computation
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status allocateResult() DAAL_C11_OVERRIDE
    {
        services::Status s = this->_result->template allocate<algorithmFPType>(&(this->input), &parameter, (int) method);
        this->_res = this->_result.get();
        return s;
    }

    /**
     * Returns forward logistic layer - the layer that corresponds to this layer on the prediction stage
     * \return Forward logistic layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual layers::forward::LayerIfacePtr getLayerForPrediction() const DAAL_C11_OVERRIDE
    {
        return layers::forward::LayerIfacePtr(
            new layers::logistic::forward::Batch<algorithmFPType>());
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
} // namespace logistic_cross
} // namespace loss
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal
#endif
