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

	sZombieImage.loadFromFile("Images/Zombies/DS DSi - Plants vs Zombies - Zombie.png");
	sZombieTexture.loadFromImage(sZombieImage);
	
	for (int i = 0; i < 7; i++)
	{
		zombieFrames[i].setTexture(sZombieTexture);
		zombieFrames[i].setTextureRect(sf::IntRect(i * 50, 59, 42, 54));
	}
}

void SimpleZombie::animateZombie(sf::RenderWindow& window)
{
	if (spriteCount > 6)
		spriteCount = 0;

	zombieFrames[spriteCount].setPosition(0, 0);
	window.draw(zombieFrames[spriteCount]);

	spriteCount++;

	//zombieTime = zombieClock.getElapsedTime();

	//if (spriteX < 342 && zombieTime.asMilliseconds() > 100)
	//{
	//	spriteX += 50;
	//	zombieClock.restart();
	//}
	//else if (spriteX > 342 && zombieTime.asMilliseconds() > 100)
	//{
	//	spriteX = 0;
	//	zombieClock.restart();
	//}
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
