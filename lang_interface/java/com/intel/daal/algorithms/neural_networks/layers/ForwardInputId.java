/* file: ForwardInputId.java */
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
 * @ingroup layers_forward
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers;

import java.lang.annotation.Native;

import com.intel.daal.utils.*;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__FORWARDINPUTID"></a>
 * \brief Available identifiers of input objects for the forward layer
 */
public final class ForwardInputId {
    /** @private */
    static {
        LibUtils.loadLibrary();
    }

    private int _value;

    /**
     * Constructs the input object identifier using the provided value
     * @param value     Value corresponding to the input object identifier
     */
    public ForwardInputId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the input object identifier
     * @return Value corresponding to the input object identifier
     */
    public int getValue() {
        return _value;
    }

    @Native private static final int dataId = 0;
    @Native private static final int weightsId = 1;
    @Native private static final int biasesId = 2;

    public static final ForwardInputId data = new ForwardInputId(dataId); /*!< Input data */
    public static final ForwardInputId weights = new ForwardInputId(weightsId); /*!< Weights of the neural network layer */
    public static final ForwardInputId biases = new ForwardInputId(biasesId); /*!< Biases of the neural network layer */
}
/** @} */
