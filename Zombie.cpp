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
	health = 270;
	speed = 1;
	attackDamage = 100;
	Pos.x = 0;
	Pos.y = rand() % 5;
}