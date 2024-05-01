#pragma once
#include "levels.cpp"

class Game
{
    protected:
        
        beginnerGarden temp;
    public:
        Game();
        void handleInput();
        void update();
        void render(sf::RenderWindow& window);
       
};