#include "levels.h"
#include "Hotbar.h"
#include <iostream>
using namespace std;

levels:: levels()
{
	
}
void levels:: setSuns(int sun)
{
	mySuns=sun;
}
int levels:: getSuns()
{
	return mySuns;
}
void levels:: destroySunSky()
{
	delete myFallingSun;
	myFallingSun=0;
	SunSkyExists=false;
	releaseSunSkyClock.restart();
}

void levels::createSunSky()
{
	if(releaseSunSkyClock.getElapsedTime().asSeconds()>=10)
    {

        myFallingSun=new SunFromSky;
		SunSkyExists=true;

    }
}



beginnerGarden::beginnerGarden()
{
	//declare allowed plants
	myhotbar.setSlots(6);
	SunSkyExists=true;
	mySuns=1000;
	myAllowedPlants = new int[4]{0,1,2,3};
	myNumAllowedPlants = 2;
	//createPlant(0,255,470);
	myTotalZombies = 3;
	myZombieTypes = new int[myTotalZombies] {2, 1, 4};
	zombieStartTimes = new int[myTotalZombies] {2, 4, 7};

	myZombieFactory = new ZombieFactory(myTotalZombies, myZombieTypes, zombieStartTimes);
	myFallingSun=new SunFromSky;
}

levels::~levels()
{
	delete[] myAllowedPlants;
	delete[] myZombieTypes;
	delete[] zombieStartTimes;
	delete myZombieFactory;
	delete myFallingSun;
}

void beginnerGarden::createPlant(int thisplantCode, int x, int y)
{
	bool plantAllowed = false;
	
	// check if that plant is allowed (for further levels)
	plantAllowed = myPlantFactory.createPlant(thisplantCode, x, y);
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

			else if (myPlantFactory.myActivePlants[j]->myPlantCode == 1)
			{
				Sunflower* pPtr = (Sunflower*)(myPlantFactory.myActivePlants[j]);
				pPtr->zombieCollision(zPtr);
			}

			else if (myPlantFactory.myActivePlants[j]->myPlantCode == 2)
			{
				Wallnut* pPtr = (Wallnut*)(myPlantFactory.myActivePlants[j]);
				pPtr->zombieCollision(zPtr);
			}

			else if (myPlantFactory.myActivePlants[j]->myPlantCode == 3)
			{
				Repeater* pPtr = (Repeater*)(myPlantFactory.myActivePlants[j]);
				zPtr->bulletCollision(pPtr->myBullet);
				pPtr->zombieCollision(zPtr);
			}
		}
	}
}
