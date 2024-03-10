#ifndef RAYLIB_CPP_INCLUDE_MUSIC_HPP_
#define RAYLIB_CPP_INCLUDE_MUSIC_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./RaylibException.hpp"

namespace raylib {
/**
 * Music stream type (audio file streaming from memory)
 */
class Music : public ::Music {
 public:
    Music(::AudioStream stream = {nullptr, nullptr, 0, 0, 0},
            unsigned int frameCount = 0,
            bool looping = false,
            int ctxType = 0,
            void *ctxData = nullptr) : ::Music{stream, frameCount, looping, ctxType, ctxData} {}

    Music(const ::Music& music) {
        set(music);
    }

    /**
     * Load music stream from file
     *
     * @throws raylib::RaylibException Throws if the music failed to load.
     */
    Music(const std::string& fileName) {
        Load(fileName);
    }

    /**
     * Load music stream from memory
     *
     * @throws raylib::RaylibException Throws if the music failed to load.
     */
    Music(const std::string& fileType, unsigned char* data, int dataSize) {
        Load(fileType, data, dataSize);
    }

    Music(const Music&) = delete;

    Music(Music&& other) {
        set(other);

        other.stream = {};
        other.frameCount = 0;
        other.looping = false;
        other.ctxType = 0;
        other.ctxData = nullptr;
    }

    /**
     * Unload music stream
     */
    ~Music() {
        Unload();
    }

    GETTER(::AudioStream, Stream, stream)
    GETTER(unsigned int, FrameCount, frameCount)
    GETTERSETTER(bool, Looping, looping)
    GETTER(int, CtxType, ctxType)
    GETTER(void*, CtxData, ctxData)

    Music& operator=(const ::Music& music) {
        set(music);
        return *this;
    }

    Music& operator=(const Music&) = delete;

    Music& operator=(Music&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        Unload();
        set(other);

        other.ctxType = 0;
        other.ctxData = nullptr;
        other.looping = false;
        other.frameCount = 0;
        other.stream = {};

        return *this;
    }

    /**
     * Unload music stream
     */
    void Unload() {
        ::UnloadMusicStream(*this);
    }

    /**
     * Start music playing
     */
    Music& Play() {
        ::PlayMusicStream(*this);
        return *this;
    }

    /**
     * Updates buffers for music streaming
     */
    Music& Update() {
        ::UpdateMusicStream(*this);
        return *this;
    }

    /**
     * Stop music playing
     */
    Music& Stop() {
        ::StopMusicStream(*this);
        return *this;
    }

    /**
     * Pause music playing
     */
    Music& Pause() {
        ::PauseMusicStream(*this);
        return *this;
    }

    /**
     * Resume music playing
     */
    Music& Resume() {
        ::ResumeMusicStream(*this);
        return *this;
    }

    /**
     * Seek music to a position (in seconds)
     */
    Music& Seek(float position) {
        SeekMusicStream(*this, position);
        return *this;
    }

    /**
     * Check if music is playing
     */
    bool IsPlaying() const {
        return ::IsMusicStreamPlaying(*this);
    }

    /**
     * Set volume for music
     */
    Music& SetVolume(float volume) {
        ::SetMusicVolume(*this, volume);
        return *this;
    }

    /**
     * Set pitch for music
     */
    Music& SetPitch(float pitch) {
        ::SetMusicPitch(*this, pitch);
        return *this;
    }

    /**
     * Set pan for a music (0.5 is center)
     */
    Music& SetPan(float pan = 0.5f) {
        ::SetMusicPan(*this, pan);
        return *this;
    }

    /**
     * Get music time length (in seconds)
     */
    float GetTimeLength() const {
        return ::GetMusicTimeLength(*this);
    }

    /**
     * Get current music time played (in seconds)
     */
    float GetTimePlayed() const {
        return ::GetMusicTimePlayed(*this);
    }

    /**
     * Load music stream from file
     *
     * @throws raylib::RaylibException Throws if the music failed to load.
     */
    void Load(const std::string& fileName) {
        set(::LoadMusicStream(fileName.c_str()));
        if (!IsReady()) {
            throw RaylibException(TextFormat("Failed to load Music from file: %s", fileName.c_str()));
        }
    }

    /**
     * Load music stream from memory
     *
     * @throws raylib::RaylibException Throws if the music failed to load.
     */
    void Load(const std::string& fileType, unsigned char* data, int dataSize) {
        set(::LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize));
        if (!IsReady()) {
            throw RaylibException(TextFormat("Failed to load Music from %s file dat", fileType.c_str()));
        }
    }

    /**
     * Retrieve whether or not the Music has been loaded.
     *
     * @return True or false depending on whether the Music has been loaded.
     */
    bool IsReady() const {
        return ::IsMusicReady(*this);
    }

 protected:
    void set(const ::Music& music) {
        stream = music.stream;
        frameCount = music.frameCount;
        looping = music.looping;
        ctxType = music.ctxType;
        ctxData = music.ctxData;
    }
};
}  // namespace raylib

using RMusic = raylib::Music;

#endif  // RAYLIB_CPP_INCLUDE_MUSIC_HPP_
