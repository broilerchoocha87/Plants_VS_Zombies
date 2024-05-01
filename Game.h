#pragma once
#include "levels.cpp"

class Game
{
    protected:
        
        beginnerGarden temp;
    public:
    sf::RenderWindow window;
        Game();
        
        void handleInput();
        void update();
        void render();
       
};