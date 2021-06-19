#include "game.hpp"

Game::Game() : mwindowSize(sf::Vector2u(1000, 800)), mWindow(sf::VideoMode(mwindowSize.x, mwindowSize.y), "Star-Field")
{
}

Game::~Game() {}

void Game::run()
{
    while (mWindow.isOpen())
    {
        processEvents();
        update();
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
void Game::update() {}
void Game::render()
{
    mWindow.clear(sf::Color::Green);
    // mWindow.draw();
    mWindow.display();
};
