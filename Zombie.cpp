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
	Pos.x = 1000;
	Pos.y = 60 + (rand()%5 * 100);
	zombieCode = 1;

	sZombieImage.loadFromFile("D:/Downloads/OOP_Project/Images/Zombies/DS DSi - Plants vs Zombies - Zombie.png");
	sZombieImage.createMaskFromColor(sf::Color(248, 152, 248, 255));
	sZombieTexture.loadFromImage(sZombieImage);

	for (int i = 0; i < 7; i++)
	{
		zombieFrame[i].setTexture(sZombieTexture);
		zombieFrame[i].setTextureRect(sf::IntRect(i * 50, 59, 42, 54));
		zombieFrame[i].setScale(2.2, 2.2);
	}
}

void SimpleZombie::moveZombie()
{
	if (moveClock.getElapsedTime().asMilliseconds() > 300)
	{
		Pos.x -= 2;
		moveClock.restart();
	}
}

void SimpleZombie::drawZombie(sf::RenderWindow& window)
{
	if (animClock.getElapsedTime().asMilliseconds() > 200)
	{
		spriteCount++;
		animClock.restart();
	}

	if (spriteCount > 6)
		spriteCount = 0;

	zombieFrame[spriteCount].setPosition(Pos.x, Pos.y);
	window.draw(zombieFrame[spriteCount]);
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
