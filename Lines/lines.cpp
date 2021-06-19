#include "lines.hpp"
#include <cmath>

Line::Line(const sf::Vector2u &windowSize):mAngle(Random::get(0, 360)),mScalingSpeed(Random::get(2.5l, 2.9l)),mAcceleration(Random::get(20.0f,35.0f))
{
    mLength = Random::get(5, 25);
    mSpeed = Random::get(400, 500);
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
    mLine.scale(mScalingSpeed * (dt+1),1.0f);
    mLine.setPosition(mPos);

    mSpeed += mAcceleration*dt;

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