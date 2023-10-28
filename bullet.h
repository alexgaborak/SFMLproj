#pragma once

class Bullet: public SpaceObject{
    float m_lifeTime;
public:
    Bullet(sf::Vector2f pos, sf::Vector2f vel, float lifeTime );

    void update(float) override;
    void draw(sf::RenderWindow&) override;
};