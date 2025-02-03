#pragma once
#include "CollisionObject.hpp"

class RigidBody : public CollisionObject {

public:
	Vec2d gravity;
	Vec2d force;
	Vec2d Velocity;
	double Mass;
	Vec2d staticFriction;
	Vec2d dynamicFriction;
	Vec2d restitution;
	bool takesGravity;

};