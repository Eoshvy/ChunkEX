#include <jni.h>
#include <android/log.h>
#include <cmath>

#define LOG_TAG "ChunkEX"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// Structure to track local player chunk positions
struct ChunkPos {
    int x;
    int z;
};

// Helper function to calculate current chunk from player block coordinates
ChunkPos getChunkFromPos(double playerX, double playerZ) {
    ChunkPos pos;
    pos.x = static_cast<int>(std::floor(playerX / 16.0));
    pos.z = static_cast<int>(std::floor(playerZ / 16.0));
    return pos;
}

// Function to log chunk boundary bounds for rendering overlay
void logChunkBorders(double x, double z) {
    ChunkPos currentChunk = getChunkFromPos(x, z);
    
    int minBlockX = currentChunk.x * 16;
    int maxBlockX = minBlockX + 15;
    int minBlockZ = currentChunk.z * 16;
    int maxBlockZ = minBlockZ + 15;

    LOGI("[ChunkEX] Player in Chunk [%d, %d] | X: %d to %d | Z: %d to %d",
         currentChunk.x, currentChunk.z, minBlockX, maxBlockX, minBlockZ, maxBlockZ);
}

// Native Mod Entry point for LeviLauncher
extern "C" JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOGI("======================================");
    LOGI(" ChunkEX Mod Initialized Successfully ");
    LOGI(" Chunk Border Renderer Engine Ready   ");
    LOGI("======================================");
    
    // Example test call to verify calculation logic
    logChunkBorders(100.5, -250.3);
    
    return JNI_VERSION_1_6;
}
