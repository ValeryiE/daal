/* file: Batch.java */
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
 * @defgroup logistic Logistic
 * @brief Contains classes for computing the logistic function
 * @ingroup math
 * @{
 */
/**
 * @defgroup logistic_batch Batch
 * @ingroup logistic
 * @{
 */
package com.intel.daal.algorithms.math.logistic;

import com.intel.daal.utils.*;
import com.intel.daal.algorithms.AnalysisBatch;
import com.intel.daal.algorithms.Precision;
import com.intel.daal.algorithms.ComputeMode;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__LOGISTIC__BATCH"></a>
 * \brief Computes logistic function in the batch processing mode.
 * <!-- \n<a href="DAAL-REF-LOGISTIC-ALGORITHM">Logistic function description and usage models</a> -->
 *
 * \par References
 *      - @ref InputId class
 *      - @ref ResultId class
 *
 */
public class Batch extends AnalysisBatch {
    public Input      input;    /*!< %Input data */
    public Method     method;   /*!< Computation method for the function */
    private Precision prec;     /*!< Data type to use in intermediate computations for the function */

    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    /**
     * Constructs logistic function by copying input objects of another logistic function
     * @param context    Context to manage the logistic function
     * @param other      An function to be used as the source to initialize the input objects of the function
     */
    public Batch(DaalContext context, Batch other) {
        super(context);
        this.method = other.method;
        prec = other.prec;

        this.cObject = cClone(other.cObject, prec.getValue(), method.getValue());
        input = new Input(context, cGetInput(cObject, prec.getValue(), method.getValue()));
    }

    /**
     * <a name="DAAL-METHOD-ALGORITHM__LOGISTIC__BATCH__BATCH"></a>
     * Constructs the logistic function
     *
     * @param context    Context to manage the logistic function
     * @param cls        Data type to use in intermediate computations for the logistic function, Double.class or Float.class
     * @param method     The logistic function computation method, @ref Method
     */
    public Batch(DaalContext context, Class<? extends Number> cls, Method method) {
        super(context);

        this.method = method;

        if (method != Method.defaultDense) {
            throw new IllegalArgumentException("method unsupported");
        }
        if (cls != Double.class && cls != Float.class) {
            throw new IllegalArgumentException("type unsupported");
        }

        if (cls == Double.class) {
            prec = Precision.doublePrecision;
        }
        else {
            prec = Precision.singlePrecision;
        }

        this.cObject = cInit(prec.getValue(), method.getValue());
        input = new Input(context, cGetInput(cObject, prec.getValue(), method.getValue()));
    }

    /**
     * Computes the logistic function
     * @return  The logistic function result
    */
    @Override
    public Result compute() {
        super.compute();
        Result result = new Result(getContext(), cGetResult(cObject, prec.getValue(), method.getValue()));
        return result;
    }

    /**
     * Registers user-allocated memory to store the result of the logistic function
     * @param result    Structure to store the result of the logistic function
     */
    public void setResult(Result result) {
        cSetResult(cObject, prec.getValue(), method.getValue(), result.getCObject());
    }

    /**
     * Returns the newly allocated logistic function
     * with a copy of the input object of this logistic function
     * @param context    Context to manage the logistic function
     *
     * @return The newly allocated function
     */
    @Override
    public Batch clone(DaalContext context) {
        return new Batch(context, this);
    }

    private native long cInit(int prec, int method);
    private native void cSetResult(long cAlgorithm, int prec, int method, long cObject);
    private native long cGetResult(long cAlgorithm, int prec, int method);
    private native long cGetInput(long cAlgorithm, int prec, int method);
    private native long cClone(long algAddr, int prec, int method);
}
/** @} */
/** @} */
