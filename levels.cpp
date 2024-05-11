#include "levels.h"
#include <iostream>
using namespace std;
beginnerGarden::beginnerGarden()
{
	//declare allowed plants
	myAllowedPlants = new int[2]{0,1};
	myNumAllowedPlants = 2;
	//createPlant(0,255,470);
	myTotalZombies = 2;
	myZombieTypes = new int[myTotalZombies] {2, 1};

	myZombieFactory = new ZombieFactory(myTotalZombies, myZombieTypes);

}

levels::~levels()
{
	delete[] myAllowedPlants;
	delete[] myZombieTypes;
	delete myZombieFactory;
}

void beginnerGarden::createPlant(int thisplantCode, int x, int y)
{
	bool plantAllowed = false;
	
	// check if that plant is allowed (for further levels)
	plantAllowed = myPlantFactory.createPlant(thisplantCode, x, y);
	cout<<"Hello created"<<endl;
}

void beginnerGarden::drawBackground(sf::RenderWindow& window)
{
	textureBackground.loadFromFile("Images/Backgrounds/level1.png");
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);
	window.draw(spriteBackground);
}

void beginnerGarden::checkCollisions()
{
	for (int i = 0; i < myZombieFactory->myTotalZombies; i++)
	{
		for (int j = 0; j < myPlantFactory.myNumPlants; j++)
		{
			Zombie* zPtr = (myZombieFactory->myActiveZombies[i]);
			
			if (myPlantFactory.myActivePlants[j]->myPlantCode == 0)
			{
				PeaShooter* pPtr = (PeaShooter*)(myPlantFactory.myActivePlants[j]);
				zPtr->bulletCollision(pPtr->myBullet);
				pPtr->zombieCollision(zPtr);
			}

			else if (myPlantFactory.myActivePlants[j]->myPlantCode == 2)
			{
				Wallnut* pPtr = (Wallnut*)(myPlantFactory.myActivePlants[j]);
				pPtr->zombieCollision(zPtr);
			}

			else if (myPlantFactory.myActivePlants[j]->myPlantCode == 1)
			{

			}
		}
	}
}
