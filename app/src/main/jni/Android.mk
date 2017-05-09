#
# Copyright 2014 Google Inc. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)
PROJECT_ROOT_FROM_JNI:= ../../../../..
PROJECT_ROOT:= $(call my-dir)/../../../../..
OPENCVROOT := $(LOCAL_PATH)/../../../../native/jni

include $(CLEAR_VARS)

#opencv
include $(OPENCVROOT)/OpenCV.mk
OPENCV_CAMERA_MODULES:=on
OPENCV_INSTALL_MODULES:=on
OPENCV_LIB_TYPE:=SHARED

LOCAL_MODULE    := test_proj
LOCAL_CFLAGS    := -std=c++11

LOCAL_SRC_FILES := jni_interface.cc \
                   OpencvTest.cpp


#LOCAL_C_INCLUDES := $(OPENCVROOT)/include


LOCAL_LDLIBS    := -llog -lGLESv2 -L$(SYSROOT)/usr/lib

include $(BUILD_SHARED_LIBRARY)