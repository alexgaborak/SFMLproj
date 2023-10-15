#pragma once

class Asteroid: public SpaceObject{
public:
    Asteroid(sf::Vector2f, sf::Vector2f, float);

    void update(float) override;
    void draw(sf::RenderWindow&) override;
};