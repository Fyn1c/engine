#pragma once
#include "Colliders.hpp"
#include "Object.hpp"
#include "Transform.hpp"
#include "TestCollision.hpp"

class Collision {
private:
    Object* obj1;
    Object* obj2;
    CollisionPoints* cp;

public:

    Collision(Object* obj1, Object* obj2) {
        this->obj1 = obj1;
        this->obj2 = obj2;
        CollisionPoints cp = TestCollision(this->obj1->Collider, {}, this->obj2->Collider, {});
        this->cp = &cp;
    }

    CollisionPoints* getCollisionPoints() {
        return this->cp;
    }
    Object* getObj1() {
        return this->obj1;
    }
    Object* getObj2() {
        return this->obj2;
    }
};