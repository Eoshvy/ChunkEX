#include <preloader/mod.h>
#include <android/log.h>

#define LOG_TAG "ChunkEX"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class ChunkEXMod {
public:
    static ChunkEXMod& instance() {
        static ChunkEXMod inst;
        return inst;
    }

    ChunkEXMod() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod& getSelf() const { return mSelf; }

    bool load() {
        LOGI("[ChunkEX] Lifecycle: LOAD");
        return true;
    }

    bool enable() {
        LOGI("[ChunkEX] Lifecycle: ENABLE - ChunkEX Ready");
        return true;
    }

    bool disable() {
        LOGI("[ChunkEX] Lifecycle: DISABLE");
        return true;
    }

    bool unload() {
        LOGI("[ChunkEX] Lifecycle: UNLOAD");
        return true;
    }

private:
    ll::mod::NativeMod& mSelf;
};

// Register mod instance with LeviLauncher
PL_REGISTER_MOD(ChunkEXMod, ChunkEXMod::instance())
