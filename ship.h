#pragma once

class Ship: public SpaceObject{
    sf::VertexArray m_fire;
    sf::VertexArray m_normalFire;
public:
    Ship(sf::Vector2f pos, float rot);

    void update(float) override;
    void draw(sf::RenderWindow&) override;
};