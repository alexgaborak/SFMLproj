#include <SFML/Graphics.hpp>

#include "space_object.h"
#include "control.h"
#include "bullet.h"

Control::Control(
    SpaceObject &spaceObject, 
    sf::RenderWindow &renderWindow): 
       m_spaceObject(spaceObject), 
       m_renderWindow(renderWindow) {
    
}

void Control::update(sf::Event& event, std::vector<SpaceObject*>& objects){

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::A) {
            m_spaceObject.m_rotVel = 2;
        }
        if (event.key.code == sf::Keyboard::D) {
            m_spaceObject.m_rotVel = -2;
        }
        if (event.key.code == sf::Keyboard::W) {
            m_spaceObject.m_linAcc = 30;
        }
        if (event.key.code == sf::Keyboard::S) {
            m_spaceObject.m_linAcc = -30;
        }
        if (event.key.code == sf::Keyboard::Space) {
            float bulletVelocityMagnitude = 100.0 + 50.0 * (rand()/(double)RAND_MAX);
            // // bulletVelocityMagnitude * m_spaceObject.m_dir
            sf::Vector2f bulletDir = bulletVelocityMagnitude * m_spaceObject.m_dir;
            sf::Vector2f spavnDir = (float)(50.0) * m_spaceObject.m_dir;
            Bullet* bullet = new Bullet( spavnDir + m_spaceObject.m_pos, bulletDir, 5.0 );
            objects.push_back(bullet);
        }
    }

    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::A) {
            m_spaceObject.m_rotVel = 0;
        }
        if (event.key.code == sf::Keyboard::D) {
            m_spaceObject.m_rotVel = 0;
        }
        if (event.key.code == sf::Keyboard::W) {
            m_spaceObject.m_linAcc = 0;
        }
        if (event.key.code == sf::Keyboard::S) {
            m_spaceObject.m_linAcc = 0;
        }
    }

}