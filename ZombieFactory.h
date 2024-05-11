#pragma once

#ifndef ZOMBIEFACTORY_H
#define ZOMBIEFACTORY_H

#include"SFML/Graphics.hpp"
#include"Zombie.h"

class ZombieFactory
{

protected:

public:

	Zombie** myActiveZombies;
	int myTotalZombies;
	int* myZombieTypes;
	int* myGameGrid;
	ZombieFactory();
	ZombieFactory(int myTotalZombies, int* myZombieTypes);
	void animateZombies(sf::RenderWindow& window);
	void updateZombies();
	void removeZombie(int index);
	~ZombieFactory();
};

#endif // !ZOMBIEFACTORY_H