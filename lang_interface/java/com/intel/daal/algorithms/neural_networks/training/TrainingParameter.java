/* file: TrainingParameter.java */
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

/**
 * @ingroup neural_networks_training
 * @{
 */
package com.intel.daal.algorithms.neural_networks.training;

import com.intel.daal.services.DaalContext;
import com.intel.daal.algorithms.Precision;
import com.intel.daal.algorithms.optimization_solver.iterative_solver.*;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__TRAINING__TRAININGPARAMETER"></a>
 * \brief Class representing the parameters of neural network
 */
public class TrainingParameter extends com.intel.daal.algorithms.Parameter {
    Precision prec;

    public TrainingParameter(DaalContext context, long cParameter) {
        super(context, cParameter);
    }

    /**
     * Constructs the parameters of neural network algorithm
     * @param context   Context to manage the parameter object
     * @param optimizationSolver Optimization solver
     */
    public TrainingParameter(DaalContext context, com.intel.daal.algorithms.optimization_solver.iterative_solver.Batch optimizationSolver) {
        super(context);
        cObject = cInit(optimizationSolver.cObject);
        setOptimizationSolver(optimizationSolver);
    }


    /**
     *  Gets the optimization solver used in the neural network
     */
    public com.intel.daal.algorithms.optimization_solver.iterative_solver.Batch getOptimizationSolver() {
        return new com.intel.daal.algorithms.optimization_solver.iterative_solver.Batch(getContext(), cGetOptimizationSolver(cObject));
    }

    /**
     *  Sets the optimization solver used in the neural network
     *  @param optimizationSolver Optimization solver used in the neural network
     */
    public void setOptimizationSolver(com.intel.daal.algorithms.optimization_solver.iterative_solver.Batch optimizationSolver) {
        cSetOptimizationSolver(cObject, optimizationSolver.cObject);
    }

    /**
     * Sets the engine to be used by the neural network
     * @param engine to be used by the neural network
     */
    public void setEngine(com.intel.daal.algorithms.engines.BatchBase engine) {
        cSetEngine(cObject, engine.cObject);
    }

    private native long cInit(long cOptimiztionSolver);
    private native long cGetOptimizationSolver(long cParameter);
    private native void cSetOptimizationSolver(long cParameter, long optAddr);
    private native void cSetEngine(long cObject, long cEngineObject);
}
/** @} */
