/* file: MaximumPooling1dForwardResult.java */
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
 * @ingroup maximum_pooling1d_forward
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.maximum_pooling1d;

import com.intel.daal.utils.*;
import com.intel.daal.data_management.data.Factory;
import com.intel.daal.data_management.data.Tensor;
import com.intel.daal.data_management.data.NumericTable;
import com.intel.daal.data_management.data.Factory;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__MAXIMUM_POOLING1D__MAXIMUMPOOLING1DFORWARDRESULT"></a>
 * @brief Class that provides methods to access the result obtained with the compute() method of the
 *        forward one-dimensional maximum pooling layer
 */
public final class MaximumPooling1dForwardResult extends com.intel.daal.algorithms.neural_networks.layers.pooling1d.Pooling1dForwardResult {
    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    /**
    * Constructs the  forward one-dimensional maximum pooling layer
    * @param context   Context to manage the  forward one-dimensional maximum pooling layer
    */
    public MaximumPooling1dForwardResult(DaalContext context) {
        super(context);
        this.cObject = cNewResult();
    }

    public MaximumPooling1dForwardResult(DaalContext context, long cObject) {
        super(context, cObject);
    }

    /**
     * Returns the result of the forward one-dimensional maximum pooling layer
     * @param  id   Identifier of the result
     * @return Result that corresponds to the given identifier
     */
    public Tensor get(MaximumPooling1dLayerDataId id) {
        if (id == MaximumPooling1dLayerDataId.auxSelectedIndices) {
            return (Tensor)Factory.instance().createObject(getContext(), cGetValue(cObject, id.getValue()));
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    /**
     * Returns the result of the forward one-dimensional maximum pooling layer
     * @param  id   Identifier of the result
     * @return Result that corresponds to the given identifier
     */
    public NumericTable get(MaximumPooling1dLayerDataNumericTableId id) {
        if (id == MaximumPooling1dLayerDataNumericTableId.auxInputDimensions) {
            return (NumericTable)Factory.instance().createObject(getContext(), cGetNumericTableValue(cObject, id.getValue()));
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    /**
     * Sets the result of the forward one-dimensional maximum pooling layer
     * @param id   Identifier of the result
     * @param val  Result that corresponds to the given identifier
     */
    public void set(MaximumPooling1dLayerDataId id, Tensor val) {
        if (id == MaximumPooling1dLayerDataId.auxSelectedIndices) {
            cSetValue(cObject, id.getValue(), val.getCObject());
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    /**
     * Sets the result of the forward one-dimensional maximum pooling layer
     * @param id   Identifier of the result
     * @param val  Result that corresponds to the given identifier
     */
    public void set(MaximumPooling1dLayerDataNumericTableId id, NumericTable val) {
        if (id == MaximumPooling1dLayerDataNumericTableId.auxInputDimensions) {
            cSetValue(cObject, id.getValue(), val.getCObject());
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    private native long cNewResult();
    private native long cGetValue(long cObject, int id);
    private native void cSetValue(long cObject, int id, long ntAddr);
    private native long cGetNumericTableValue(long cObject, int id);
    private native void cSetNumericTableValue(long cObject, int id, long ntAddr);
}
/** @} */
