/* file: DropoutLayerDataId.java */
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
 * @ingroup dropout
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.dropout;

import java.lang.annotation.Native;

import com.intel.daal.utils.*;
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__DROPOUT__DROPOUTLAYERDATAID"></a>
 * \brief Identifiers of input objects for the backward dropout layer and results for the forward dropout layer
 */
public final class DropoutLayerDataId {
    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    private int _value;

    /**
     * Constructs the input object identifier using the provided value
     * @param value     Value corresponding to the input object identifier
     */
    public DropoutLayerDataId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the input object identifier
     * @return Value corresponding to the input object identifier
     */
    public int getValue() {
        return _value;
    }

    @Native private static final int auxRetainMaskId = 2;

    public static final DropoutLayerDataId auxRetainMask = new DropoutLayerDataId(auxRetainMaskId);
            /*!< Tensor filled with Bernoulli random variates  (0 in positions that are dropped,
                 1 - in the others) divided by probability that any particular element is retained. */
}
/** @} */
