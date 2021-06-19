#include "game.hpp"

Game::Game() : mwindowSize(sf::Vector2u(1000, 800)), mWindow(sf::VideoMode(mwindowSize.x, mwindowSize.y), "Star-Field")
{
}

Game::~Game() {}

void Game::run()
{
    sf::Clock clock;
    mWindow.setFramerateLimit(60);
    while (mWindow.isOpen())
    {
        processEvents();
        sf::Time dt = clock.restart();
        update(dt.asSeconds());
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
};
void Game::update(float dt)
{
    mCurrentDuration += dt;
    if (mCurrentDuration >= mLineMakingDuration)
    {
        mCurrentDuration = 0.0f;
        Line *newLine = new Line(mwindowSize);
        mCurrLines.push_back(newLine);
    }
    for (auto i = mCurrLines.begin(); i != mCurrLines.end(); i++)
    {

        sf::Vector2f currLinePos = (*i)->getPos();
        if (currLinePos.x > mwindowSize.x || currLinePos.x < 0 || currLinePos.y < 0 || currLinePos.y > mwindowSize.y)
        {
            delete (*i);
            mCurrLines.erase(i);
            continue;
        }
        else
        {
            (*i)->update(dt);
        }
    }
}

void Game::render()
{
    mWindow.clear(sf::Color::Black);
    for (auto i = mCurrLines.begin(); i != mCurrLines.end(); i++)
    {
        mWindow.draw((*i)->getLine());
    }
    mWindow.display();
};
