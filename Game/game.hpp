#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../Lines/lines.hpp"

class Game
{
public:
    Game();
    ~Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

private:
    sf::Vector2u mwindowSize;
    sf::RenderWindow mWindow;
};

#endif