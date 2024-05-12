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
	Pos.x = 1200;
	Pos.y = 60 + (rand() % 5 * 95);
	zombieCode = 1;
	isMoving = true;
	isDying = false;
	isDead = false;
	isFlying = false;
	isFalling = false;

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
			if ((bPtr[i].bulletCoord.x) >= Pos.x && Pos.y >= (bPtr[i].bulletCoord.y - 50) && Pos.y <= (bPtr[i].bulletCoord.y + 40))
			{
				cout << "Bullet collision" << endl;
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
	isFlying = false;
	isFalling = false;

	fZombieImage.loadFromFile("Images/Zombies/DS DSi - Plants vs Zombies - Football Zombie.png");
	fZombieImage.createMaskFromColor(sf::Color(0, 168, 96, 255));
	fZombieTexture.loadFromImage(fZombieImage);
}

void FootballZombie::drawZombie(sf::RenderWindow& window)
{
	if (isDying)
	{
		fzombieFrame.setTexture(fZombieTexture);
		fzombieFrame.setTextureRect(sf::IntRect(dyingSpriteCount * 47, 919, 60, 47));

		if (dyingSpriteCount > 6)
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
			if (health >= 460)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 64, 78, 64, 57));
			}

			else if (health >= 360)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 64, 151, 64, 57));
			}

			else if (health >= 200)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 62, 223, 62, 57));
			}

			else if (health >= 100)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 62, 295, 62, 57));
			}

			else if (health >= 40)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 61, 365, 61, 51));
			}

			else if (health < 40)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 57, 438, 57, 51));
			}

			if (spriteCount >= 7)
				spriteCount = 0;
		}

		else

		{
			if (health >= 460)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 64, 501, 64, 55));
			}

			else if (health >= 360)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 64, 572, 64, 55));
			}

			else if (health >= 200)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 62, 642, 62, 56));
			}

			else if (health >= 100)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 62, 713, 62, 56));
			}

			else if (health >= 40)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 61, 781, 46, 56));
			}

			else if (health < 40)
			{
				fzombieFrame.setTexture(fZombieTexture);
				fzombieFrame.setTextureRect(sf::IntRect(spriteCount * 57, 855, 39, 45));
			}

			if (spriteCount >= 5)
				spriteCount = 0;
		}
	}

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
			Pos.x -= 4;
			moveClock.restart();
		}
	}
}

void FootballZombie::bulletCollision(bullet* bPtr)
{
	for (int i = 0; i < 3; i++)
	{
		if (bPtr[i].bulletExists)
		{
			if ((bPtr[i].bulletCoord.x) >= Pos.x && Pos.y >= (bPtr[i].bulletCoord.y - 50) && Pos.y <= (bPtr[i].bulletCoord.y + 40))
			{
				cout << "Bullet collision" << endl;
				health -= bPtr[i].bulletDamage;
				bPtr[i].bulletExists = false;
			}
		}
	}
}

FlyingZombie::FlyingZombie()
{
	health = 340;
	speed = 2;
	attackDamage = 100;
	spriteCount = 0;
	dyingSpriteCount = 0;
	Pos.x = 1200;
	Pos.y = 60 + (rand() % 5 * 95);
	zombieCode = 3;
	isMoving = true;
	isDying = false;
	isDead = false;
	isFlying = true;
	isFalling = false;

	ZombieImage.loadFromFile("Images/Zombies/DS DSi - Plants vs Zombies - Balloon Zombie.png");
	ZombieImage.createMaskFromColor(sf::Color(104, 164, 255, 255));
	ZombieTexture.loadFromImage(ZombieImage);
}

void FlyingZombie::drawZombie(sf::RenderWindow& window)
{
	if (isDying)
	{
		zombieFrame.setTexture(ZombieTexture);

		switch (dyingSpriteCount)
		{
		case 0:
			zombieFrame.setTextureRect(sf::IntRect(543, 230, 21, 29));
			break;
		case 1:
			zombieFrame.setTextureRect(sf::IntRect(564, 230, 23, 29));
			break;
		case 2:
			zombieFrame.setTextureRect(sf::IntRect(587, 230, 25, 29));
			break;
		case 3:
			zombieFrame.setTextureRect(sf::IntRect(587 + 25, 230, 40, 29));
			break;
		case 4:
			zombieFrame.setTextureRect(sf::IntRect(587 + 25 + 40, 230, 46, 29));
			break;
		}

		if (dyingSpriteCount > 5)
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

	else if (isFalling)
	{
		zombieFrame.setTexture(ZombieTexture);
		 
		if (spriteCount >= 0 && spriteCount <= 1)
			zombieFrame.setTextureRect(sf::IntRect(96 + (33 *  spriteCount), 59, 33, 76));
		else if (spriteCount>= 2 && spriteCount <= 3)
			zombieFrame.setTextureRect(sf::IntRect(163 + (spriteCount - 2) * 38, 59, 38, 76));

		if (spriteCount >= 3)
		{
			isFalling = false;
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
			if (health >= 240)
			{
				zombieFrame.setTexture(ZombieTexture);
				
				if (spriteCount >= 0 && spriteCount <= 1)
					zombieFrame.setTextureRect(sf::IntRect((spriteCount * 34) + 1, 1, 34, 57));
				else if (spriteCount >= 2 && spriteCount <= 3)
					zombieFrame.setTextureRect(sf::IntRect(69 + (spriteCount - 2) * 33, 1, 33, 57));
				else if (spriteCount >= 4 && spriteCount <= 9)
					zombieFrame.setTextureRect(sf::IntRect(135 + (spriteCount - 4) * 34, 1, 34, 57));
				else if (spriteCount >= 10 && spriteCount <= 18)
					zombieFrame.setTextureRect(sf::IntRect(339 + (spriteCount - 10) * 36, 1, 36, 57));
				else if (spriteCount == 19)
					zombieFrame.setTextureRect(sf::IntRect(663, 1, 35, 57));

				if (spriteCount >= 19)
					spriteCount = 0;
			}

			else if (health >= 160)
			{
				zombieFrame.setTexture(ZombieTexture);

				if (spriteCount >= 0 && spriteCount <= 1)
					zombieFrame.setTextureRect(sf::IntRect((spriteCount * 29) + 38, 138, 29, 44));
				else if (spriteCount >= 2 && spriteCount <= 3)
					zombieFrame.setTextureRect(sf::IntRect(96 + (spriteCount - 2) * 31, 138, 31, 44));
				else if (spriteCount >= 4 && spriteCount <= 5)
					zombieFrame.setTextureRect(sf::IntRect(158 + (spriteCount - 4) * 35, 138, 35, 44));
				else if (spriteCount >= 6 && spriteCount <= 7)
					zombieFrame.setTextureRect(sf::IntRect(228 + (spriteCount - 5) * 36, 138, 36, 44));

				if (spriteCount >= 7)
					spriteCount = 0;
			}

			else if (health < 80)
			{
				zombieFrame.setTexture(ZombieTexture);
				
				if (spriteCount >= 0 && spriteCount <= 1)
					zombieFrame.setTextureRect(sf::IntRect((spriteCount * 29) + 38, 138, 29, 44));
				else if (spriteCount >= 2 && spriteCount <= 3)
					zombieFrame.setTextureRect(sf::IntRect(96 + (spriteCount - 2) * 31, 138, 31, 44));
				else if (spriteCount >= 4 && spriteCount <= 5)
					zombieFrame.setTextureRect(sf::IntRect(158 + (spriteCount - 4) * 35, 138, 35, 44));
				else if (spriteCount >= 6 && spriteCount <= 7)
					zombieFrame.setTextureRect(sf::IntRect(228 + (spriteCount - 5) * 36, 138, 36, 44));

				if (spriteCount >= 7)
					spriteCount = 0;
			}
		}

		else

		{
			if (health >= 160)
			{
				zombieFrame.setTexture(ZombieTexture);

				switch (spriteCount)
				{
				case 0:
					zombieFrame.setTextureRect(sf::IntRect(564, 136, 34, 46));
					break;
				case 1:
					zombieFrame.setTextureRect(sf::IntRect(598, 136, 36, 46));
					break;
				case 2:
					zombieFrame.setTextureRect(sf::IntRect(598 + 36, 136, 35, 46));
					break;
				case 3:
					zombieFrame.setTextureRect(sf::IntRect(598 + 36 + 35, 136, 29, 46));
					break;
				}

			}

			else if (health < 80)
			{
				zombieFrame.setTexture(ZombieTexture);

				switch (spriteCount)
				{
				case 0:
					zombieFrame.setTextureRect(sf::IntRect(564, 183, 34, 46));
					break;
				case 1:
					zombieFrame.setTextureRect(sf::IntRect(598, 183, 36, 46));
					break;
				case 2:
					zombieFrame.setTextureRect(sf::IntRect(598 + 36, 183, 35, 46));
					break;
				case 3:
					zombieFrame.setTextureRect(sf::IntRect(598 + 36 + 35, 183, 29, 46));
					break;
				}

			}

			if (spriteCount >= 3)
				spriteCount = 0;
		}
	}

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

void FlyingZombie::moveZombie()
{
	if (isMoving) {

		if (moveClock.getElapsedTime().asMilliseconds() > 300)
		{
			Pos.x -= 2;
			moveClock.restart();
		}
	}
}

void FlyingZombie::bulletCollision(bullet* bPtr)
{
	if (isFlying)
		return;

	for (int i = 0; i < 3; i++)
	{
		if (bPtr[i].bulletExists)
		{
			if ((bPtr[i].bulletCoord.x) >= Pos.x && Pos.y >= (bPtr[i].bulletCoord.y - 50) && Pos.y <= (bPtr[i].bulletCoord.y + 40))
			{
				cout << "Bullet collision" << endl;
				health -= bPtr[i].bulletDamage;
				bPtr[i].bulletExists = false;
			}
		}
	}
}

DancingZombie::DancingZombie()
{
	health = 240;
	speed = 2;
	attackDamage = 100;
	spriteCount = 0;
	dyingSpriteCount = 0;
	Pos.x = 1200;
	Pos.y = 60 + ((rand() % 4 + 1) * 95);
	zombieCode = 4;
	isMoving = true;
	isDying = false;
	isDead = false;
	isFlying = false;
	isFalling = false;

	//backupDancers[0].Pos.y = Pos.y - 95;
	//backupDancers[1].Pos.y = Pos.y + 95;

	ZombieImage.loadFromFile("Images/Zombies/DS DSi - Plants vs Zombies - Dancing Zombie.png");
	ZombieImage.createMaskFromColor(sf::Color(232, 112, 248, 255));
	ZombieTexture.loadFromImage(ZombieImage);
}

void DancingZombie::drawZombie(sf::RenderWindow& window)
{
	if (isDying)
	{
		zombieFrame.setTexture(ZombieTexture);

		switch (spriteCount)
		{
		case 0:
			zombieFrame.setTextureRect(sf::IntRect(775, 732, 29, 57));
			break;
		case 1:
			zombieFrame.setTextureRect(sf::IntRect(866, 732, 46, 53));
			break;
		case 2:
			zombieFrame.setTextureRect(sf::IntRect(945, 732, 50, 50));
			break;
		case 3:
			zombieFrame.setTextureRect(sf::IntRect(1022, 732, 50, 50));
			break;
		}

		if (dyingSpriteCount > 3)
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
			if (health > 0)
			{
				zombieFrame.setTexture(ZombieTexture);

				switch (spriteCount)
				{
				case 0:
					zombieFrame.setTextureRect(sf::IntRect(5, 6, 42, 69));
					break;
				case 1:
					zombieFrame.setTextureRect(sf::IntRect(59, 6, 32, 69));
					break;
				case 2:
					zombieFrame.setTextureRect(sf::IntRect(114, 6, 36, 69));
					break;
				case 3:
					zombieFrame.setTextureRect(sf::IntRect(163, 6, 32, 69));
					break;
				}
			}

			if (animClock.getElapsedTime().asMilliseconds() > 200)
			{
				spriteCount++;
				animClock.restart();
			}

			if (spriteCount > 3)
				spriteCount = 0;
		}

		else

		{
			if (health > 0)
			{
				zombieFrame.setTexture(ZombieTexture);

				switch (spriteCount)
				{
				case 0:
					zombieFrame.setTextureRect(sf::IntRect(5, 592, 42, 69));
					break;
				case 1:
					zombieFrame.setTextureRect(sf::IntRect(60, 592, 40, 69));
					break;
				case 2:
					zombieFrame.setTextureRect(sf::IntRect(110, 592, 43, 69));
					break;
				case 3:
					zombieFrame.setTextureRect(sf::IntRect(163, 592, 43, 69));
					break;
				}
			}

			if (animClock.getElapsedTime().asMilliseconds() > 200)
			{
				spriteCount++;
				animClock.restart();
			}

			if (spriteCount > 3)
				spriteCount = 0;
		}
	}

	if (isDying)
		zombieFrame.setScale(2.1, 2.1);
	else
		zombieFrame.setScale(2.2, 2.2);


	zombieFrame.setPosition(Pos.x, Pos.y);
	window.draw(zombieFrame);
}

void DancingZombie::moveZombie()
{
	if (isMoving) {

		if (moveClock.getElapsedTime().asMilliseconds() > 300)
		{
			Pos.x -= 2;
			moveClock.restart();
		}
	}
}

void DancingZombie::bulletCollision(bullet* bPtr)
{
	for (int i = 0; i < 3; i++)
	{
		if (bPtr[i].bulletExists)
		{
			if ((bPtr[i].bulletCoord.x) >= Pos.x && Pos.y >= (bPtr[i].bulletCoord.y - 50) && Pos.y <= (bPtr[i].bulletCoord.y + 40))
			{
				cout << "Bullet collision" << endl;
				health -= bPtr[i].bulletDamage;
				bPtr[i].bulletExists = false;
			}
		}
	}
}
