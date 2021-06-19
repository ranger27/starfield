#include "lines.hpp"
#include <cmath>

Line::Line(const sf::Vector2u &windowSize)
{
    mAngle = Random::get(0, 360);
    mLength = Random::get(5, 25);
    mSpeed = Random::get(130, 200);
    mPos = sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f);
    mLine = sf::RectangleShape(sf::Vector2f(mLength, 1.0));
    mLine.setFillColor(sf::Color::White);
    mLine.setRotation(mAngle);
    mLine.setPosition(mPos);
}
void Line::update(float dt)
{
    mPos.x += mSpeed * cos((3.141593 / 180.0) * mAngle) * dt;
    mPos.y += mSpeed * sin((3.141593 / 180.0) * mAngle) * dt;
    mLine.setPosition(mPos);
}

sf::Vector2f Line::getPos()
{
    return mPos;
}

Line::~Line() {}

sf::RectangleShape Line::getLine()
{
    return mLine;
}