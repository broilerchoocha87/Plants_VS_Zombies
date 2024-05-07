#pragma once

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

struct zombiePos {
	int x;
	int y;
};

class Zombie
{
protected:
	double health;
	float speed;
	float attackDamage;
	zombiePos Pos;
	Clock animClock;
	Clock moveClock;
	int spriteCount;
	bool isMoving;

public:
	int zombieCode;
	Zombie();
	virtual void drawZombie(sf::RenderWindow&) = 0;
	virtual void moveZombie() = 0;
	//virtual bool bulletCollision(int plantX, int plantY) = 0;
	//virtual bool plantCollision(int, int) = 0;
};

class SimpleZombie :public Zombie
{
protected:

	Image sZombieImage;
	Texture sZombieTexture;
	Sprite zombieFrame [7];

public:
	SimpleZombie();
	virtual void drawZombie(sf::RenderWindow& window);
	virtual void moveZombie();
	/*virtual*/ bool bulletCollision(int bulletX, int bulletY);
	/*virtual*/ bool plantCollision(int plantX, int plantY);
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