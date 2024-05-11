#include "Plants.h"
#include "bullet.h"
#include<iostream>
using namespace std;


Plants::~Plants() {} // Definition of destructor required for a virtual destructor

Plants::Plants(int x, int y) // For ease of coordinate assignment
{
	myPlantCoord.x = x;
	myPlantCoord.y = y;
}


PeaShooter::PeaShooter(int xCoord, int yCoord) : Plants(xCoord, yCoord)
{
	myHealth = 300;
	myCost = 100;
	myPlantCode = 0;
	// Initialise bullets
	myNumbullets = 0;
	myBullet = new bullet[3]; // Max bullets at a time
	for (int i = 0; i < 3; i++)
	{
		myBullet[i].bulletExists = false;
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

void PeaShooter::animatePeaShooter(sf::RenderWindow& window)
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

	//if(shootClock.getElapsedTime().asSeconds()>1.05f)
	shootBullet();

	for (int i = 0; i < 1; i++)
	{
		if (myBullet[i].bulletExists == true)
		{
			myBullet[i].animateBullet(window);
			myBullet[i].moveBullet();
		}


	}
	shootClock.restart();
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

bool PeaShooter::zombieCollision(Zombie* zPtr)
{
	if (zPtr->Pos.x <= (myPlantCoord.x + 36) && zPtr->Pos.y >= (zPtr->Pos.y - 150) && zPtr->Pos.y <= (myPlantCoord.y + 150))
	{
		zPtr->isMoving = false;
		myHealth -= zPtr->attackDamage;
		return true;
	}

	return true;
}

PeaShooter::~PeaShooter()
{
	delete[] myBullet;
}
