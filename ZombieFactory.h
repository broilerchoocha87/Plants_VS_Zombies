#pragma once

#include"SFML/Graphics.hpp"
#include"Zombie.cpp"

class ZombieFactory
{

protected:

	Zombie** myActiveZombies;
	int myTotalZombies;
	int* myZombieTypes;
	int* myGameGrid;

public:

	ZombieFactory();
	ZombieFactory(int myTotalZombies, int* myZombieTypes, int* myGameGrid);
	void animateZombies(sf::RenderWindow& window);
	~ZombieFactory();
};

