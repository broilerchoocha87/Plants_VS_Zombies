#include "Zombie.h"
#include<iostream>

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
	Pos.y = 60 + (rand() % 5 * 95);
	zombieCode = 1;
	isMoving = true;

	sZombieImage.loadFromFile("D:/Downloads/OOP_Project/Images/Zombies/DS DSi - Plants vs Zombies - Zombie.png");
	sZombieImage.createMaskFromColor(sf::Color(248, 152, 248, 255));
	sZombieTexture.loadFromImage(sZombieImage);
}

void SimpleZombie::moveZombie()
{
	if (isMoving) {

		if (moveClock.getElapsedTime().asMilliseconds() > 300)
		{
			Pos.x -= 2;
			cout << "X = " << Pos.x << " Y = " << Pos.y << endl;
			moveClock.restart();
		}
	}
}

void SimpleZombie::drawZombie(sf::RenderWindow& window)
{
	if (isMoving)
	{
		if (spriteCount > 6)
			spriteCount = 0;

		zombieFrame.setTexture(sZombieTexture);
		zombieFrame.setTextureRect(sf::IntRect(spriteCount * 50, 59, 42, 54));
	}

	else
	{

		if (spriteCount > 5)
			spriteCount = 0;

		zombieFrame.setTexture(sZombieTexture);
		zombieFrame.setTextureRect(sf::IntRect(spriteCount * 45, 224, 37, 51));
	}

	if (animClock.getElapsedTime().asMilliseconds() > 200)
	{
		spriteCount++;
		animClock.restart();
	}

	zombieFrame.setScale(2.2, 2.2);
	zombieFrame.setPosition(Pos.x, Pos.y);
	window.draw(zombieFrame);
}

bool SimpleZombie::plantCollision(int plantX, int plantY)
{
	if (Pos.x <= (plantX + 36) && Pos.y >= (plantY - 250) && Pos.y <= (plantY + 250))
	{
		isMoving = false;
		return true;
	}

	return true;
}

bool SimpleZombie::bulletCollision(int bulletX, int bulletY)
{
	if (Pos.x <= (bulletX + 10) && Pos.y >= (bulletY - 100) && Pos.y <= (bulletY + 100))
	{
		
		return true;
	}

	return false;
}

//FootballZombie::FootballZombie()
//{
//	health = 1600;
//	speed = 3;
//	attackDamage = 100;
//	//Pos.x = 0;
//	//Pos.y = rand() % 5;
//}
//
//FlyingZombie::FlyingZombie()
//{
//	health = 240;
//	speed = 1;
//	attackDamage = 100;
//	//Pos.x = 0;
//	//Pos.y = rand() % 5;
//}
//
//DancingZombie::DancingZombie()
//{
//	health = 500;
//	speed = 2;
//	attackDamage = 100;
//	//Pos.x = 0;
//	//Pos.y = rand() % 5;
//}
//
//DolphinRiderZombie::DolphinRiderZombie()
//{
//	health = 500;
//	speed = 2;
//	attackDamage = 100;
//	//Pos.x = 0;
//	//Pos.y = rand() % 5;
//}
