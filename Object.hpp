#pragma once
#include "Vec2d.hpp"
#include "Colliders.hpp"

struct Object {
	Vec2d Position; // struct with 3 floats for x, y, z or i + j + k
	Vec2d Velocity;
	Vec2d Force;
	Collider* Collider;
	double Mass;
};