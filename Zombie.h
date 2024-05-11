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

class Zombie
{
protected:

public:
	int spriteCount;
	int dyingSpriteCount;
	double health;
	float speed;
	float attackDamage;
	zombiePos Pos;
	Clock animClock;
	Clock moveClock;
	bool isMoving;
	bool isDying;
	bool isDead;

	int zombieCode;
	Zombie();
	virtual void drawZombie(sf::RenderWindow&) = 0;
	virtual void moveZombie() = 0;
	virtual bool bulletCollision(bullet* bPtr) = 0;
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
	virtual bool bulletCollision(bullet* bPtr);
	//virtual bool plantCollision(Plants* pPtr);
};

//class FootballZombie :public Zombie
//{
//protected:
//
//public:
//	FootballZombie();
//};
//
//class FlyingZombie :public Zombie
//{
//protected:
//
//public:
//	FlyingZombie();
//};
//
//class DancingZombie :public Zombie
//{
//protected:
//
//public:
//	DancingZombie();
//};
//
//class DolphinRiderZombie :public Zombie
//{
//protected:
//
//public:
//	DolphinRiderZombie();
//};

#endif // !ZOMBIE_H