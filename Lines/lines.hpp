#ifndef LINES_HPP
#define LINES_HPP


#include <SFML/Graphics.hpp>
#include "../randomLib/random.hpp"

using Random = effolkronium::random_static;

class Line
{
public:
    Line();
    void update(float dt);
    ~Line();

private:
    int m_angle;
    int m_length;
    int m_speed;
    sf::Vector2f pos;
};

#endif