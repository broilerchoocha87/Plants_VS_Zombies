#pragma once

#include "SFML/Graphics.hpp"
using namespace std;

struct coordinates {
	int x;
	int y;
};

class Zombie
{
protected:
	double health;
	float speed;
	float attackDamage;
	coordinates Pos;

public:
	Zombie();
};

class SimpleZombie :public Zombie
{
protected:

	sf::Texture sZombieTexture;

public:
	SimpleZombie();
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