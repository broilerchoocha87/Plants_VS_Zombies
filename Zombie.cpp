#include "Zombie.h"

Zombie::Zombie()
{
	health = 0.0;
	speed = 0;
	attackDamage = 0;
	Pos.x = 0;
	Pos.y = 0;
}

SimpleZombie::SimpleZombie()
{
	health = 240;
	speed = 1;
	attackDamage = 100;
	Pos.x = 0;
	Pos.y = rand() % 5;
}

FootballZombie::FootballZombie()
{
	health = 1600;
	speed = 3;
	attackDamage = 100;
	Pos.x = 0;
	Pos.y = rand() % 5;
}

FlyingZombie::FlyingZombie()
{
	health = 240;
	speed = 1;
	attackDamage = 100;
	Pos.x = 0;
	Pos.y = rand() % 5;
}

DancingZombie::DancingZombie()
{
	health = 500;
	speed = 2;
	attackDamage = 100;
	Pos.x = 0;
	Pos.y = rand() % 5;
}

DolphinRiderZombie::DolphinRiderZombie()
{
	health = 500;
	speed = 2;
	attackDamage = 100;
	Pos.x = 0;
	Pos.y = rand() % 5;
}