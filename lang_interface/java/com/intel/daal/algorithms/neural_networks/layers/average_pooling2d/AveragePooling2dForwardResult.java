/* file: AveragePooling2dForwardResult.java */
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
 * @ingroup average_pooling2d_forward
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.average_pooling2d;

import com.intel.daal.utils.*;
import com.intel.daal.data_management.data.Factory;
import com.intel.daal.data_management.data.NumericTable;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__AVERAGE_POOLING2D__AVERAGEPOOLING2DFORWARDRESULT"></a>
 * @brief Class that provides methods to access the result obtained with the compute() method
 *        of the forward two-dimensional average pooling layer
 */
public final class AveragePooling2dForwardResult extends com.intel.daal.algorithms.neural_networks.layers.pooling2d.Pooling2dForwardResult {
    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    public AveragePooling2dForwardResult(DaalContext context, long cObject) {
        super(context, cObject);
    }

    /**
    * Constructs the forward two-dimensional average pooling layer
    * @param context   Context to manage the forward two-dimensional average pooling layer
    */
    public AveragePooling2dForwardResult(DaalContext context) {
        super(context);
        this.cObject = cNewResult();
    }

    /**
     * Returns the result of the forward two-dimensional average pooling layer
     * @param  id   Identifier of the result
     * @return Result that corresponds to the given identifier
     */
    public NumericTable get(AveragePooling2dLayerDataId id) {
        if (id == AveragePooling2dLayerDataId.auxInputDimensions) {
            return (NumericTable)Factory.instance().createObject(getContext(), cGetValue(cObject, id.getValue()));
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    /**
     * Sets the result of the forward two-dimensional average pooling layer
     * @param id   Identifier of the result
     * @param val  Result that corresponds to the given identifier
     */
    public void set(AveragePooling2dLayerDataId id, NumericTable val) {
        if (id == AveragePooling2dLayerDataId.auxInputDimensions) {
            cSetValue(cObject, id.getValue(), val.getCObject());
        }
        else {
            throw new IllegalArgumentException("id unsupported");
        }
    }

    private native long cNewResult();
    private native long cGetValue(long cObject, int id);
    private native void cSetValue(long cObject, int id, long ntAddr);
}
/** @} */
