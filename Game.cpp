#include"Game.h"

Game::Game()//:window(sf::VideoMode(800, 600), "My window")
{
    
}

void Game::render(sf::RenderWindow& window)
{
    temp.drawBackground(window);
}