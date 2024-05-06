#include"Game.h"


void Game::render(sf::RenderWindow& window)
{
    //BackGround
     temp.drawBackground(window);
    //CardDeck
    
    //Plants and bullets if present
    //temp.createPlant(0,120,120); //memory issues
    //temp.myPlantFactory.animatePlants(window);
    //Zombies
     temp.myZombieFactory->animateZombies(window); 
}