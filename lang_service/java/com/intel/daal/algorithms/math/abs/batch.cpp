/* file: batch.cpp */
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

#include <jni.h>
#include "com_intel_daal_algorithms_math_abs_Batch.h"
#include "com_intel_daal_algorithms_math_abs_Method.h"
#include "daal.h"
#include "common_helpers.h"

USING_COMMON_NAMESPACES()
using namespace daal::algorithms::math;

/*
 * Class:     com_intel_daal_algorithms_math_abs_Batch
 * Method:    cInit
 * Signature:(II)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_math_abs_Batch_cInit
(JNIEnv *env, jobject thisObj, jint prec, jint method)
{
    return jniBatch<abs::Method, abs::Batch, abs::defaultDense, abs::fastCSR>::newObj(prec, method);
}

/*
 * Class:     com_intel_daal_algorithms_math_abs_Batch
 * Method:    cSetResult
 * Signature:(JIIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_math_abs_Batch_cSetResult
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method, jlong resultAddr)
{
    jniBatch<abs::Method, abs::Batch, abs::defaultDense, abs::fastCSR>::setResult<abs::Result>(prec, method, algAddr, resultAddr);
}

/*
 * Class:     com_intel_daal_algorithms_math_abs_Batch
 * Method:    cGetResult
 * Signature:(JII)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_math_abs_Batch_cGetResult
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniBatch<abs::Method, abs::Batch, abs::defaultDense, abs::fastCSR>::getResult(prec, method, algAddr);
}

/*
 * Class:     com_intel_daal_algorithms_math_abs_Batch
 * Method:    cGetInput
 * Signature:(JII)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_math_abs_Batch_cGetInput
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniBatch<abs::Method, abs::Batch, abs::defaultDense, abs::fastCSR>::getInput(prec, method, algAddr);
}

/*
 * Class:     com_intel_daal_algorithms_math_abs_Batch
 * Method:    cClone
 * Signature:(JII)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_math_abs_Batch_cClone
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniBatch<abs::Method, abs::Batch, abs::defaultDense, abs::fastCSR>::getClone(prec, method, algAddr);
}
