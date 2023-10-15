#pragma once

class Control{
    SpaceObject &m_spaceObject;
    sf::RenderWindow &m_renderWindow;
public:
    Control(SpaceObject &spaceObject, sf::RenderWindow &renderWindow);
    void update(sf::Event&, std::vector<SpaceObject*>&);
};