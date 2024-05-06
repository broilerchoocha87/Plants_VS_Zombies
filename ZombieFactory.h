#pragma once

#ifndef ZOMBIEFACTORY_H
#define ZOMBIEFACTORY_H

#include"SFML/Graphics.hpp"
#include"Zombie.h"

class ZombieFactory
{

protected:

	Zombie** myActiveZombies;
	int myTotalZombies;
	int* myZombieTypes;
	int* myGameGrid;

public:

	ZombieFactory();
	ZombieFactory(int myTotalZombies, int* myZombieTypes);
	void animateZombies(sf::RenderWindow& window);
	~ZombieFactory();
};

#endif // !ZOMBIEFACTORY_H