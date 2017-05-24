/*
 * Copyright 2014 Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <jni.h>
#include <header/OpencvTest.h>

static test_proj::ImageProcessing app;

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT void JNICALL
Java_com_example_caig_opencv_1test_JniNative_cannyEdge(
    JNIEnv *, jclass, jlong inputMat, jlong outputMat) {

    Mat& inputImage  = *(Mat*)inputMat;
    Mat& outputImage = *(Mat*)outputMat;

    app.toCannyEdge(inputImage, outputImage);
}

JNIEXPORT void JNICALL
Java_com_example_caig_opencv_1test_JniNative_saveFilePath(
    JNIEnv* env, jobject /*obj*/, jstring inputFilePath) {

    const char *nativeString = env->GetStringUTFChars(inputFilePath, 0);
    char* s = (char*)nativeString;
    app.savePath(s);
}

#ifdef __cplusplus
}
#endif
