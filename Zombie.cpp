#include "Zombie.h"

Zombie::Zombie()
{
	health = 0.0;
	speed = 0;
	attackDamage = 0;
	//Pos.x = 0;
	//Pos.y = 0;
}

SimpleZombie::SimpleZombie()
{
	health = 240;
	speed = 1;
	attackDamage = 100;
	spriteCount = 0;
	//Pos.x = 0;
	//Pos.y = rand() % 5;

	sZombieTexture.loadFromFile("Zombie.png");
	zombieFrame.setTexture(sZombieTexture);
}

void SimpleZombie::animateZombie(sf::RenderWindow& window)
{
	//if (zombieClock.getElapsedTime().asMilliseconds() < 100)
	//	return;

	//zombieClock.restart();


	//if (spriteCount > 6)
	//	spriteCount = 0;

	zombieFrame.setTextureRect(sf::IntRect(spriteCount * 50, 46, 42, 54));
	zombieFrame.setPosition(100, 100);
	window.draw(zombieFrame);

	//spriteCount++;
}

FootballZombie::FootballZombie()
{
	health = 1600;
	speed = 3;
	attackDamage = 100;
	//Pos.x = 0;
	//Pos.y = rand() % 5;
}

FlyingZombie::FlyingZombie()
{
	health = 240;
	speed = 1;
	attackDamage = 100;
	//Pos.x = 0;
	//Pos.y = rand() % 5;
}

DancingZombie::DancingZombie()
{
	health = 500;
	speed = 2;
	attackDamage = 100;
	//Pos.x = 0;
	//Pos.y = rand() % 5;
}

DolphinRiderZombie::DolphinRiderZombie()
{
	health = 500;
	speed = 2;
	attackDamage = 100;
	//Pos.x = 0;
	//Pos.y = rand() % 5;
}
