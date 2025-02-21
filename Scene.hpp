#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "PhysicsWorld.hpp"

class Scene {
private:
	PhysicsWorld pw;
	bool firstDraw = true;
	std::vector<Object> objectsNow;
	std::vector<Object> objectsPrev;

public:
	Scene() {

	}

	void addSolver(Solver* solv) {
		pw.addSolver(solv);
	}

	void addCircle(const float& x, const float& y, sf::Color col, const double& mass) {
		sf::Shape* shape = new sf::CircleShape(50.f);
		shape->setFillColor(col);
		shape->setPosition({ x, y });

		Collider* coll = new SphereCollider(ColliderType::SPHERE, {x, y}, 50.0);
		Object obj{ {x, y}, {0, 0}, {0, 0}, coll, mass, shape};

		
		objectsNow.push_back(obj);
		pw.AddObject(&obj);
	}

	void draw(sf::RenderWindow& window, const float& time) {
		if (firstDraw) {
			for (Object obj : objectsNow) {
				if (SphereCollider* sp = dynamic_cast<SphereCollider*>(obj.Collider) ) {
					sf::CircleShape* csh = dynamic_cast<sf::CircleShape*>(obj.shape);
					window.draw(*csh);
					firstDraw = false;
				}
				else {
					PlaneCollider* pl = dynamic_cast<PlaneCollider*>(obj.Collider);
					//приведение shape к прямой
					//window.draw();
				}
				
			}
		}
		else {
			for (int i = 0; i < objectsNow.size(); i++) {
				if (i > objectsPrev.size() - 1) {
					objectsPrev.push_back(objectsNow[i]);
				}
				else {
					objectsPrev[i] = objectsNow[i];
				}
			}
			pw.resolveCollisions(time, objectsNow);
			pw.Step(time);
			
			for (int i = 0; i < objectsNow.size(); i++) {
				if (SphereCollider* sp = dynamic_cast<SphereCollider*>(objectsNow[i].Collider)) {
					sf::CircleShape* csh = dynamic_cast<sf::CircleShape*>(objectsNow[i].shape);
					sf::Vector2f vn = coordinateTransform(objectsNow[i].Position.x, objectsNow[i].Position.y, window.getSize().x, window.getSize().y, csh);
					sf::Vector2f vp = coordinateTransform(objectsPrev[i].Position.x, objectsPrev[i].Position.y, window.getSize().x, window.getSize().y, csh);
					csh->move(vp - vn);
				}
			}

		}
	}


	sf::Vector2f coordinateTransform(const double& w, const double& h, const unsigned int& weight, const unsigned int& height, sf::Shape* sh) {
		return { (float)(w + weight / 2) - sh->getGeometricCenter().x, (float)(h + height / 2) - sh->getGeometricCenter().y };
	}
};