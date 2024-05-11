#pragma once

#ifndef PLANTS_H
#define PLANTS_H

#include "bullet.h"
#include"SFML/Graphics.hpp"
#include "Zombie.h"

class Plants
{
public:
	int myHealth;
	int myCost;
	int myPlantCode;
	coordinates myPlantCoord;
	sf::Clock plantClock;
	sf::Image plantImage;
	sf::Texture plantTexture; //Loads the spriteSheet
	sf::Sprite plantSprite; // Stores different variations of peashooter at different times
	sf::IntRect frame; // Used in Animation() to choose different sprites
	Plants(int xCoord, int yCoord); // For ease of coordinate assignment
	virtual bool zombieCollision(Zombie* zPtr) = 0;
	virtual ~Plants() = 0; // pure virtual function to make class abstract

};

class PeaShooter : public Plants
{
protected:
	int myNumbullets;
	sf::Clock shootClock;
public:
	bullet* myBullet;
	PeaShooter(int xCoord, int yCoord);
	void shootBullet();
	void animatePeaShooter(sf::RenderWindow& window);
	virtual bool zombieCollision(Zombie* zPtr);
	~PeaShooter();
};



#endif // !PLANTS_H
