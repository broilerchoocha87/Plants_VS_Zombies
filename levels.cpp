#include "levels.h"

#include <iostream>
using namespace std;


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
	cout<<"Hello"<<endl;
}

void levels::createSunSky()
{cout<<"..";
	if(releaseSunSkyClock.getElapsedTime().asSeconds()>=10)
    {
		cout<<"Bye\n";
        myFallingSun=new SunFromSky;
		SunSkyExists=true;
		cout<<"SUn created\n";
    }
}
beginnerGarden::beginnerGarden()
{
	//declare allowed plants
	SunSkyExists=true;
	mySuns=0;
	myAllowedPlants = new int[2]{0,1};
	myNumAllowedPlants = 2;
	//createPlant(0,255,470);
	myTotalZombies = 2;
	myZombieTypes = new int[myTotalZombies] {1, 1};

	myZombieFactory = new ZombieFactory(myTotalZombies, myZombieTypes);
	myFallingSun=new SunFromSky;
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
			PeaShooter* pPtr = (PeaShooter*)(myPlantFactory.myActivePlants[j]);
			SimpleZombie* zPtr = (SimpleZombie*)(myZombieFactory->myActiveZombies[i]);

			zPtr->bulletCollision(pPtr->myBullet);
			pPtr->zombieCollision(zPtr);
		}
	}
}
