/* file: neural_networks_training_distributed.h */
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
//  Implementation of the interface for neural network model-based training
//  in the distributed processing mode
//--
*/

#ifndef __NEURAL_NETWORKS_TRAINING_DISTRIBUTED_H__
#define __NEURAL_NETWORKS_TRAINING_DISTRIBUTED_H__

#include "algorithms/algorithm.h"

#include "services/daal_defines.h"
#include "algorithms/neural_networks/neural_networks_types.h"
#include "algorithms/neural_networks/neural_networks_training_types.h"
#include "algorithms/neural_networks/neural_networks_training_model.h"
#include "algorithms/neural_networks/layers/layer.h"

namespace daal
{
namespace algorithms
{
/**
 * \brief Contains classes for neural network model-based training and prediction
 */
namespace neural_networks
{
namespace training
{
namespace interface1
{
/**
 * @defgroup neural_networks_training_distributed Distributed
 * @ingroup neural_networks_training
 * @{
 */
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__TRAINING__DISTRIBUTEDCONTAINER"></a>
 * \brief Class containing methods to train neural network model in the distributed processing mode
 *        using algorithmFPType precision arithmetic
 * \DAAL_DEPRECATED
 */
template<ComputeStep step, typename algorithmFPType, Method method, CpuType cpu>
class DistributedContainer
{};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__TRAINING__DISTRIBUTEDCONTAINER_STEP1LOCAL_ALGORITHMFPTYPE_METHOD_CPU"></a>
 * \brief Class containing methods to train neural network model using algorithmFPType precision arithmetic
 * \DAAL_DEPRECATED
 */
template<typename algorithmFPType, Method method, CpuType cpu>
class DistributedContainer<step1Local, algorithmFPType, method, cpu> : public TrainingContainerIface<distributed>
{
public:
    /**
     * Constructs a container for neural network model-based training with a specified environment
     * in the batch processing mode
     * \param[in] daalEnv   Environment object
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED DistributedContainer(daal::services::Environment::env *daalEnv);
    /** Destructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED ~DistributedContainer();
    /**
     * Computes a partial result of neural network model-based training in the distributed processing mode
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status compute() DAAL_C11_OVERRIDE;
    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status setupCompute() DAAL_C11_OVERRIDE;
    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status resetCompute() DAAL_C11_OVERRIDE;
    /**
     * Computes the result of neural network model-based training
     * in the first step of the distributed processing mode
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status finalizeCompute() DAAL_C11_OVERRIDE;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__TRAINING__DISTRIBUTEDCONTAINER_STEP2MASTER_ALGORITHMFPTYPE_METHOD_CPU"></a>
 * \brief Class containing methods to train neural network model using algorithmFPType precision arithmetic
 * \DAAL_DEPRECATED
 */
template<typename algorithmFPType, Method method, CpuType cpu>
class DistributedContainer<step2Master, algorithmFPType, method, cpu> : public TrainingContainerIface<distributed>
{
public:
    /**
     * Constructs a container for neural network model-based training with a specified environment
     * in the batch processing mode
     * \param[in] daalEnv   Environment object
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED DistributedContainer(daal::services::Environment::env *daalEnv);
    /** Destructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED ~DistributedContainer();
    /**
     * Computes a partial result of neural network model-based training in the distributed processing mode
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status compute() DAAL_C11_OVERRIDE;
    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status setupCompute() DAAL_C11_OVERRIDE;
    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status resetCompute() DAAL_C11_OVERRIDE;
    /**
     * Computes the result of neural network model-based training
     * in the first step of the distributed processing mode
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status finalizeCompute() DAAL_C11_OVERRIDE;
};


/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__TRAINING__DISTRIBUTED"></a>
 * \brief Provides methods for neural network model-based training in the batch processing mode
 * <!-- \n<a href="DAAL-REF-NEURALNETWORK-ALGORITHM">Neural network algorithm description and usage models</a> -->
 *
 * \tparam step             Step of the neural network algorithm in the distributed processing mode
 * \tparam algorithmFPType  Data type to use in intermediate computations for neural network model-based training, double or float
 * \tparam method           Neural network training method, training::Method
 *
 * \par Enumerations
 *      - training::Method  Computation methods
 *
 * \par References
 *      - \ref interface1::Parameter "Parameter" class
 *      - \ref neural_networks::training::interface1::Model "neural_networks::training::Model" class
 *      - \ref prediction::interface1::Batch "prediction::Batch" class
 *
 * \DAAL_DEPRECATED
 */
template<ComputeStep step, typename algorithmFPType = DAAL_ALGORITHM_FP_TYPE, Method method = defaultDense>
class DAAL_EXPORT Distributed
{};


/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__TRAINING__DISTRIBUTED_STEP1LOCAL_ALGORITHMFPTYPE_METHOD"></a>
 * \brief Provides methods for neural network model-based training in the batch processing mode
 * <!-- \n<a href="DAAL-REF-NEURALNETWORK-ALGORITHM">Neural network algorithm description and usage models</a> -->
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations for neural network model-based training, double or float
 * \tparam method           Neural network training method, training::Method
 *
 * \par Enumerations
 *      - training::Method  Computation methods
 *
 * \par References
 *      - \ref neural_networks::training::interface1::Model "neural_networks::training::Model" class
 *      - \ref prediction::interface1::Batch "prediction::Batch" class
 *
 * \DAAL_DEPRECATED
 */
template<typename algorithmFPType, Method method>
class DAAL_EXPORT Distributed<step1Local, algorithmFPType, method> : public Training<distributed>
{
public:
    typedef algorithms::neural_networks::training::DistributedInput<step1Local> InputType;
    typedef algorithms::neural_networks::training::Parameter                    ParameterType;
    typedef algorithms::neural_networks::training::Result                       ResultType;
    typedef algorithms::neural_networks::training::PartialResult                PartialResultType;

    DistributedInput<step1Local> input;            /*!< %Input data structure */
    ParameterType parameter;    /*!< %Training parameters */

    /** Default constructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Distributed()
    {
        initialize();
    };

    /**
     * Constructs neural network by copying input objects and parameters of another neural network
     * \param[in] other An algorithm to be used as the source to initialize the input objects
     *                  and parameters of the algorithm
     * \DAAL_DEPRECATED
     */
    Distributed(const Distributed<step1Local, algorithmFPType, method> &other) : parameter(other.parameter), input(other.input)
    {
        initialize();
    }

    /**
     * \DAAL_DEPRECATED
     */
    virtual ~Distributed() {}

    /**
     * Registers user-allocated memory to store  partial results of the neural network algorithm
     * \param[in] partialResult    Structure for storing partial results of the neural network algorithm
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status setPartialResult(const PartialResultPtr& partialResult)
    {
        _partialResult = partialResult;
        _pres = _partialResult.get();
        return services::Status();
    }

    /**
     * Returns structure that contains computed partial results of the neural network algorithm
     * \return Structure that contains partial results of the neural network algorithm
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED PartialResultPtr getPartialResult() { return _partialResult; }

    /**
     * Returns the structure that contains the results of the neural network algorithm
     * \return Structure that contains the results of the neural network algorithm
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED ResultPtr getResult()
    {
        return _result;
    }

    /**
     * Register user-allocated memory to store the results of the neural network algorithm
     * \param[in] res    Structure for storing results of the neural network algorithm
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status setResult(const ResultPtr& res)
    {
        DAAL_CHECK(res, services::ErrorNullResult)
        _result = res;
        _res = _result.get();
        return services::Status();
    }

    /**
     * Returns a pointer to the newly allocated neural network
     * with a copy of input objects and parameters of this neural network
     * \return Pointer to the newly allocated layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::SharedPtr<Distributed<step1Local, algorithmFPType, method> > clone() const
    {
        return services::SharedPtr<Distributed<step1Local, algorithmFPType, method> >(cloneImpl());
    }

    /**
     * Returns method of the algorithm
     * \return Method of the algorithm
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual int getMethod() const DAAL_C11_OVERRIDE { return(int) method; }

protected:
    /**
     * \DAAL_DEPRECATED
     */
    void initialize()
    {
        _ac = new __DAAL_ALGORITHM_CONTAINER(distributed, DistributedContainer, step1Local, algorithmFPType, method)(&_env);
        _in = &input;
        _par = &parameter;
        _partialResult.reset(new PartialResultType());
        _result.reset(new ResultType());
    }

    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual Distributed<step1Local, algorithmFPType, method> *cloneImpl() const DAAL_C11_OVERRIDE
    {
        return new Distributed<step1Local, algorithmFPType, method>(*this);
    }

    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status allocateResult() DAAL_C11_OVERRIDE
    {
        services::Status s = _result->allocate<algorithmFPType>(&input, &parameter, (int) method);
        _res = _result.get();
        return s;
    }

    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status allocatePartialResult() DAAL_C11_OVERRIDE
    {
        services::Status s = _partialResult->allocate<algorithmFPType>(&input, &parameter, method);
        _pres = _partialResult.get();
        return s;
    }

    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status initializePartialResult() DAAL_C11_OVERRIDE
    {
        _pres = _partialResult.get();
        return services::Status();
    }
private:
    PartialResultPtr _partialResult;
    ResultPtr _result;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__TRAINING__DISTRIBUTED_STEP2MASTER_ALGORITHMFPTYPE_METHOD"></a>
 * \brief Provides methods for neural network model-based training in the batch processing mode
 * <!-- \n<a href="DAAL-REF-NEURALNETWORK-ALGORITHM">Neural network algorithm description and usage models</a> -->
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations for neural network model-based training, double or float
 * \tparam method           Neural network training method, training::Method
 *
 * \par Enumerations
 *      - training::Method  Computation methods
 *
 * \par References
 *      - \ref neural_networks::training::interface1::Model "neural_networks::training::Model" class
 *      - \ref prediction::interface1::Batch "prediction::Batch" class
 *
 * \DAAL_DEPRECATED
 */
template<typename algorithmFPType, Method method>
class DAAL_EXPORT Distributed<step2Master, algorithmFPType, method> : public Training<distributed>
{
public:
    typedef algorithms::neural_networks::training::DistributedInput<step2Master> InputType;
    typedef algorithms::neural_networks::training::Parameter                     ParameterType;
    typedef algorithms::neural_networks::training::Result                        ResultType;
    typedef algorithms::neural_networks::training::DistributedPartialResult      PartialResultType;

    DistributedInput<step2Master> input;            /*!< %Input data structure */
    ParameterType parameter;    /*!< %Training parameters */

    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Distributed(const services::SharedPtr<optimization_solver::iterative_solver::Batch >& optimizationSolver_) : parameter(optimizationSolver_)
    {
        initialize();
    };

    /**
     * Constructs neural network by copying input objects and parameters of another neural network
     * \param[in] other An algorithm to be used as the source to initialize the input objects
     *                  and parameters of the algorithm
     * \DAAL_DEPRECATED
     */
     Distributed(const Distributed<step2Master, algorithmFPType, method> &other) : parameter(other.parameter), input(other.input)
    {
        initialize();
    }

    /**
     * \DAAL_DEPRECATED
     */
    virtual ~Distributed() {}

    /**
     * Initializes the neural network topology
     * \param[in] dataSize Collection of sizes of each dimension of input data tensor
     * \param[in] topology Neural network topology
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status initialize(const services::Collection<size_t> &dataSize, const training::Topology &topology)
    {
        ResultPtr result = getResult();
        if (!result || !result->get(neural_networks::training::model))
        {
            return services::Status(services::ErrorNullModel);
        }
        result->get(neural_networks::training::model)->initialize<algorithmFPType>(dataSize, topology, parameter);
        return services::Status();
    }

    /**
     * Registers user-allocated memory to store  partial results of the neural network algorithm
     * \param[in] partialResult    Structure for storing partial results of the neural network algorithm
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status setPartialResult(const DistributedPartialResultPtr& partialResult)
    {
        _partialResult = partialResult;
        _pres = _partialResult.get();
        return services::Status();
    }

    /**
     * Returns structure that contains computed partial results of the neural network algorithm
     * \return Structure that contains partial results of the neural network algorithm
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED DistributedPartialResultPtr getPartialResult() { return _partialResult; }

    /**
     * Returns the structure that contains the results of the neural network algorithm
     * \return Structure that contains the results of the neural network algorithm
     * \DAAL_DEPRECATED
     */
    ResultPtr getResult()
    {
        return _partialResult->get(resultFromMaster);
    }

    /**
     * Returns a pointer to the newly allocated neural network
     * with a copy of input objects and parameters of this neural network
     * \return Pointer to the newly allocated layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::SharedPtr<Distributed<step2Master, algorithmFPType, method> > clone() const
    {
        return services::SharedPtr<Distributed<step2Master, algorithmFPType, method> >(cloneImpl());
    }

    /**
     * Returns method of the algorithm
     * \return Method of the algorithm
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual int getMethod() const DAAL_C11_OVERRIDE { return(int) method; }

protected:
    /**
     * \DAAL_DEPRECATED
     */
    void initialize()
    {
        _ac = new __DAAL_ALGORITHM_CONTAINER(distributed, DistributedContainer, step2Master, algorithmFPType, method)(&_env);
        _in = &input;
        _par = &parameter;
        _partialResult = DistributedPartialResultPtr(new PartialResultType());
    }

    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual Distributed<step2Master, algorithmFPType, method> *cloneImpl() const DAAL_C11_OVERRIDE
    {
        return new Distributed<step2Master, algorithmFPType, method>(*this);
    }

    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status allocateResult() DAAL_C11_OVERRIDE
    {
        return services::Status();
    }

    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status allocatePartialResult() DAAL_C11_OVERRIDE
    {
        services::Status s = _partialResult->allocate<algorithmFPType>(&input, &parameter, method);
        _pres = _partialResult.get();
        return s;
    }

    /**
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status initializePartialResult() DAAL_C11_OVERRIDE
    {
        _pres = _partialResult.get();
        return services::Status();
    }
private:
    DistributedPartialResultPtr _partialResult;
};
/** @} */
} // namespace interface1
using interface1::Distributed;
using interface1::DistributedContainer;

} // namespace training
} // namespace neural_networks
} // namespace algorithms
} // namespace daal
#endif
