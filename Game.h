#pragma once
#include "levels.cpp"

class Game
{
    protected:
        sf::RenderWindow* window;
        beginnerGarden temp;
    public:
        Game();
        ~Game();
        void handleInput();
        void update();
        void render();
       
};