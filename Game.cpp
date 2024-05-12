#include "Game.h"

#include<iostream>
using namespace std;


void Game::render(sf::RenderWindow& window)
{
	//BackGround
	temp.drawBackground(window);
	temp.myhotbar.displayHotbar(window);
	//CardDeck
	// sf::RectangleShape rectangle(sf::Vector2f(730, 490));
	// rectangle.setPosition(250.0f,80.0f);
	// window.draw(rectangle);
	// Plants and bullets if present
	temp.myPlantFactory.animatePlants(window);
	//Zombies
	temp.myZombieFactory->animateZombies(window);
	if(temp.SunSkyExists)
		temp.myFallingSun->animateSun(window);
	
}

void Game::handleInput(sf::RenderWindow& window, sf::Event& event)
{
	if (event.type == event.MouseButtonReleased){
	
		if (event.mouseButton.button == sf::Mouse::Left)// if left mouse button clicked
		{
			// Check if click is done in inventory location
			//Check if click is done on any pause buttons
			//cout<<"SUn X: "<<temp.myFallingSun->mySunPos.X<<"Y: "<<temp.myFallingSun->mySunPos.Y<<endl;
			cout << "Event X: " << event.mouseButton.x << "Y: " << event.mouseButton.y << endl;
			//cout << "MOsue X: " << mousePos.x << "Y: " << mousePos.y << endl;
			// Check if click is on game Grid
			if (event.mouseButton.x  >= temp.myGameGrid.minBoundx &&
			    event.mouseButton.y  >= temp.myGameGrid.minBoundy && 
				event.mouseButton.x  <= temp.myGameGrid.maxBoundx && 
				event.mouseButton.y  <= temp.myGameGrid.maxBoundy)	
			{	
				//Find the grid block
				int tempX = (event.mouseButton.x-temp.myGameGrid.minBoundx)/temp.myGameGrid.gridLenght;
				int tempY = (event.mouseButton.y-temp.myGameGrid.minBoundy)/temp.myGameGrid.gridHeight;
				// Check if sun in the sky

				if (temp.SunSkyExists &&
				event.mouseButton.x  >= temp.myFallingSun->mySunPos.X &&
			    event.mouseButton.y  >= temp.myFallingSun->mySunPos.Y && 
				event.mouseButton.x  <= temp.myFallingSun->mySunPos.X + 55&& 
				event.mouseButton.y  <= temp.myFallingSun->mySunPos.Y +55 &&
				temp.myFallingSun->mySunPos.Y>=temp.myFallingSun->yBound)// If sun landed, only then can pick
				{
					
					//Increment suns
					temp.setSuns(temp.myFallingSun->getSunValue()+temp.getSuns());
					// Delete current sun
					temp.destroySunSky();

				}
				

				//Check if click is done after selecting a plant
				// Update Game Grid
				
				else if (temp.myGameGrid.grid[tempY][tempX] == temp.myGameGrid.plantable)
				{
					
					temp.myGameGrid.grid[tempY][tempX] = temp.myGameGrid.planted;
					
					
					temp.createPlant(1, (tempX*temp.myGameGrid.gridLenght +temp.myGameGrid.minBoundx), (tempY*temp.myGameGrid.gridHeight +temp.myGameGrid.minBoundy));
				//print gamegrid

					for(int i =0;i<5;i++)
					{
						for (int j=0;j<9;j++)
						{
							cout<<temp.myGameGrid.grid[i][j]<< " ";
						}
						cout<<endl;
					}
				}
				//Check for Sunflower Suns ///CLICK IS REGISTERING!!!!!!!!!
				else{
					int i =0;
					while(i<temp.myPlantFactory.myNumPlants &&
						temp.myPlantFactory.myActivePlants[i]->myPlantCode==1)//Only check sunflower
					{
						if (temp.SunSkyExists &&
						event.mouseButton.x  >= temp.myPlantFactory.myActivePlants[i]->myPlantCoord.x &&
						event.mouseButton.y  >= temp.myPlantFactory.myActivePlants[i]->myPlantCoord.y+50 && 
						event.mouseButton.x  <= temp.myPlantFactory.myActivePlants[i]->myPlantCoord.x + 55&& 
						event.mouseButton.y  <= temp.myPlantFactory.myActivePlants[i]->myPlantCoord.y +55+50 
							)
						{
							
							//Increment suns
							temp.setSuns(25+temp.getSuns());
							cout<<temp.getSuns()<<"\n";
							// Delete current sun
							Sunflower* sunTemp= dynamic_cast<Sunflower*>((temp.myPlantFactory.myActivePlants[i]));
							sunTemp->removeSun();

						}
						i++;
					}

				}
			}

		}
	}
	
}

void Game::update()
{
	temp.checkCollisions();
	temp.myPlantFactory.updatePlants();
	temp.myZombieFactory->updateZombies();
	// SUn operations
	//Create sun

	if(temp.SunSkyExists==false)
		temp.createSunSky();// WIll only create if space availible
	
	if(temp.SunSkyExists)
		temp.myFallingSun->sunMove();

	

}