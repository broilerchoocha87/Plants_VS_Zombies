#pragma once

#ifndef LEVELS_H
#define LEVELS_H
#include "Sun.h"
#include"GameGrid.h"
#include"PlantFactory.h"
#include"ZombieFactory.h"
#include"Plants.h"
#include"Zombie.h"
#include "Sun.h"
#include"SFML/Graphics.hpp"

class levels // Abstract class
{
protected:

	int mySuns;
	int* myAllowedPlants; // pointer to array of allowed plants' codes
	int* myZombieTypes;   
	int myNumAllowedPlants; // size of array
	int myTotalZombies;
	sf::Clock releaseSunSkyClock; // Measure intervals between sun drops
	sf::Texture textureBackground; // Background texture
	sf::Sprite spriteBackground; // Backrground sprite



public:
	bool SunSkyExists;
	SunFromSky* myFallingSun;
	GameGrid myGameGrid; 
	PlantFactory myPlantFactory;
	ZombieFactory* myZombieFactory;
	void destroySunSky();
	void createSunSky();
	virtual ~levels() = 0;
	void setSuns(int sun);
	int  getSuns();
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
