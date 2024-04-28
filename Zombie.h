#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
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

class SimpleZombie : public Zombie
{
protected:

public:
	SimpleZombie();
};

class FootballZombie :public Zombie
{
public:
	FootballZombie();
};

