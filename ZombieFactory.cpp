#include"SFML/Graphics.hpp"
#include "ZombieFactory.h"

ZombieFactory::ZombieFactory()
{
	myActiveZombies = nullptr;
	myTotalZombies = 0;
	myZombieTypes = nullptr;
	myGameGrid = nullptr;
}

ZombieFactory::ZombieFactory(int TotalZombies, int* ZombieTypes, int* zombieStartTimes)
{
	myTotalZombies = TotalZombies;
	myZombieTypes = ZombieTypes;

	myActiveZombies = new Zombie * [myTotalZombies];

	for (int i = 0; i < myTotalZombies; i++)
	{
		if (myZombieTypes[i] == 1)
		{
			myActiveZombies[i] = new SimpleZombie;
		}
		else if (myZombieTypes[i] == 2)
		{
			myActiveZombies[i] = new FootballZombie;
		}
		else if (myZombieTypes[i] == 3)
		{
			myActiveZombies[i] = new FlyingZombie;
		}
		else if (myZombieTypes[i] == 4)
		{
			myActiveZombies[i] = new DancingZombie;
		}

		myActiveZombies[i]->startMovingTime = zombieStartTimes[i];
	}
}

void ZombieFactory::animateZombies(sf::RenderWindow& window)
{
	for (int i = 0; i < myTotalZombies; i++)
	{
		//SimpleZombie* zPtr = (SimpleZombie*) myActiveZombies[i];
		//if (myActiveZombies[i]->zombieCode == 4)
		//{
		//	DancingZombie* zPtr = (DancingZombie*)myActiveZombies[i];
		//	zPtr->moveZombie();
		//	zPtr->drawZombie(window);
		//	for (int i = 0; i < 2; i++)
		//	{
		//		zPtr->backupDancers[i].drawZombie(window);
		//		zPtr->backupDancers[i].moveZombie();
		//	}
		//}

		//else
		//{
		if (myActiveZombies[i]->startMovingClock.getElapsedTime().asSeconds() > myActiveZombies[i]->startMovingTime)
			myActiveZombies[i]->moveZombie();

		myActiveZombies[i]->drawZombie(window);
		/*}*/
	}
}

void ZombieFactory::updateZombies()
{
	for (int i = 0; i < myTotalZombies; i++)
	{
		if (myActiveZombies[i]->health <= 0 && !myActiveZombies[i]->isDead)
		{
			myActiveZombies[i]->isDying = true;
			myActiveZombies[i]->isMoving = false;
		}

		if (myActiveZombies[i]->isDead)
		{
			removeZombie(i);
		}
	}
}

void ZombieFactory::removeZombie(int deadZombieIndex)
{
	delete myActiveZombies[deadZombieIndex];
	myActiveZombies[deadZombieIndex] = nullptr;

	if (myTotalZombies - 1 == 0)
	{
		delete[] myActiveZombies;
		myActiveZombies = nullptr;
	}

	else
	{
		Zombie** updatedZombies;
		updatedZombies = new Zombie * [myTotalZombies - 1];

		int c = 0;
		for (int i = 0; i < myTotalZombies; i++)
		{
			if (myActiveZombies[i] != nullptr)
			{
				updatedZombies[c++] = myActiveZombies[i];
			}
		}

		delete[] myActiveZombies;
		myActiveZombies = updatedZombies;
	}

	myTotalZombies--;
}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i < myTotalZombies; i++)
		delete myActiveZombies[i];

	delete[] myActiveZombies;
}