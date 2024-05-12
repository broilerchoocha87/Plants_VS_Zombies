#pragma once

#ifndef PLANTS_H
#define PLANTS_H
//#include "Sun.h"
#include "bullet.h"
#include "Zombie.h"
#include "Sun.h"
#include "SFML/Graphics.hpp"

class Plants //Abstract class
{
public:
	int myHealth;
	int myCost;
	int myPlantCode;
	int spriteCount;
	coordinates myPlantCoord;
	sf::Clock plantClock;
	sf::Image plantImage;
	sf::Texture plantTexture; //Loads the spriteSheet
	sf::Sprite plantSprite; // Stores different variations of peashooter at different times
	sf::IntRect frame; // Used in Animation() to choose different sprites
	Plants(int xCoord, int yCoord); // For ease of coordinate assignment
	virtual void zombieCollision(Zombie* zPtr) = 0;
	virtual void animatePlant(sf:: RenderWindow& window) =0;
	virtual ~Plants() = 0; // pure virtual function to make class abstract

};

class PeaShooter : public Plants
{
protected:
	int myNumbullets;
	sf::Clock shootClock;
public:
	bool isShooting;
	int shootingSpriteCount;
	bullet* myBullet;
	PeaShooter(int xCoord, int yCoord);
	void shootBullet();
	void animatePlant(sf::RenderWindow& window);
	void zombieCollision(Zombie*zPtr);
	~PeaShooter();
};

class Wallnut : public Plants
{
	public:
		Wallnut(int xCoord, int yCoord);
		void animatePlant(sf::RenderWindow& window);
		void zombieCollision(Zombie* zPtr);
		//~Wallnut(); // Not required since no dynamic memory
		
};

class Sunflower : public Plants
{
	public:
		bool sunExists;
		sf::Clock Sunclock;
		SunFromFlower *mySun;
		Sunflower(int x, int y);
		void dropSun();
		void animatePlant(sf::RenderWindow& window);
		void removeSun();
		void zombieCollision(Zombie* zPtr);
		//~Sunflower();
		
};

#endif // !PLANTS_H
