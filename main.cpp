#include <SFML/Graphics.hpp>
#include <vector>

#include "space_object.h"
#include "ship.h"
#include "asteroid.h"
#include "control.h"
#include "rules.h"

int main(){

    sf::Clock clock;
    sf::Time deltaTime;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Asteroids");

    Ship* ship = new Ship( sf::Vector2f(window.getSize().x/2, window.getSize().y/2), 0 );
    std::vector<SpaceObject*> sceneObjects;
    sceneObjects.push_back(ship);

    Control control(*ship, window);

    sceneObjects.push_back(new Asteroid( sf::Vector2f(300, 400), sf::Vector2f(3, 1), 30.0));
    sceneObjects.push_back(new Asteroid( sf::Vector2f(100, 150), sf::Vector2f(3, 1), 30.0));
    sceneObjects.push_back(new Asteroid( sf::Vector2f(50, 200), sf::Vector2f(3, 1), 30.0));
    sceneObjects.push_back(new Asteroid( sf::Vector2f(500, 100), sf::Vector2f(3, 1), 30.0));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Q) {
                    window.close();
                }
            }
            control.update(event, sceneObjects);
        }

        deltaTime = clock.restart();

        window.clear(sf::Color::Black);

        Rules::positionCheck(sceneObjects, window);
        Rules::checkCollision(sceneObjects);
        Rules::checkLifeTime(sceneObjects);

        for( auto obj: sceneObjects ){
            obj->update(deltaTime.asSeconds());
            obj->draw(window);
        }

        window.display();
    }

    return 0;
}