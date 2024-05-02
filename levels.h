#pragma once

#ifndef LEVELS_H
#define LEVELS_H

#include"PlantFactory.h"
#include"ZombieFactory.h"

class levels
{
protected:
	
	int gameGrid[5][9]; // Stores whether plantable area or not and its reason
	PlantFactory myPlantFactory;
	ZombieFactory* myZombieFactory;
	int* myAllowedPlants;
	int* myZombieTypes;
	int myNumAllowedPlants;
	int myTotalZombies;
	sf::Image imageBackground;
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

public:

	virtual ~levels() = 0;
};

class beginnerGarden :public levels
{
public:
	beginnerGarden();
	void createPlant(int thisplantCode, int x, int y);
	void drawBackground(sf::RenderWindow& window);
	void animate(sf::RenderWindow& window);
};

#endif // !LEVELS_H