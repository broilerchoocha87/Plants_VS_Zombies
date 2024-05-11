#include "levels.h"
#include"Zombie.h"
#include"Plants.h"
#include <iostream>
using namespace std;
beginnerGarden::beginnerGarden()
{
	//declare allowed plants
	myAllowedPlants = new int[2]{0,1};
	myNumAllowedPlants = 2;
	//createPlant(0,255,470);
	myTotalZombies = 2;
	myZombieTypes = new int[myTotalZombies] {1, 1};

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
	if (myGameGrid.anyPlanted())
	{
		for (int i = 0; i < myTotalZombies; i++)
		{
			for (int j = 0; j < myNumAllowedPlants; j++)
			{
				if (myZombieFactory->myActiveZombies[i] != nullptr && myPlantFactory.myActivePlants[j] != nullptr)
				{
					PeaShooter* pPtr = (PeaShooter*)(myPlantFactory.myActivePlants[j]);
					SimpleZombie* zPtr = (SimpleZombie*)(myZombieFactory->myActiveZombies[i]);

					if (pPtr->zombieCollision(zPtr))
					{

					}

					if (zPtr->bulletCollision(pPtr->myBullet))
					{

					}
				}
			}
		}
	}
}
