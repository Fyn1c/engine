#pragma once

#include "Transform.hpp"
#include "Colliders.hpp"
#include <utility>
#include <cmath>

//CollisionPoints Test_Sphere_Sphere(
//	Collider* a, const Transform* ta,
//	Collider* b, const Transform* tb);
// реализуйте эти функции
CollisionPoints Test_Sphere_Sphere(
	Collider* a, const Transform* ta,
	Collider* b, const Transform* tb) {

	SphereCollider* spc1{ dynamic_cast<SphereCollider*>(a) };
	SphereCollider* spc2{ dynamic_cast<SphereCollider*>(b) };

	spc1->Center += ta->Position;
	spc2->Center += tb->Position;

	double o1o2 = std::pow(std::pow(spc1->Center.x - spc2->Center.x, 2) + std::pow(spc1->Center.y - spc2->Center.y, 2), 0.5);
	if (o1o2 > spc1->Radius + spc2->Radius) {
		return { {}, {}, {}, NULL, false};
	}
	Vec2d veco1o2 = { spc2->Center.x - spc1->Center.x, spc2->Center.y - spc1->Center.y, o1o2};

	Vec2d o1A = { spc1->Radius / o1o2 * veco1o2.x, spc1->Radius / o1o2 * veco1o2.y };
	double o1B = o1o2 - spc2->Radius;
	Vec2d o2B = { o1B / o1o2 * veco1o2.x, o1B / o1o2 * veco1o2.y };

	Vec2d A = spc1->Center + o1A;
	Vec2d B = spc2->Center + o2B;
	

	double lenght = o1o2 - spc1->Radius - spc2->Radius;

	return { A, B, B - A, lenght, true};
}

CollisionPoints Test_Sphere_Plane(
	Collider* a, const Transform* ta,
	Collider* b, const Transform* tb)
{

	SphereCollider* spc1{ dynamic_cast<SphereCollider*>(a) };
	PlaneCollider* spc2{ dynamic_cast<PlaneCollider*>(b) };

	Vec2d vecOnPlane = spc2->Normal * spc2->Distance;

	double numenator = std::abs(spc2->Normal.x*spc1->Center.x + spc2->Normal.y* spc1->Center.y - (spc2->Normal.x * vecOnPlane.x + spc2->Normal.y * vecOnPlane.y));
	double denominator = std::pow(std::pow(spc2->Normal.x, 2) +  std::pow(spc2->Normal.y, 2), 0.5);

	double distanceToPlane = numenator / denominator;

	Vec2d OB = distanceToPlane * (-spc2->Normal);
	Vec2d B = spc1->Center + OB;

	Vec2d OA = (OB / OB.getLenght()) * spc1->Radius;
	Vec2d A = spc1->Center + OA;


	return { A, B, B - A, (OA - OB).lenght, true };

}

using FindContactFunc = CollisionPoints(*)(
	Collider*, const Transform*,
	Collider*, const Transform*);

CollisionPoints TestCollision(
	Collider* a, const Transform* at,
	Collider* b, const Transform* bt)
{
	static const FindContactFunc tests[2][2] =
	{
		// Sphere             Plane
		{ Test_Sphere_Sphere, Test_Sphere_Plane }, // Sphere
		{ nullptr,            nullptr           }  // Plane
	};

	// If we are passed a Plane vs Sphere, swap the 
	// colliders so it's a Sphere vs Plane
	bool swap = b->Type > a->Type;

	if (swap)
	{
		std::swap(a, b);
		std::swap(at, bt);
	}

	// now we can dispatch the correct function
	CollisionPoints points = tests[a->Type][b->Type](a, at, b, bt);

	// if we swapped the order of the colliders, to keep the
	// results consistent, we need to swap the points
	if (swap)
	{
		std::swap(points.A, points.B);
		points.Normal = -points.Normal;
	}

	return points;
}