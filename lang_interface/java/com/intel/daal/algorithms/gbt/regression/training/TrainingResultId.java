/* file: TrainingResultId.java */
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
 * @ingroup gbt_regression_training
 * @{
 */
package com.intel.daal.algorithms.gbt.regression.training;

import java.lang.annotation.Native;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__GBT__REGRESSION__TRAINING__TRAININGRESULTID"></a>
 * @brief Available identifiers of results of gbt regression model training algorithm
 */
public final class TrainingResultId {
    private int _value;

    /**
     * Constructs the training result object identifier using the provided value
     * @param value     Value corresponding to the training result object identifier
     */
    public TrainingResultId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the training result object identifier
     * @return Value corresponding to the training result object identifier
     */
    public int getValue() {
        return _value;
    }

    @Native private static final int Model = 0;

    /** Trained model */
    public static final TrainingResultId model = new TrainingResultId(Model);
}
/** @} */
