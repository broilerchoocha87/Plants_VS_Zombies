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

public:
	int zombieCode;
	Zombie();
};

class SimpleZombie :public Zombie
{
protected:

	Image sZombieImage;
	Texture sZombieTexture;
	Sprite zombieFrame [7];

public:
	SimpleZombie();
	void drawZombie(sf::RenderWindow& window);
	void moveZombie();
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