/*
*   LICENSE: zlib/libpng
*
*   raylib-cpp is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software:
*
*   Copyright (c) 2020 Rob Loach (@RobLoach)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*/

#ifndef RAYLIB_CPP_INCLUDE_MUSIC_HPP_
#define RAYLIB_CPP_INCLUDE_MUSIC_HPP_

#include <string>

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
class Music : public ::Music {
 public:
    Music(const ::Music& music) {
        set(music);
    }

    /**
     * Load music stream from file
     */
    Music(const std::string& fileName) {
        set(::LoadMusicStream(fileName.c_str()));
    }

    /**
     * Unload music stream
     */
    ~Music() {
        Unload();
    }

    GETTERSETTER(::AudioStream, Stream, stream)
    GETTERSETTER(unsigned int, SampleCount, sampleCount)
    GETTERSETTER(bool, Looping, looping)
    GETTERSETTER(int, CtxType, ctxType)
    GETTERSETTER(void*, CtxData, ctxData)

    Music& operator=(const ::Music& music) {
        set(music);
        return *this;
    }

    Music& operator=(const Music& music) {
        set(music);
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
     * Check if music is playing
     */
    inline bool IsPlaying() const {
        return ::IsMusicPlaying(*this);
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

 protected:
    inline void set(const ::Music& music) {
        ctxType = music.ctxType;
        ctxData = music.ctxData;
        looping = music.looping;
        sampleCount = music.sampleCount;
        stream = music.stream;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MUSIC_HPP_
