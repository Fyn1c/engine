#pragma once
#include "Vec2d.hpp"
#include <iostream>

enum ColliderType {
	SPHERE,
	PLANE
};

struct Collider {
	ColliderType Type;
	virtual void f() = 0;
};

struct SphereCollider : Collider {

	SphereCollider(const ColliderType type, const Vec2d cent, double rad) {
		this->Type = type;
		this->Center = cent;
		this->Radius = rad;
	}

	void f() override {
		std::cout << "sphere" << std::endl;
	}
	Vec2d Center;
	double Radius;
};

struct PlaneCollider : Collider {

	
	void f() override {
		std::cout << "plane" << std::endl;
	}
	Vec2d Normal;
	Vec2d point; //point of 
	double Distance;
};