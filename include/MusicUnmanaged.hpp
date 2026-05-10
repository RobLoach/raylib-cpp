#ifndef RAYLIB_CPP_INCLUDE_MUSICUNMANAGED_HPP_
#define RAYLIB_CPP_INCLUDE_MUSICUNMANAGED_HPP_

#include <string>

#include "./RaylibException.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raylib.hpp"

namespace raylib {
/**
 * A Music stream that is not managed by C++ RAII.
 *
 * Make sure to Unload() this if needed, otherwise use raylib::Music.
 *
 * @see raylib::Music
 */
class MusicUnmanaged : public ::Music {
public:
    /**
     * Creates a MusicUnmanaged with the given components.
     */
    MusicUnmanaged(
        ::AudioStream stream = {nullptr, nullptr, 0, 0, 0},
        unsigned int frameCount = 0,
        bool looping = false,
        int ctxType = 0,
        void* ctxData = nullptr)
        : ::Music{stream, frameCount, looping, ctxType, ctxData} {}

    /**
     * Creates a MusicUnmanaged from an existing Music struct.
     */
    MusicUnmanaged(const ::Music& music) : ::Music(music) {}

    /**
     * Load music stream from file.
     *
     * @throws raylib::RaylibException Throws if the music failed to load.
     */
    MusicUnmanaged(const std::string& fileName) { Load(fileName); }

    /**
     * Load music stream from memory.
     *
     * @throws raylib::RaylibException Throws if the music failed to load.
     */
    MusicUnmanaged(const std::string& fileType, unsigned char* data, int dataSize) {
        Load(fileType, data, dataSize);
    }

    GETTER(::AudioStream, Stream, stream)
    GETTER(unsigned int, FrameCount, frameCount)
    GETTERSETTER(bool, Looping, looping)
    GETTER(int, CtxType, ctxType)
    GETTER(void*, CtxData, ctxData)

    MusicUnmanaged& operator=(const ::Music& music) {
        set(music);
        return *this;
    }

    /**
     * Load music stream from file.
     *
     * @throws raylib::RaylibException Throws if the music failed to load.
     */
    void Load(const std::string& fileName) {
        set(::LoadMusicStream(fileName.c_str()));
        if (!IsValid()) {
            throw RaylibException(TextFormat("Failed to load Music from file: %s", fileName.c_str()));
        }
    }

    /**
     * Load music stream from memory.
     *
     * @throws raylib::RaylibException Throws if the music failed to load.
     */
    void Load(const std::string& fileType, unsigned char* data, int dataSize) {
        set(::LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize));
        if (!IsValid()) {
            throw RaylibException(TextFormat("Failed to load Music from %s file data", fileType.c_str()));
        }
    }

    /**
     * Unload music stream.
     */
    void Unload() {
        if (IsValid()) {
            ::UnloadMusicStream(*this);
            ctxData = nullptr;
            ctxType = 0;
        }
    }

    /**
     * Start music playing.
     */
    MusicUnmanaged& Play() {
        ::PlayMusicStream(*this);
        return *this;
    }

    /**
     * Updates buffers for music streaming.
     */
    MusicUnmanaged& Update() {
        ::UpdateMusicStream(*this);
        return *this;
    }

    /**
     * Stop music playing.
     */
    MusicUnmanaged& Stop() {
        ::StopMusicStream(*this);
        return *this;
    }

    /**
     * Pause music playing.
     */
    MusicUnmanaged& Pause() {
        ::PauseMusicStream(*this);
        return *this;
    }

    /**
     * Resume music playing.
     */
    MusicUnmanaged& Resume() {
        ::ResumeMusicStream(*this);
        return *this;
    }

    /**
     * Seek music to a position (in seconds).
     */
    MusicUnmanaged& Seek(float position) {
        ::SeekMusicStream(*this, position);
        return *this;
    }

    /**
     * Check if music is playing.
     */
    RLCPP_NODISCARD bool IsPlaying() const { return ::IsMusicStreamPlaying(*this); }

    /**
     * Set volume for music.
     */
    MusicUnmanaged& SetVolume(float volume) {
        ::SetMusicVolume(*this, volume);
        return *this;
    }

    /**
     * Set pitch for music.
     */
    MusicUnmanaged& SetPitch(float pitch) {
        ::SetMusicPitch(*this, pitch);
        return *this;
    }

    /**
     * Set pan for a music (0.5 is center).
     */
    MusicUnmanaged& SetPan(float pan = 0.5f) {
        ::SetMusicPan(*this, pan);
        return *this;
    }

    /**
     * Get music time length (in seconds).
     */
    RLCPP_NODISCARD float GetTimeLength() const { return ::GetMusicTimeLength(*this); }

    /**
     * Get current music time played (in seconds).
     */
    RLCPP_NODISCARD float GetTimePlayed() const { return ::GetMusicTimePlayed(*this); }

    /**
     * Retrieve whether or not the Music has been loaded.
     *
     * @return True or false depending on whether the Music has been loaded.
     */
    RLCPP_NODISCARD bool IsValid() const { return ::IsMusicValid(*this); }

protected:
    void set(const ::Music& music) {
        stream = music.stream;
        frameCount = music.frameCount;
        looping = music.looping;
        ctxType = music.ctxType;
        ctxData = music.ctxData;
    }
};
} // namespace raylib

using RMusicUnmanaged = raylib::MusicUnmanaged;

#endif // RAYLIB_CPP_INCLUDE_MUSICUNMANAGED_HPP_
