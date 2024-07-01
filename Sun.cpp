#include "Sun.h"
#include <iostream>
using namespace std;
Sun::Sun()
{
    sunExists=true;
    mySunValue=25; //FIxed
    sunImage.loadFromFile("Images/sun.png");
    sunTexture.loadFromImage(sunImage);
    sunSprite.setTexture(sunTexture);

}
int Sun::getSunValue()
{
	return mySunValue;
}

SunFromSky::SunFromSky()
{
    
    int temp=rand()%730 + 200;;
    mySunPos.X= temp;// According to lb and ub of gamegrid
    yBound=rand()%490 +40;
    mySunPos.Y=0;
    sunSprite.setScale(0.115,0.115);
    sunSprite.setPosition(mySunPos.X,mySunPos.Y);
   
}

void SunFromSky::sunMove()
{
	if (sunExists && moveClock.getElapsedTime().asMilliseconds() > 100 && mySunPos.Y < yBound)
	{
		mySunPos.Y += 6;
		sunSprite.setPosition(mySunPos.X, mySunPos.Y);
		moveClock.restart();
	}

}

void SunFromSky::animateSun(sf::RenderWindow& window)
{
	if (sunExists)
		window.draw(sunSprite);

}



SunFromFlower::SunFromFlower(int x, int y)
{
    mySunPos.X= x;// According to lb and ub of gamegrid
    mySunPos.Y=y;
    sunSprite.setScale(0.115,0.115);
    sunSprite.setPosition(mySunPos.X,mySunPos.Y+50);
}
void SunFromFlower::animateSun(sf::RenderWindow& window)
{
    window.draw(sunSprite);
}