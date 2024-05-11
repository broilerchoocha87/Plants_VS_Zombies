#include"SFML/Graphics.hpp"
#include "ZombieFactory.h"

ZombieFactory::ZombieFactory()
{
	myActiveZombies = nullptr;
	myTotalZombies = 0;
	myZombieTypes = nullptr;
	myGameGrid = nullptr;
}

ZombieFactory::ZombieFactory(int TotalZombies, int* ZombieTypes)
{
	myTotalZombies = TotalZombies;
	myZombieTypes = ZombieTypes;

	myActiveZombies = new Zombie * [myTotalZombies];

	for (int i = 0; i < myTotalZombies; i++)
	{
		if (myZombieTypes[i] == 1)
			myActiveZombies[i] = new SimpleZombie;
		//else if (myZombieTypes[i] == 2)
		//	myActiveZombies[i] = new FootballZombie;
		//else if (myZombieTypes[i] == 3)
		//	myActiveZombies[i] = new FlyingZombie;
		//else if (myZombieTypes[i] == 4)
		//	myActiveZombies[i] = new DancingZombie;
		//else if (myZombieTypes[i] == 5)
		//	myActiveZombies[i] = new DolphinRiderZombie;
	}
}

void ZombieFactory::animateZombies(sf::RenderWindow& window)
{
	if (myTotalZombies == 0)
		return;

	for (int i = 0; i < myTotalZombies; i++)
	{
		if (myActiveZombies[i] != nullptr)
		{
			//SimpleZombie* zPtr = (SimpleZombie*) myActiveZombies[i];
			myActiveZombies[i]->moveZombie();
			myActiveZombies[i]->drawZombie(window);
		}
	}
}

void ZombieFactory::updateZombies()
{
	for (int i = 0; i < myTotalZombies; i++)
	{
		if (myActiveZombies[i] != nullptr)
		{
			if (myActiveZombies[i]->health == 0 && myActiveZombies[i]->isDead)
			{
				removeZombie(i);
			}

			else if (myActiveZombies[i]->health == 0 && !myActiveZombies[i]->isDead)
			{
				myActiveZombies[i]->isDying = true;
			}
		}
	}
}

void ZombieFactory::removeZombie(int deadZombieIndex)
{
	delete myActiveZombies[deadZombieIndex];
	myActiveZombies[deadZombieIndex] = nullptr;

	if ((myTotalZombies - 1) == 0)
	{
		delete[] myActiveZombies;
		myActiveZombies = nullptr;
	}

	else
	{
		Zombie** updatedZombies;
		updatedZombies = new Zombie * [myTotalZombies - 1];
		
		for (int i = 0; i < myTotalZombies; i++)
		{
			if (myActiveZombies[i] != nullptr)
			{
				updatedZombies[i] = myActiveZombies[i];
				delete myActiveZombies[i];
				myActiveZombies[i] = nullptr;
			}
		}

		delete[] myActiveZombies;
		myActiveZombies = updatedZombies;

		--myTotalZombies;
	}
}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i < myTotalZombies; i++)
		delete myActiveZombies[i];

	delete[] myActiveZombies;
}