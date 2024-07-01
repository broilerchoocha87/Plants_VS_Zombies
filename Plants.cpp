#include"Plants.h"
#include<iostream>
using namespace std;


Plants::~Plants() {} // Definition of destructor required for a virtual destructor

Plants::Plants(int x, int y) // For ease of coordinate assignment
{
	myPlantCoord.x = x;
	myPlantCoord.y = y;
}

// Peashooter definitions
PeaShooter::PeaShooter(int xCoord, int yCoord) : Plants(xCoord, yCoord)
{
	myHealth = 300;
	myCost = 100;
	myPlantCode = 0;
	isShooting = false;
	shootingSpriteCount = 0;
	// Initialise bullets
	myNumbullets = 0;
	myBullet = new bullet[3]; // Max bullets at a time
	for (int i = 0; i < 3; i++)
	{
		myBullet[i].bulletExists = false;
		myBullet[i].bulletCode = 0;
	}
	// Initialising sprite
	plantImage.loadFromFile("Images/Plants/Peashooter.png");
	plantImage.createMaskFromColor(sf::Color(117, 101, 255, 255));
	plantTexture.loadFromImage(plantImage);
	frame.top = 0;
	frame.left = 0;
	frame.height = 32;
	frame.width = 27;
	plantSprite.setTexture(plantTexture);
	plantSprite.setTextureRect(frame);
	plantSprite.setPosition(myPlantCoord.x, myPlantCoord.y);
	plantSprite.setScale(2.5, 2.5);
}

void PeaShooter::animatePlant(sf::RenderWindow& window)
{
	if (plantClock.getElapsedTime().asMilliseconds() > 200){
		if (isShooting)
		{

			plantSprite.setTexture(plantTexture);
			plantSprite.setTextureRect(sf::IntRect(shootingSpriteCount * 26, 33, 26, 30));

			if (plantClock.getElapsedTime().asMilliseconds() > 75)
			{
				shootingSpriteCount++;
				plantClock.restart();
			}

			if (shootingSpriteCount > 2)
				isShooting = false;
	}
	}
	else
	{
		if (plantClock.getElapsedTime().asMilliseconds() > 100)
		{
			if (frame.left == 189)
			{
				frame.left = 0;
			}
			else
			{
				frame.left += 27;
			}
			plantSprite.setTextureRect(frame);
			plantClock.restart();
		}
	}

	if (shootClock.getElapsedTime().asSeconds() > 2)

	{
		shootBullet();
		isShooting = true;
		shootingSpriteCount = 0;
		shootClock.restart();
	}

	for (int i = 0; i < 3; i++)
	{
		if (myBullet[i].bulletExists == true)
		{
			myBullet[i].animateBullet(window);
			myBullet[i].moveBullet();
		}

		if (myBullet[i].bulletCoord.x >= 1000)
			myBullet[i].bulletExists = false;
	}

	window.draw(plantSprite);
}


void PeaShooter::shootBullet()// Creates a new bullet
{

	//Traverse array to find
	for (int i = 0; i < 3; i++)
	{
		if (myBullet[i].bulletExists == false) // Check space to create new bullet
		{
			myBullet[i].bulletExists = true;
			myBullet[i].bulletCoord.x = myPlantCoord.x + 25;//255
			myBullet[i].bulletCoord.y = myPlantCoord.y + 10;//470
			myBullet[i].bulletDamage = 20;
			myBullet[i].bulletSpeed = 10;
			myBullet[i].bulletSprite.setPosition(myBullet[i].bulletCoord.x, myBullet[i].bulletCoord.y);
			break;
		}
	}
}

void PeaShooter::zombieCollision(Zombie* zPtr)
{
	if (zPtr->Pos.x <= (myPlantCoord.x + 36) && zPtr->Pos.x >= (myPlantCoord.x - 10) && zPtr->Pos.y >= (myPlantCoord.y - 50) && zPtr->Pos.y <= (myPlantCoord.y + 40))
	{
		zPtr->isMoving = false;

		if (zPtr->zombieAttackClock.getElapsedTime().asSeconds() > 1.5f)
		{
			myHealth -= zPtr->attackDamage;
			
			if (myHealth <= 0)
				zPtr->isMoving = true;

			zPtr->zombieAttackClock.restart();
		}

		return;
	}

	zPtr->isMoving = true;
}

PeaShooter::~PeaShooter()
{
	delete[] myBullet;
}

// Wallnut Defintions

Wallnut :: Wallnut (int thisX, int thisY) : Plants(thisX, thisY)
{
	myHealth = 4000;
	myCost = 50;
	myPlantCode = 2;

	// Initialising sprite
	plantImage.loadFromFile("Images/Plants/wallnut.png");
	plantImage.createMaskFromColor(sf::Color(117,101,255,255));
	plantTexture.loadFromImage(plantImage);
	frame.top = 0;
	frame.left = 0;
	frame.height = 32;
	frame.width = 27;
	plantSprite.setTexture(plantTexture);
	plantSprite.setTextureRect(frame);
	plantSprite.setPosition(myPlantCoord.x, myPlantCoord.y);
	plantSprite.setScale(2.5, 2.5);
}

void Wallnut :: animatePlant(sf:: RenderWindow& window)
{
	if (plantClock.getElapsedTime().asMilliseconds() > 200)
		{
			
			if (frame.left >= 108)
			{
				frame.left = 0;
			}
			else
			{
				frame.left += 27;
			}
			plantSprite.setTextureRect(frame);
			plantClock.restart();
		}
	window.draw(plantSprite);
}

void Wallnut::zombieCollision(Zombie* zPtr)
{
	if (zPtr->isFlying)
		return;

	if (zPtr->Pos.x <= (myPlantCoord.x + 36) && zPtr->Pos.x >= (myPlantCoord.x - 10) && zPtr->Pos.y >= (myPlantCoord.y - 50) && zPtr->Pos.y <= (myPlantCoord.y + 40)) {
		zPtr->isMoving = false;

		if (zPtr->zombieAttackClock.getElapsedTime().asSeconds() > 1.5f)
		{
			myHealth -= zPtr->attackDamage;

			if (myHealth <= 0)
				zPtr->isMoving = true;

			zPtr->zombieAttackClock.restart();
		}

		return;
	}

	zPtr->isMoving = true;
}

Sunflower::Sunflower(int x, int y): Plants(x,y)
{
	myHealth = 300;
	myCost = 50;
	myPlantCode = 1;
	sunExists=false;
	// Initialising sprite
	plantImage.loadFromFile("Images/Plants/sunflower.png");
	plantImage.createMaskFromColor(sf::Color(255,155,226,255));
	plantTexture.loadFromImage(plantImage);
	frame.top = 37;
	frame.left = 101;
	frame.height = 32;
	frame.width = 27;
	plantSprite.setTexture(plantTexture);
	plantSprite.setTextureRect(frame);
	plantSprite.setPosition(myPlantCoord.x, myPlantCoord.y);
	plantSprite.setScale(2.5, 2.5);
}

void Sunflower::animatePlant(sf::RenderWindow& window)
{
	plantSprite.setTexture(plantTexture);
	
	switch (spriteCount)
	{
	case 0:
		plantSprite.setTextureRect(sf::IntRect(101, 38, 28, 31));
		break;
	case 1:
		plantSprite.setTextureRect(sf::IntRect(131, 38, 28, 31));
		break;
	case 2:
		plantSprite.setTextureRect(sf::IntRect(162, 38, 28, 31));
		break;
	case 3:
		plantSprite.setTextureRect(sf::IntRect(192, 38, 28, 31));
		break;
	case 4:
		plantSprite.setTextureRect(sf::IntRect(222, 38, 28, 31));
		break;
	case 5:
		plantSprite.setTextureRect(sf::IntRect(253, 38, 28, 31));
		break;
	}

	if (spriteCount > 5)
		spriteCount = 0;

	if (plantClock.getElapsedTime().asMilliseconds() > 200)
	{
		spriteCount++;
		plantClock.restart();
	}

	window.draw(plantSprite);
}

void Sunflower::dropSun()
{
	if((sunExists==false) && Sunclock.getElapsedTime().asSeconds()>=10 && Sunclock.getElapsedTime().asSeconds()<=12)
	{
		mySun= new SunFromFlower{myPlantCoord.x, myPlantCoord.y};
		sunExists=true;
	}
	else if((sunExists==true) &&Sunclock.getElapsedTime().asSeconds()>=20)
	{
		delete mySun;
		sunExists=false;
		Sunclock.restart();
	}
	
}

void Sunflower:: removeSun()
{
	//delete mySun;
	sunExists=false;
	Sunclock.restart();
}

void Sunflower::zombieCollision(Zombie* zPtr)
{
	if (zPtr->Pos.x <= (myPlantCoord.x + 36) && zPtr->Pos.x >= (myPlantCoord.x - 10) && zPtr->Pos.y >= (myPlantCoord.y - 50) && zPtr->Pos.y <= (myPlantCoord.y + 40)) {
		zPtr->isMoving = false;

		if (zPtr->zombieAttackClock.getElapsedTime().asSeconds() > 1.5f)
		{
			myHealth -= zPtr->attackDamage;

			if (myHealth <= 0)
				zPtr->isMoving = true;

			zPtr->zombieAttackClock.restart();
		}

		return;
	}

	zPtr->isMoving = true;
}

//Repeater

Repeater::Repeater(int x, int y ):Plants(x,y)
{
	myHealth = 300;
	myCost = 100;
	myPlantCode = 3;
	isShooting = false;
	shootingSpriteCount = 0;
	// Initialise bullets
	myNumbullets = 0;
	myBullet = new bullet[4]; // Max bullets at a time
	for (int i = 0; i < 3; i++)
	{
		myBullet[i].bulletExists = false;
		myBullet[i].bulletCode = 1;
	}
	// Initialising sprite
	plantImage.loadFromFile("Images/Plants/Repeater.png");
	plantImage.createMaskFromColor(sf::Color(117, 101, 255, 255));
	plantTexture.loadFromImage(plantImage);
	frame.top = 3;
	frame.left = 3;
	frame.height = 29;
	frame.width = 29;
	plantSprite.setTexture(plantTexture);
	plantSprite.setTextureRect(frame);
	plantSprite.setPosition(myPlantCoord.x, myPlantCoord.y);
	plantSprite.setScale(2.5, 2.5);
}

void Repeater::shootBullet()
{

	//Traverse array to find
	for (int i = 0; i < 4; i++)
	{
		if (myBullet[i].bulletExists == false) // Check space to create new bullet
		{
			myBullet[i].bulletExists = true;
			myBullet[i].bulletCoord.x = myPlantCoord.x + 25;//255
			myBullet[i].bulletCoord.y = myPlantCoord.y + 10;//470
			myBullet[i].bulletDamage = 20;
			myBullet[i].bulletSpeed = 10;
			myBullet[i].bulletSprite.setPosition(myBullet[i].bulletCoord.x, myBullet[i].bulletCoord.y);
			break;
		}
	}
}

void Repeater::animatePlant(sf::RenderWindow& window)
{
	
	if (plantClock.getElapsedTime().asMilliseconds() > 100)
	{
		if (frame.left >=141)
		{
			frame.left =3;
		}
		else
		{
			frame.left += 35;
		}
		plantSprite.setTextureRect(frame);
		plantClock.restart();
	}
	window.draw(plantSprite);
	//First shot
	if (shootClock.getElapsedTime().asSeconds() >= 2.0f)
	{
		shootBullet();
		
	}
	if (shootClock.getElapsedTime().asSeconds() >= 2.03f)// perfect time
	{
		shootBullet();
		shootClock.restart();
	}
	
//Animate bullet
	for (int i = 0; i < 4; i++)
	{
		if (myBullet[i].bulletExists == true)
		{
			myBullet[i].animateBullet(window);
			myBullet[i].moveBullet();
		}

		if (myBullet[i].bulletCoord.x >= 1000)
			myBullet[i].bulletExists = false;
	}

	
}

void Repeater::zombieCollision(Zombie* zPtr)
{
	if (zPtr->Pos.x <= (myPlantCoord.x + 36) && zPtr->Pos.x >= (myPlantCoord.x - 10) && zPtr->Pos.y >= (myPlantCoord.y - 50) && zPtr->Pos.y <= (myPlantCoord.y + 40)) {
		zPtr->isMoving = false;

		if (zPtr->zombieAttackClock.getElapsedTime().asSeconds() > 1.5f)
		{
			myHealth -= zPtr->attackDamage;

			if (myHealth <= 0)
				zPtr->isMoving = true;

			zPtr->zombieAttackClock.restart();
		}

		return;
	}

	zPtr->isMoving = true;
}
Repeater::~Repeater()
{

}