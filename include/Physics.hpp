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

#ifndef RAYLIB_CPP_INCLUDE_PHYSICS_HPP_
#define RAYLIB_CPP_INCLUDE_PHYSICS_HPP_

#include "./raylib.hpp"

#ifdef __cplusplus
extern "C" {
#endif
#include "physac.h" // NOLINT
#ifdef __cplusplus
}
#endif

#include "./Vector2.hpp"

namespace raylib {
class Physics {
 public:
    Physics() {
        Init();
    }

    Physics(float gravityY) {
        Init();
        SetGravity(0, gravityY);
    }

    Physics(float gravityX, float gravityY) {
        Init();
        SetGravity(gravityX, gravityY);
    }

    ~Physics() {
        Close();
    }

    inline Physics& Init() {
        ::InitPhysics();
        return *this;
    }

    inline Physics& Close() {
        ::ClosePhysics();
        return *this;
    }

    inline Physics& RunStep() {
        ::RunPhysicsStep();
        return *this;
    }

    inline Physics& SetTimeStep(double delta) {
        ::SetPhysicsTimeStep(delta);
        return *this;
    }

    inline bool IsEnabled() const {
        return ::IsPhysicsEnabled();
    }

    inline Physics& SetGravity(float x, float y) {
        ::SetPhysicsGravity(x, y);
        return *this;
    }

    inline PhysicsBody CreateBodyCircle(Vector2 pos, float radius, float density) {
        return ::CreatePhysicsBodyCircle(pos, radius, density);
    }

    inline PhysicsBody CreateBodyRectangle(Vector2 pos, float width, float height, float density) {
        return ::CreatePhysicsBodyRectangle(pos, width, height, density);
    }

    inline PhysicsBody CreateBodyPolygon(Vector2 pos, float radius, int sides, float density) {
        return ::CreatePhysicsBodyPolygon(pos, radius, sides, density);
    }

    inline Physics& AddForce(PhysicsBody body, Vector2 force) {
        ::PhysicsAddForce(body, force);
        return *this;
    }

    inline Physics& AddTorque(PhysicsBody body, float amount) {
        ::PhysicsAddTorque(body, amount);
        return *this;
    }

    inline Physics& Shatter(PhysicsBody body, Vector2 position, float force) {
        ::PhysicsShatter(body, position, force);
        return *this;
    }

    inline int GetBodiesCount() const {
        return ::GetPhysicsBodiesCount();
    }

    inline PhysicsBody GetBody(int index) const {
        return ::GetPhysicsBody(index);
    }

    inline int GetShapeType(int index) const {
        return ::GetPhysicsShapeType(index);
    }

    inline int GetShapeVerticesCount(int index) const {
        return ::GetPhysicsShapeVerticesCount(index);
    }

    inline Vector2 GetShapeVertex(PhysicsBody body, int vertex) const {
        return ::GetPhysicsShapeVertex(body, vertex);
    }

    inline Physics& SetBodyRotation(PhysicsBody body, float radians) {
        ::SetPhysicsBodyRotation(body, radians);
        return *this;
    }

    inline Physics& DestroyBody(PhysicsBody body) {
        ::DestroyPhysicsBody(body);
        return *this;
    }

    inline Physics& Reset() {
        ::ResetPhysics();
        return *this;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_PHYSICS_HPP_
