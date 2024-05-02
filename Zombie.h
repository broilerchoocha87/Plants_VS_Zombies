#pragma once

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

//struct coordinates {
//	int x;
//	int y;
//};

class Zombie
{
protected:
	double health;
	float speed;
	float attackDamage;
	//coordinates Pos;
	Clock zombieClock;

public:
	Zombie();
};

class SimpleZombie :public Zombie
{
protected:

	Image sZombieImage;
	Texture sZombieTexture;
	Sprite sZombieSprite;
	int spriteX;

public:
	SimpleZombie();
	void animate(sf::RenderWindow& window);
};

class FootballZombie :public Zombie
{
protected:

public:
	FootballZombie();
};

class FlyingZombie :public Zombie
{
protected:

public:
	FlyingZombie();
};

class DancingZombie :public Zombie
{
protected:

public:
	DancingZombie();
};

class DolphinRiderZombie :public Zombie
{
protected:

public:
	DolphinRiderZombie();
};

#endif // !ZOMBIE_H