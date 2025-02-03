#pragma once
#include "Vec2d.hpp"

struct CollisionPoints {
	Vec2d A; // Furthest point of A into B
	Vec2d B; // Furthest point of B into A
	Vec2d Normal; // B – A normalized
	double Depth;    // Length of B – A
	bool HasCollision;
};

struct Transform { // Describes an objects location
	Vec2d Position;
	Vec2d Scale;
	// Quaternion Rotation;
	Transform(const Vec2d& pos, const Vec2d& sc) {
		this->Position = pos;
		this->Scale = sc;
	}
	Transform() {
		this->Position = { 1, 0 };
		this->Scale = { 0, 0 };
	}
};