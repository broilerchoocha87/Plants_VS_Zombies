#include"Game.h"

Game::Game()
{
    
}

void Game::render(sf::RenderWindow& window)
{
    temp.drawBackground(window);
    temp.animateLevel(window);
}