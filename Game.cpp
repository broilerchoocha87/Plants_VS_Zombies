#include"Game.h"


void Game::render(sf::RenderWindow& window)
{
    //BackGround
     temp.drawBackground(window);
    //CardDeck
    
    //Plants and bullets if present
    //temp.createPlant(0,32,32); memory issues
    //temp.myPlantFactory.animatePlants(window);
    //Zombies
     temp.myZombieFactory->animateZombies(window); //Not working currently, typecasting error? Console says picture not loading
    // and gives access violation 
}