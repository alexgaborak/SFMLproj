#include <SFML/Graphics.hpp>
#include <cmath>

#include "space_object.h"
#include "asteroid.h"

#define PI 3.14

Asteroid::Asteroid( sf::Vector2f pos, sf::Vector2f vel, float radius ): SpaceObject(true, pos, vel, 0, 1.0 * (rand()/ (double)RAND_MAX - 0.5) ){

    m_shape = sf::VertexArray(sf::Lines, 16);

    float rotation = 0;
    for( int i = 0 ; i < 16 ; ++i ){
        float xDir = - radius * sin( rotation );
        float yDir = radius * cos( rotation );
        m_shape[i].position = sf::Vector2f(xDir , yDir);
        m_shape[i].color = sf::Color::Blue;
        if(i%2==0){
            rotation += 2.0 * PI / 8.0;
        }
    }

    m_normalShape = m_shape;

}


void Asteroid::update(float dt){
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

void Asteroid::draw(sf::RenderWindow& renderWindow){
    renderWindow.draw(m_shape);
}