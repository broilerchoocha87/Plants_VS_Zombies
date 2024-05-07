#include "Game.h"
#include<iostream>
using namespace std;


void Game::render(sf::RenderWindow& window)
{
    //BackGround
     temp.drawBackground(window);
    //CardDeck
   // sf::RectangleShape rectangle(sf::Vector2f(730, 490));
   // rectangle.setPosition(250.0f,80.0f);
//    window.draw(rectangle);
    //Plants and bullets if present
     temp.myPlantFactory.animatePlants(window);
    //Zombies
     temp.myZombieFactory->animateZombies(window);
     //temp.checkCollisions();
}

void Game:: handleInput(sf::RenderWindow& window)
{
    // Check mouse coordinates. Confirm with gamegrid. If valid position: create plant
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))// if left mouse button clicked
    {

        sf::Vector2i mousePos=sf::Mouse::getPosition(window) ;// get relative coordinates
        // Check if click is done in inventory location
        //Check if click is done on any pause buttons

        // Check if click is on game Grid
        if(mousePos.x>=temp.myGameGrid.minBoundx && mousePos.y>=temp.myGameGrid.minBoundy && mousePos.x<=temp.myGameGrid.maxBoundx && mousePos.y<=temp.myGameGrid.maxBoundy)
            // Check if clock is done on sun
            //Check if click is done after selecting a plant
            // Update Game Grid
            if(temp.myGameGrid.grid[int(((mousePos.y-temp.myGameGrid.minBoundy)/98))][int((mousePos.x-temp.myGameGrid.minBoundx)/81)]==temp.myGameGrid.plantable)
            {
                temp.myGameGrid.grid[int(((mousePos.y-temp.myGameGrid.minBoundy)/98))][int((mousePos.x-temp.myGameGrid.minBoundx)/81)]=temp.myGameGrid.planted;
                temp.createPlant(0,(int((mousePos.x)/81)*81 + 5),(int((mousePos.y)/98)*98 -10));
                cout<<"X: "<<mousePos.x<<"Y: "<<mousePos.y<<endl;
            }

    }
}
