/* file: LcnParameter.java */
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
 * @ingroup lcn_layers
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.lcn;

import com.intel.daal.services.DaalContext;
import com.intel.daal.data_management.data.NumericTable;
import com.intel.daal.data_management.data.Tensor;
import com.intel.daal.data_management.data.Factory;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LCN__LCNPARAMETER"></a>
 * \brief Class that specifies parameters of the local contrast normalization layer
 */
public class LcnParameter extends com.intel.daal.algorithms.neural_networks.layers.Parameter {

    /**
     * Constructs the parameter of the local contrast normalization layer
     * @param context Context to manage the parameter of the local contrast normalization layer
     */
    public LcnParameter(DaalContext context) {
        super(context);
        cObject = cInit();
    }
    /**
     * Constructs parameter from C++ parameter
     * @param context Context to manage the parameter
     * @param cObject Address of C++ parameter
     */
    public LcnParameter(DaalContext context, long cObject) {
        super(context, cObject);
    }

    /**
     * Gets the structure representing the indices of the two dimensions on which local contrast normalization is performed
     * @return The structure representing the indices of the two dimensions on which local contrast normalization is performed
     */
    public LcnIndices getIndices() {
        long[] dims = cGetIndices(cObject);
        return new LcnIndices(dims[0], dims[1]);
    }

    /**
     * Sets the structure representing the indices of the two dimensions on which local contrast normalization is performed
     * @param indices   The structure representing the indices of the two dimensions on which local contrast normalization is performed
     */
    public void setIndices(LcnIndices indices) {
        long[] dims = indices.getSize();
        cSetIndices(cObject, dims[0], dims[1]);
    }

    /**
     *  Gets the numeric table of size 1x1 that stores dimension f
     */
    public NumericTable getSumDimension() {
        return (NumericTable)Factory.instance().createObject(getContext(), cGetSumDimension(cObject));
    }

    /**
     *  Sets the numeric table of size 1x1 that stores dimension f
     *  @param sumDimension   Numeric table of size 1x1 that stores dimension f
     */
    public void setSumDimension(NumericTable sumDimension) {
        cSetSumDimension(cObject, sumDimension.getCObject());
    }

    /**
     *  Gets the tensor of the two-dimensional kernel
     */
    public Tensor getKernel() {
        return (Tensor)Factory.instance().createObject(getContext(), cGetKernel(cObject));
    }

    /**
     *  Sets the tensor of the two-dimensional kernel
     *  @param kernel   Tensor of the two-dimensional kernel
     */
    public void setKernel(Tensor kernel) {
        cSetKernel(cObject, kernel.getCObject());
    }

    private native long cInit();
    private native void cSetIndices(long cObject, long first, long second);
    private native long[] cGetIndices(long cObject);
    private native long cGetSumDimension(long cParameter);
    private native void cSetSumDimension(long cParameter, long sumDimension);
    private native long cGetKernel(long cParameter);
    private native void cSetKernel(long cParameter, long kernel);
}
/** @} */
