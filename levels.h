#pragma once

#ifndef LEVELS_H
#define LEVELS_H
#include "Sun.h"
#include"GameGrid.h"
#include"PlantFactory.h"
#include"ZombieFactory.h"
#include"Plants.h"
#include"Zombie.h"
#include"SFML/Graphics.hpp"

class levels // Abstract class
{
protected:

	int mySuns; //AMount of currency in hand
	int* myAllowedPlants; // pointer to array of allowed plants' codes
	int* myZombieTypes;  
	int myTotalZombies; //Total number of zombies
	sf::Clock releaseSunSkyClock; // Measure intervals between sun drops
	sf::Clock releaseFlowSunClock; // Measure intervals between sun drops
	sf::Texture textureBackground; // Background texture
	sf::Sprite spriteBackground; // Backrground sprite



public:
	levels();
	bool SunSkyExists; // Existence of sun that drop from sky
	SunFromSky* myFallingSun; // pointer to sun that drop from sky
	GameGrid myGameGrid; // Instance of gamegrid
	PlantFactory myPlantFactory; //Instance of myPlantFactory -responsible for handling plants
	int myNumAllowedPlants; // size of array
	ZombieFactory* myZombieFactory;
	void destroySunSky(); //destroy sun sky after a particualr time or when selected
	void createSunSky(); //creates a sun sky after every 10 seconds(after deletion of previous)
	virtual ~levels() = 0;//pure virtual
	void setSuns(int sun); // setter of mysuns
	int  getSuns(); // getter of mysuns

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
