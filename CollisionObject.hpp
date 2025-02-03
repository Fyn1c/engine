#pragma once

#include "Collision.hpp"
#include "Colliders.hpp"
#include "Transform.hpp"
#include <functional>

class CollisionObject {
private:
    Transform* transform;
    Collider* collider;
    bool isTrigger;
    bool isDynamic;
    std::function<void(Collision&, float)> func;
public:

    void setTransform(Transform* tr) {
        this->transform = tr;
    }
    void setCollider(Collider* col) {
        this->collider = col;
    }

    void setIsTrigger(bool trigg) {
        this->isTrigger = trigg;
    }
    void setIsDynamic(bool dyn) {
        this->isDynamic = dyn;
    }
    void setFunction(std::function<void(Collision&, float)>& func) {
        this->func = func;
    }

    Transform* getTransform() {
        return transform;
    }
    Collider* getCollider() {
        return collider;
    }
    bool getIsTrigger() {
        return isTrigger;
    }
    bool getIsDynamic() {
        return isDynamic;
    }
    std::function<void(Collision&, float)> getFunction() {
        return func;
    }
};