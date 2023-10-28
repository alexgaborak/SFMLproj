#include <SFML/Graphics.hpp>
#include <cmath>

#include "space_object.h"

SpaceObject::SpaceObject(
    bool isAlive,
    sf::Vector2f pos,
    sf::Vector2f vel,
    float rot,
    float rotVel ): m_isAlive(isAlive),
        m_pos(pos),
        m_vel(vel),
        m_rot(rot),
        m_rotVel(rotVel), 
        m_linAcc(0), 
        m_dir(sf::Vector2f(0, 1)){

}

SpaceObject::SpaceObject(
    sf::Vector2f pos,
    float rot ): SpaceObject(true, 
        pos, 
        sf::Vector2f(0,0), 
        rot, 
        0){

}

bool SpaceObject::checkCollision(sf::Vector2f& point){

    bool inside = false;

    float x0 = point.x;
    float y0 = point.y;

    for( int i = 0 ; i < m_shape.getVertexCount() ; i+=2 ){
        float x1 = m_shape[i].position.x;
        float y1 = m_shape[i].position.y;

        float x2 = m_shape[(i+1)%m_shape.getVertexCount()].position.x;
        float y2 = m_shape[(i+1)%m_shape.getVertexCount()].position.y;

        if( y0 > fmin(y1, y2) && y0 < fmax(y1, y2) && x0 < fmax(x1, x2)){
            double _x = (y0 - (x1 * y2 - y1 * x2)/(x1 - x2)) / ((y1 - y2)/(x1 - x2));
            if( _x >= x0 ){
                inside = !inside;
            } 
        }

    }
    return inside;
}
