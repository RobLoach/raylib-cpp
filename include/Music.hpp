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
    Music(::Music music) {
        set(music);
    }

    Music(const std::string& fileName) {
        set(::LoadMusicStream(fileName.c_str()));
    }

    ~Music() {
        Unload();
    }

    GETTERSETTER(int, CtxType, ctxType)
    GETTERSETTER(bool, Looping, looping)
    GETTERSETTER(unsigned int, SampleCount, sampleCount)

    Music& operator=(const ::Music& music) {
        set(music);
        return *this;
    }

    Music& operator=(const Music& music) {
        set(music);
        return *this;
    }

    inline void Unload() {
        ::UnloadMusicStream(*this);
    }

    inline Music& Play() {
        ::PlayMusicStream(*this);
        return *this;
    }

    inline Music& Update() {
        ::UpdateMusicStream(*this);
        return *this;
    }

    inline Music& Stop() {
        ::StopMusicStream(*this);
        return *this;
    }

    inline Music& Pause() {
        ::PauseMusicStream(*this);
        return *this;
    }

    inline Music& Resume() {
        ::ResumeMusicStream(*this);
        return *this;
    }

    inline bool IsPlaying() const {
        return ::IsMusicPlaying(*this);
    }

    inline Music& SetVolume(float volume) {
        ::SetMusicVolume(*this, volume);
        return *this;
    }

    inline Music& SetPitch(float pitch) {
        ::SetMusicPitch(*this, pitch);
        return *this;
    }

    inline float GetTimeLength() const {
        return ::GetMusicTimeLength(*this);
    }

    inline float GetTimePlayed() const {
        return ::GetMusicTimePlayed(*this);
    }

 protected:
    inline void set(::Music music) {
        ctxType = music.ctxType;
        ctxData = music.ctxData;
        looping = music.looping;
        sampleCount = music.sampleCount;
        stream = music.stream;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_MUSIC_HPP_
