#include <preloader/mod.h>
#include <preloader/log.h>
#include <android/log.h>
#include <cmath>

#define LOG_TAG "ChunkEX"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class ChunkEXMod {
public:
    static ChunkEXMod& instance() {
        static ChunkEXMod inst;
        return inst;
    }

    ChunkEXMod() : mSelf(*ll::mod::NativeMod::current()) {}

    ll::mod::NativeMod& getSelf() const { return mSelf; }

    bool load() {
        LOGI("[ChunkEX] Lifecycle Phase: LOAD");
        return true;
    }

    bool enable() {
        LOGI("[ChunkEX] Lifecycle Phase: ENABLE");
        LOGI("======================================");
        LOGI(" ChunkEX Mod Enabled & Hooks Active   ");
        LOGI("======================================");
        return true;
    }

    bool disable() {
        LOGI("[ChunkEX] Lifecycle Phase: DISABLE");
        return true;
    }

    bool unload() {
        LOGI("[ChunkEX] Lifecycle Phase: UNLOAD");
        return true;
    }

private:
    ll::mod::NativeMod& mSelf;
};

// Register mod instance with LeviLauncher preloader
PL_REGISTER_MOD(ChunkEXMod, ChunkEXMod::instance())
