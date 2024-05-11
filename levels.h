#pragma once

#ifndef LEVELS_H
#define LEVELS_H

#include"GameGrid.h"
#include"PlantFactory.h"
#include"ZombieFactory.h"
#include"SFML/Graphics.hpp"

class levels // Abstract class
{
protected:
	
	int* myAllowedPlants; // pointer to array of allowed plants' codes
	int* myZombieTypes;   
	int myNumAllowedPlants; // size of array
	int myTotalZombies;
	sf::Texture textureBackground; // Background texture
	sf::Sprite spriteBackground; // Backrground sprite

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
