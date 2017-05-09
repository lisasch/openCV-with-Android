#ifndef OPENCV_TEST_UTIL_H
#define OPENCV_TEST_UTIL_H

#include <android/log.h>

#define LOGI(...) \
  __android_log_print(ANDROID_LOG_INFO, "test_proj", __VA_ARGS__)
#define LOGE(...) \
  __android_log_print(ANDROID_LOG_ERROR, "test_proj", __VA_ARGS__)
#define LOGW(...) \
  __android_log_print(ANDROID_LOG_WARN, "test_proj", __VA_ARGS__)
#define LOGD(...) \
  __android_log_print(ANDROID_LOG_DEBUG, "test_proj", __VA_ARGS__)

#endif //OPENCV_TEST_UTIL_H
