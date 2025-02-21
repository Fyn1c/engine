#include <SFML/Graphics.hpp>
#include "PhysicsWorld.hpp"
#include "Scene.hpp"
#include "DefaultSolver.hpp"
#include <chrono>
#include <iostream>


sf::Vector2f coordinateTransform(const double& w, const double& h, const unsigned int& weight, const unsigned int& height, sf::Shape* sh);

int main()
{

    unsigned int width = 800;
    unsigned int height = 800;
    sf::RenderWindow window(sf::VideoMode({ width, height }), "SFML works!");


    //sf::CircleShape shape(50.f);
    //// set the shape color to green
    //shape.setFillColor(sf::Color(100, 250, 50));

    
    /*PhysicsWorld pw;*/
    /*Vec2d pos{ 0, 0 };*/
   /* Collider* coll = new SphereCollider(ColliderType::SPHERE, pos, 50.0);*/

    /*Object obj{ pos, {0, 0}, {0, 0}, coll, 50};

    pw.AddObject(&obj);
    
    shape.setPosition(coordinateTransform(obj.Position.x, obj.Position.y, height, width, &shape));*/

    /*Vec2d prevcord{ obj.Position.x, obj.Position.y };*/


    Scene scene;
    scene.addSolver(new DefaultSolver());


    while (window.isOpen())
    {
        auto time = std::chrono::high_resolution_clock::now();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }

            // Clear screen
            window.clear();

            typedef std::chrono::duration<float> fsec;
            fsec fs = std::chrono::high_resolution_clock::now() - time;

            scene.draw(window, fs.count());
            

            /*shape.setPosition({(float) obj->Position.x, (float) obj->Position.y});*/

            //sf::Vector2f vn = coordinateTransform(obj.Position.x, obj.Position.y, width, height, &shape);
            //sf::Vector2f vp = coordinateTransform(prevcord.x, prevcord.y, width, height, &shape);
            //shape.move(vp - vn);

            //window.draw(shape);

            //shape.move({0.0f, -1.0f});
            // Update the window


            window.display();

        }

        /* Rest of the main loop*/
    }

    return 0;
}


sf::Vector2f coordinateTransform(const double& w, const double& h, const unsigned int& weight, const unsigned int& height, sf::Shape* sh) {
    return {(float) (w + weight /2) - sh->getGeometricCenter().x, (float)(h + height / 2) - sh->getGeometricCenter().y };
}