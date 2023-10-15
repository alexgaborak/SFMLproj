#include <SFML/Graphics.hpp>
#include <cmath>

#include "space_object.h"
#include "bullet.h"

#define BULLET_SIZE 5


Bullet::Bullet(sf::Vector2f pos, sf::Vector2f vel, float lifeTime): 
    SpaceObject(true, pos, vel, 0, 5.0 * (rand()/ (double)RAND_MAX - 0.5) ), m_lifeTime(lifeTime){

    m_shape = sf::VertexArray(sf::Lines, 8);
    m_shape[0].position = sf::Vector2f(-BULLET_SIZE, BULLET_SIZE);
    m_shape[1].position = sf::Vector2f(-BULLET_SIZE, -BULLET_SIZE);
    m_shape[2].position = sf::Vector2f(-BULLET_SIZE, -BULLET_SIZE);
    m_shape[3].position = sf::Vector2f(BULLET_SIZE, -BULLET_SIZE);
    m_shape[4].position = sf::Vector2f(BULLET_SIZE, -BULLET_SIZE);
    m_shape[5].position = sf::Vector2f(BULLET_SIZE, BULLET_SIZE);
    m_shape[6].position = sf::Vector2f(BULLET_SIZE, BULLET_SIZE);
    m_shape[7].position = sf::Vector2f(-BULLET_SIZE, BULLET_SIZE);

    for(int i = 0; i < m_shape.getVertexCount(); ++i){
        m_shape[i].color = sf::Color::Red;
    }

    m_normalShape = m_shape;

}
 
void Bullet::update(float dt){
    m_lifeTime -= dt;

    if( m_lifeTime < 0 ){
        m_lifeTime = 0;
        m_isAlive = false;
    }

    m_rot += m_rotVel * dt;

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
}

void Bullet::draw(sf::RenderWindow& renderWindow){
    renderWindow.draw(m_shape);
}