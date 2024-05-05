#include"Game.h"

Game::Game()
{
    
}

void Game::render(sf::RenderWindow& window)
{
    //BackGround
    temp.drawBackground(window);
    //CardDeck
    
    //Plants and bullets if present

    //Zombies
    temp.animateLevelZombies(window); //Not working currently, typecasting error? Console says picture not loading
    // and gives access violation 
}