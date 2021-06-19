#include "lines.hpp"

Line::Line()
{
    m_angle = Random::get(0, 360);
    m_length = Random::get(2, 8);
    m_speed = Random::get(50, 90);
    // pos = sf::Vector2
}
void Line::update(float dt)
{
    // pos.x =
}
Line::~Line() {}
