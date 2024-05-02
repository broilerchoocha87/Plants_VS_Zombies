#include"SFML/Graphics.hpp"
#include "ZombieFactory.h"

ZombieFactory::ZombieFactory()
{
	myActiveZombies = nullptr;
	myTotalZombies = 0;
	myZombieTypes = nullptr;
	myGameGrid = nullptr;
}

ZombieFactory::ZombieFactory(int TotalZombies, int* ZombieTypes, int* GameGrid)
{
	myTotalZombies = TotalZombies;
	myZombieTypes = ZombieTypes;
	myGameGrid = GameGrid;

	myActiveZombies = new Zombie * [myTotalZombies];

	for (int i = 0; i < myTotalZombies; i++)
	{
		if (myZombieTypes[i] == 1)
			myActiveZombies[i] = new SimpleZombie;
		else if (myZombieTypes[i] == 2)
			myActiveZombies[i] = new FootballZombie;
		else if (myZombieTypes[i] == 3)
			myActiveZombies[i] = new FlyingZombie;
		else if (myZombieTypes[i] == 4)
			myActiveZombies[i] = new DancingZombie;
		else if (myZombieTypes[i] == 5)
			myActiveZombies[i] = new DolphinRiderZombie;
	}
}