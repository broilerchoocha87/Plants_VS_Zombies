#pragma once

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "SFML/Graphics.hpp"
#include "bullet.h"
using namespace std;
using namespace sf;

struct zombiePos {
	int x;
	int y;
};

class Zombie // Abstract Class
{
protected:

public:
	int spriteCount; // Progresses through the sprite sheet
	int dyingSpriteCount; // Progresses through the sprites when Character is dying
	double health; // Stores health/Armour
	float speed; // Stores speed of the zombie
	float attackDamage; // Stores the amount of damage Zombie's attack does
	zombiePos Pos; // Saves zombie's position
	int startMovingTime; // Time when zombie is supposed to start moving
	Clock startMovingClock;
	Clock zombieAttackClock; // Delay between attacks
	Clock animClock; // Delay in animation
	Clock moveClock; // Delay in movement
	bool isMoving; // Bool for knowing if movement is needed
	bool isDying; // Bool to trigger death animation
	bool isDead; // Bool to delete Zombie object
	bool isFlying; // Bool to stop collisions with other plants
	bool isFalling; 
	int zombieCode; // Bool to store Zombie type
	
	Zombie();
	// Draws Zombie sprite on the Window
	virtual void drawZombie(sf::RenderWindow&) = 0; // Pure Virtual
	// Moves Zombie coordinates according to the speed
	virtual void moveZombie() = 0; // Pure Virtual
	// Checks for bullets colliding and decreases health accordingly
	virtual void bulletCollision(bullet* bPtr) = 0; // Pure Virtual
};

class SimpleZombie :public Zombie
{
protected:

	Image sZombieImage;
	Texture sZombieTexture;
	Sprite zombieFrame;

public:
	SimpleZombie();
	virtual void drawZombie(sf::RenderWindow& window);
	virtual void moveZombie();
	virtual void bulletCollision(bullet* bPtr);
};

class FootballZombie :public Zombie
{
protected:
	Image fZombieImage;
	Texture fZombieTexture;
	Sprite fzombieFrame;
public:
	FootballZombie();
	virtual void drawZombie(sf::RenderWindow& window);
	virtual void moveZombie();
	virtual void bulletCollision(bullet* bPtr);
};

class FlyingZombie :public Zombie
{
protected:
	Image ZombieImage;
	Texture ZombieTexture;
	Sprite zombieFrame;

public:
	FlyingZombie();
	virtual void drawZombie(sf::RenderWindow& window);
	virtual void moveZombie();
	virtual void bulletCollision(bullet* bPtr);
};

class DancingZombie :public Zombie
{
protected:
	Image ZombieImage;
	Texture ZombieTexture;
	Sprite zombieFrame;

public:
	DancingZombie();
	virtual void drawZombie(sf::RenderWindow& window);
	virtual void moveZombie();
	virtual void bulletCollision(bullet* bPtr);
};

#endif // !ZOMBIE_H