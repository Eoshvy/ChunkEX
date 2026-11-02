#include <jni.h>
#include <android/log.h>

#define LOG_TAG "ChunkEX"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// Entry point when LeviLauncher loads the native library
extern "C" JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOGI("ChunkEX mod loaded successfully!");
    return JNI_VERSION_1_6;
}
