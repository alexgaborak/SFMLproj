#include <SFML/Graphics.hpp>
#include <cmath>

#include "space_object.h"
#include "ship.h"

Ship::Ship(sf::Vector2f pos, float rot): SpaceObject(pos, rot){
    m_shape = sf::VertexArray(sf::Lines, 6);
    m_shape[0].position = sf::Vector2f(0, 20);
    m_shape[1].position = sf::Vector2f(-10, -5);
    m_shape[2].position = sf::Vector2f(-10, -5);
    m_shape[3].position = sf::Vector2f(10, -5);
    m_shape[4].position = sf::Vector2f(10, -5);
    m_shape[5].position = sf::Vector2f(0, 20);

    for(int i = 0; i < m_shape.getVertexCount(); ++i){
        m_shape[i].color = sf::Color::Green;
    }

    m_normalShape = m_shape;

    m_fire = sf::VertexArray(sf::Lines, 6);
    m_fire[0].position = sf::Vector2f(0, -40);
    m_fire[1].position = sf::Vector2f(-8, -5);
    m_fire[2].position = sf::Vector2f(-8, -5);
    m_fire[3].position = sf::Vector2f(8, -5);
    m_fire[4].position = sf::Vector2f(8, -5);
    m_fire[5].position = sf::Vector2f(0, -40);

    for(int i = 0; i < m_fire.getVertexCount(); ++i){
        m_fire[i].color = sf::Color::Red;
    }

    m_normalFire = m_fire;
}

void Ship::update(float dt){
    m_rot += m_rotVel * dt;

    m_dir.x = sin(m_rot);
    m_dir.y = cos(m_rot);

    m_vel.x += m_dir.x * m_linAcc * dt;
    m_vel.y += m_dir.y * m_linAcc * dt;

    m_pos.x += m_vel.x * dt;
    m_pos.y += m_vel.y * dt;

    m_shape = m_normalShape;

    for(int i = 0 ; i < m_shape.getVertexCount(); ++i){
        float oldX = m_shape[i].position.x;
        float oldY = m_shape[i].position.y;

        float rotatedX = oldX * cos(m_rot) + oldY * sin(m_rot);
        float rotatedY = -oldX * sin(m_rot) + oldY * cos(m_rot);

        m_shape[i].position.x = rotatedX + m_pos.x;
        m_shape[i].position.y = rotatedY + m_pos.y;
    }

    if(m_linAcc > 0.1){
        m_normalFire[0].position.y = -5 - 20 * (rand()/ (double)RAND_MAX);
        m_normalFire[5].position.y = -5 - 20 * (rand()/ (double)RAND_MAX);
    }else{
        m_normalFire[0].position.y = -5;
        m_normalFire[5].position.y = -5;      
    }

    m_fire = m_normalFire;

    for(int i = 0 ; i < m_fire.getVertexCount(); ++i){
        float oldX = m_fire[i].position.x;
        float oldY = m_fire[i].position.y;

        float rotatedX = oldX * cos(m_rot) + oldY * sin(m_rot);
        float rotatedY = -oldX * sin(m_rot) + oldY * cos(m_rot);

        m_fire[i].position.x = rotatedX + m_pos.x;
        m_fire[i].position.y = rotatedY + m_pos.y;
    }

}

void Ship::draw(sf::RenderWindow& renderWindow){
    renderWindow.draw(m_fire);
    renderWindow.draw(m_shape);
}