#ifndef LINES_HPP
#define LINES_HPP


#include <SFML/Graphics.hpp>
#include "../randomLib/random.hpp"

using Random = effolkronium::random_static;

class Line
{
public:
    Line(const sf::Vector2u & windowSize);
    void update(float dt);
    ~Line();
    sf::Vector2f getPos();
    sf::RectangleShape getLine();

private:
    const int mAngle;
    int mLength;
    const float mScalingSpeed;
    const float mAcceleration;
    int mSpeed;
    sf::Vector2f mPos;
    sf::RectangleShape mLine;
};

#endif