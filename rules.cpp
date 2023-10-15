#include <SFML/Graphics.hpp>
#include <vector>

#include "space_object.h"
#include "bullet.h"
#include "ship.h"
#include "rules.h"

void Rules::positionCheck(std::vector<SpaceObject*>& objects, sf::RenderWindow& renderWindow){
    for(auto obj: objects){
        if(obj->m_pos.x > renderWindow.getSize().x ){
            obj->m_pos.x = 0.01;
        }
        if(obj->m_pos.y > renderWindow.getSize().y ){
            obj->m_pos.y = 0.01;
        }
        if(obj->m_pos.x <= 0 ){
            obj->m_pos.x = renderWindow.getSize().x - 0.01;
        }
        if(obj->m_pos.y <= 0 ){
            obj->m_pos.y = renderWindow.getSize().y - 0.01;
        }
    }
}

void Rules::checkLifeTime(std::vector<SpaceObject*>& objects){
    for( std::vector<SpaceObject*>::iterator it = objects.begin() ; it != objects.end() ; ){
        if(!(*it)->m_isAlive){
            SpaceObject* spaceObject = (*it);
            objects.erase(it);
            delete spaceObject;
        }else{
            ++it;
        }
    }
}

void Rules::checkCollision(std::vector<SpaceObject*>& objects){

    for( auto object: objects ){
        Bullet* bullet;
        if( dynamic_cast<Bullet*>(object) != nullptr ){ 
            bullet = dynamic_cast<Bullet*>(object);
            for( auto obj: objects ){
                if( dynamic_cast<Bullet*>(obj) == nullptr && dynamic_cast<Ship*>(obj) == nullptr ){
                    if(obj->checkCollision(bullet->m_pos)){
                        bullet->m_isAlive = false;
                        obj->m_isAlive = false;
                        break;
                    }
                }
            }
        }
    }

}