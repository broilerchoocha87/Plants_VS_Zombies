#pragma once

#ifndef LEVELS_H
#define LEVELS_H

#include"GameGrid.h"
#include"PlantFactory.h"
#include"ZombieFactory.h"
#include"SFML/Graphics.hpp"

class levels
{
protected:

	// Stores whether plantable area or not and its reason
	int* myAllowedPlants;
	int* myZombieTypes;
	int myNumAllowedPlants;
	int myTotalZombies;
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

public:
	GameGrid myGameGrid;
	PlantFactory myPlantFactory;
	ZombieFactory* myZombieFactory;
	virtual ~levels() = 0;
};

class beginnerGarden :public levels
{
public:
	beginnerGarden();
	void createPlant(int thisplantCode, int x, int y);
	void drawBackground(sf::RenderWindow& window);
	void checkCollisions();
};

#endif // !LEVELS_H
