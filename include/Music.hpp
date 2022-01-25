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
    /**
     * Default Music constructor to build an empty Music object.
     */
    Music() {
        ctxType = 0;
        ctxData = nullptr;
        looping = false;
        frameCount = 0;
        stream.buffer = nullptr;
    }

    Music(const ::Music& music) {
        set(music);
    }

    /**
     * Load music stream from file
     *
     * @throws raylib::RaylibException Throws if the music failed to load.
     */
    Music(const std::string& fileName) {
        if (!Load(fileName)) {
            throw RaylibException(TextFormat("Failed to load Music from file: %s", fileName.c_str()));
        }
    }

    /**
     * Load music stream from memory
     *
     * @throws raylib::RaylibException Throws if the music failed to load.
     */
    Music(const std::string& fileType, unsigned char* data, int dataSize) {
        if (!Load(fileType, data, dataSize)) {
            throw RaylibException(TextFormat("Failed to load Music from %s file", fileType.c_str()));
        }
    }

    Music(const Music&) = delete;

    Music(Music&& other) {
        set(other);

        other.ctxType = 0;
        other.ctxData = nullptr;
        other.looping = false;
        other.frameCount = 0;
        other.stream = {};
    }

    /**
     * Unload music stream
     */
    ~Music() {
        Unload();
    }

    GETTERSETTER(::AudioStream, Stream, stream)
    GETTERSETTER(unsigned int, FrameCount, frameCount)
    GETTERSETTER(bool, Looping, looping)
    GETTERSETTER(int, CtxType, ctxType)
    GETTERSETTER(void*, CtxData, ctxData)

    Music& operator=(const ::Music& music) {
        set(music);
        return *this;
    }

    Music& operator=(const Music&) = delete;

    Music& operator=(Music&& other) {
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
    inline void Unload() {
        ::UnloadMusicStream(*this);
    }

    /**
     * Start music playing
     */
    inline Music& Play() {
        ::PlayMusicStream(*this);
        return *this;
    }

    /**
     * Updates buffers for music streaming
     */
    inline Music& Update() {
        ::UpdateMusicStream(*this);
        return *this;
    }

    /**
     * Stop music playing
     */
    inline Music& Stop() {
        ::StopMusicStream(*this);
        return *this;
    }

    /**
     * Pause music playing
     */
    inline Music& Pause() {
        ::PauseMusicStream(*this);
        return *this;
    }

    /**
     * Resume music playing
     */
    inline Music& Resume() {
        ::ResumeMusicStream(*this);
        return *this;
    }

    /**
     * Seek music to a position (in seconds)
     */
    inline Music& Seek(float position) {
        SeekMusicStream(*this, position);
        return *this;
    }

    /**
     * Check if music is playing
     */
    inline bool IsPlaying() const {
        return ::IsMusicStreamPlaying(*this);
    }

    /**
     * Set volume for music
     */
    inline Music& SetVolume(float volume) {
        ::SetMusicVolume(*this, volume);
        return *this;
    }

    /**
     * Set pitch for music
     */
    inline Music& SetPitch(float pitch) {
        ::SetMusicPitch(*this, pitch);
        return *this;
    }

    /**
     * Get music time length (in seconds)
     */
    inline float GetTimeLength() const {
        return ::GetMusicTimeLength(*this);
    }

    /**
     * Get current music time played (in seconds)
     */
    inline float GetTimePlayed() const {
        return ::GetMusicTimePlayed(*this);
    }

    /**
     * Load music stream from file
     */
    bool Load(const std::string& fileName) {
        set(::LoadMusicStream(fileName.c_str()));
        return IsReady();
    }

    /**
     * Load music stream from memory
     */
    bool Load(const std::string& fileType, unsigned char* data, int dataSize) {
        set(::LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize));
        return IsReady();
    }

    /**
     * Retrieve whether or not the Music has been loaded.
     *
     * @return True or false depending on whether the Music has been loaded.
     */
    inline bool IsReady() const {
        return stream.buffer != nullptr;
    }

 private:
    inline void set(const ::Music& music) {
        ctxType = music.ctxType;
        ctxData = music.ctxData;
        looping = music.looping;
        frameCount = music.frameCount;
        stream = music.stream;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MUSIC_HPP_
