#ifndef RAYLIB_CPP_INCLUDE_PHYSICS_HPP_
#define RAYLIB_CPP_INCLUDE_PHYSICS_HPP_

#include "./raylib.hpp"
#include "./physac.hpp"
#include "./Vector2.hpp"

namespace raylib {
/**
 * 2D Physics library for videogames
 */
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

    inline Physics& UpdateStep() {
        ::UpdatePhysicsStep();
        return *this;
    }

    inline Physics& SetTimeStep(double delta) {
        ::SetPhysicsTimeStep(delta);
        return *this;
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
