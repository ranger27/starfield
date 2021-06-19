#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../Lines/lines.hpp"
#include <vector>

class Game
{
public:
    Game();
    ~Game();
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();

private:
    sf::Vector2u mwindowSize;
    sf::RenderWindow mWindow;
    // Time after which a line is made
    float mLineMakingDuration = 0.03f;
    float mCurrentDuration = 0.0f;
    std::vector<Line *> mCurrLines;
};

#endif