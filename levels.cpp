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
	myhotbar.setSlots(2);
	SunSkyExists=true;
	mySuns=50;
	myAllowedPlants = new int[2]{0,1};
	myNumAllowedPlants = 2;
	//createPlant(0,255,470);
	myTotalZombies = 3;
	myZombieTypes = new int[myTotalZombies] {2, 3, 4};
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

void levels::createPlant(int thisplantCode, int x, int y)
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
		}
	}
}
Level2::Level2()
{
	//declare allowed plants
	myhotbar.setSlots(3);
	SunSkyExists=true;
	mySuns=50;
	myAllowedPlants = new int[3]{0,1,2};
	myNumAllowedPlants = 3;
	myTotalZombies = 4;
	myZombieTypes = new int[myTotalZombies] {2, 3, 4,};
	zombieStartTimes = new int[myTotalZombies] {2, 4, 7};

	myZombieFactory = new ZombieFactory(myTotalZombies, myZombieTypes, zombieStartTimes);
	myFallingSun=new SunFromSky;
}

void Level2:: checkCollisions()
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
		}
	}
}