#pragma once

class Rules{
public:
    static void positionCheck   (std::vector<SpaceObject*>&, sf::RenderWindow&);
    static void checkLifeTime   (std::vector<SpaceObject*>&);
    static void checkCollision  (std::vector<SpaceObject*>&);
};