#include "bullet.h"
#include<iostream>
using namespace std;
/*bullet::bullet()
{
	bulletExists=false;
}*/

bullet::bullet()
{
	bulletCoord.x = 0;
	bulletCoord.y = 0;
	bulletExists = true;
	bulletDamage = 20;
	bulletSpeed = 40;

	// Initialising sprite
	bulletImage.loadFromFile("Images/Plants/Peashooter.png");
	bulletImage.createMaskFromColor(sf::Color(117, 101, 255, 255));
	bulletTexture.loadFromImage(bulletImage);
	frame.top = 43;
	frame.left = 78;
	frame.height = 11;
	frame.width = 11;
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setTextureRect(frame);
	bulletSprite.setScale(2.5, 2.5);
}

void bullet::animateBullet(sf::RenderWindow& window)
{
	if (bulletExists)
	window.draw(bulletSprite);
}

void bullet::moveBullet()
{
	if (bulletExists)
	{
		bulletCoord.x += bulletSpeed;
		bulletSprite.setPosition(bulletCoord.x, bulletCoord.y);
		bulletMoveClock.restart();
	}
}

SnowBullet::SnowBullet()
{
	bulletExists = false;
}

SnowBullet::SnowBullet(int xCoord, int yCoord, bool thisbulletExists, int thisbulletDamage, float thisBulletSpeed)
{
	bulletCoord.x = xCoord;
	bulletCoord.y = yCoord;
	bulletExists = thisbulletExists;
	bulletDamage = thisbulletDamage;
	freezeTime = 10;//seconds
	speedReduction = 0.5;
	bulletSpeed = thisBulletSpeed;
}
