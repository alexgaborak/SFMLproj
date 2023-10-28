#pragma once

class SpaceObject{
protected:
    bool m_isAlive;
    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    float m_rot;
    float m_rotVel;

    float m_linAcc;
    sf::VertexArray m_shape;
    sf::VertexArray m_normalShape;
    sf::Vector2f m_dir;

public:
    SpaceObject(
        bool isAlive,
        sf::Vector2f pos,
        sf::Vector2f vel,
        float rot,
        float rotVel
    );

    SpaceObject(
        sf::Vector2f pos,
        float rot
    );

    bool checkCollision(sf::Vector2f&);

    virtual void update(float) = 0;
    virtual void draw(sf::RenderWindow&) = 0;

    friend class Control;
    friend class Rules;
};