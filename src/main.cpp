#include <pl/mod.hpp>

class ChunkEXMod {
public:
    static ChunkEXMod &instance() {
        static ChunkEXMod inst;
        return inst;
    }

    ChunkEXMod() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod &getSelf() const { return mSelf; }

    bool load() {
        getSelf().getLogger().info("ChunkEX Loaded successfully!");
        return true;
    }

    bool enable() {
        getSelf().getLogger().info("ChunkEX Enabled successfully!");
        return true;
    }

    bool disable() {
        return true;
    }

    bool unload() {
        return true;
    }

private:
    ll::mod::NativeMod &mSelf;
};

PL_REGISTER_MOD(ChunkEXMod, ChunkEXMod::instance())
