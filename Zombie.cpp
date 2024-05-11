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
	dyingSpriteCount = 0;
	Pos.x = 900;
	Pos.y = 60 + (rand() % 5 * 95);
	zombieCode = 1;
	isMoving = true;
	isDying = false;
	isDead = false;

	sZombieImage.loadFromFile("Images/Zombies/DS DSi - Plants vs Zombies - Zombie.png");
	sZombieImage.createMaskFromColor(sf::Color(248, 152, 248, 255));
	sZombieTexture.loadFromImage(sZombieImage);
}

void SimpleZombie::moveZombie()
{
	if (isMoving) {

		if (moveClock.getElapsedTime().asMilliseconds() > 300)
		{
			Pos.x -= 2;
			moveClock.restart();
		}
	}
}

void SimpleZombie::drawZombie(sf::RenderWindow& window)
{
	if (isDying)
	{
		zombieFrame.setTexture(sZombieTexture);
		zombieFrame.setTextureRect(sf::IntRect(dyingSpriteCount * 52, 385, 44, 34));

		if (dyingSpriteCount > 8)
		{
			isDead = true;
			isDying = false;
			return;
		}

		if (animClock.getElapsedTime().asMilliseconds() > 200)
		{
			dyingSpriteCount++;
			animClock.restart();
		}
	}

	else

	{
		if (isMoving)
		{
			if (health >= 200)
			{
				zombieFrame.setTexture(sZombieTexture);
				zombieFrame.setTextureRect(sf::IntRect(spriteCount * 50, 59, 42, 54));
			}

			else if (health >= 140)
			{
				zombieFrame.setTexture(sZombieTexture);
				zombieFrame.setTextureRect(sf::IntRect(spriteCount * 45, 121, 37, 54));
			}

			else if (health < 140)
			{
				zombieFrame.setTexture(sZombieTexture);
				zombieFrame.setTextureRect(sf::IntRect(spriteCount * 45, 752, 37, 54));
			}
		}

		else

		{
			if (health >= 200)
			{
				zombieFrame.setTexture(sZombieTexture);
				zombieFrame.setTextureRect(sf::IntRect(spriteCount * 45, 224, 37, 51));
			}

			else if (health < 140)
			{
				zombieFrame.setTexture(sZombieTexture);
				zombieFrame.setTextureRect(sf::IntRect(spriteCount * 45, 283, 37, 51));
			}
		}
	}

	if (spriteCount >= 6)
		spriteCount = 0;

	if (animClock.getElapsedTime().asMilliseconds() > 200)
	{
		spriteCount++;
		animClock.restart();
	}

	if (isDying)
		zombieFrame.setScale(2.8, 2.8);
	else
		zombieFrame.setScale(2.2, 2.2);

	zombieFrame.setPosition(Pos.x, Pos.y);
	window.draw(zombieFrame);
}

void SimpleZombie::bulletCollision(bullet* bPtr)
{
	for (int i = 0; i < 3; i++)
	{
		if (bPtr[i].bulletExists)
		{
			if (Pos.x <= (bPtr[i].bulletCoord.x) && Pos.y >= (bPtr[i].bulletCoord.y - 25) && Pos.y <= (bPtr[i].bulletCoord.y + 75))
			{
				health -= bPtr[i].bulletDamage;
				bPtr[i].bulletExists = false;
			}
		}
	}
}

//void SimpleZombie::plantCollision(Plants* pPtr)
//{
//	if (Pos.x <= (pPtr->myPlantCoord.x + 36) && Pos.y >= (pPtr->myPlantCoord.y - 125) && Pos.y <= (pPtr->myPlantCoord.y + 125))
//	{
//		isMoving = false;
//
//		if (zombieAttackClock.getElapsedTime().asSeconds() > 1.5f)
//		{
//			pPtr->myHealth -= attackDamage;
//			zombieAttackClock.restart();
//		}
//
//		return;
//	}
//
//	isMoving = true;
//}

FootballZombie::FootballZombie()
{
	health = 540;
	speed = 2;
	attackDamage = 100;
	spriteCount = 0;
	dyingSpriteCount = 0;
	Pos.x = 900;
	Pos.y = 60 + (rand() % 5 * 95);
	zombieCode = 2;
	isMoving = true;
	isDying = false;
	isDead = false;

	fZombieImage.loadFromFile("Images/Zombies/DS DSi - Plants vs Zombies - Football Zombie.png");
	fZombieImage.createMaskFromColor(sf::Color(248, 152, 248, 255));
	fZombieTexture.loadFromImage(fZombieImage);
}

void FootballZombie::drawZombie(sf::RenderWindow& window)
{
	if (isDying)
	{
		fzombieFrame.setTexture(fZombieTexture);
		fzombieFrame.setTextureRect(sf::IntRect(dyingSpriteCount * 52, 385, 44, 34));

		if (dyingSpriteCount > 8)
		{
			isDead = true;
			isDying = false;
			return;
		}

		if (animClock.getElapsedTime().asMilliseconds() > 200)
		{
			dyingSpriteCount++;
			animClock.restart();
		}
	}

	else

	{
		if (isMoving)
		{
			if (health >= 540)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect((spriteCount * 65) + 8, 83, 44, 52));
			}

			else if (health >= 460)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect((spriteCount * 65) + 8, 156, 44, 52));
			}

			else if (health >= 360)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect((spriteCount * 65) + 8, 227, 44, 52));
			}

			else if (health >= 200)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect((spriteCount * 63) + 8, 299, 44, 51));
			}

			else if (health >= 100)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect((spriteCount * 65) + 8, 369, 44, 51));
			}

			else if (health < 100)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect((spriteCount * 57) + 8, 443, 44, 51));
			}
		}

		else

		{
			if (health >= 200)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 45, 224, 37, 51));
			}

			else if (health < 140)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 45, 283, 37, 51));
			}
		}
	}

	if (spriteCount >= 6)
		spriteCount = 0;

	if (animClock.getElapsedTime().asMilliseconds() > 200)
	{
		spriteCount++;
		animClock.restart();
	}

	if (isDying)
		fzombieFrame.setScale(2.8, 2.8);
	else
		fzombieFrame.setScale(2.2, 2.2);

	fzombieFrame.setPosition(Pos.x, Pos.y);
	window.draw(fzombieFrame);
}

void FootballZombie::moveZombie()
{
	if (isMoving) {

		if (moveClock.getElapsedTime().asMilliseconds() > 200)
		{
			Pos.x -= 2;
			moveClock.restart();
		}
	}
}

void FootballZombie::bulletCollision(bullet* bPtr)
{

}

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
