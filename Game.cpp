#include "Game.h"


void Game::render(sf::RenderWindow& window)
{
    //BackGround
     temp.drawBackground(window);
    //CardDeck

    //Plants and bullets if present
     //memory issues
     temp.myPlantFactory.animatePlants(window);
    //Zombies
     temp.myZombieFactory->animateZombies(window);
}
