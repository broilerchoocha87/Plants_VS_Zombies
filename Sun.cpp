#include "Sun.h"
#include <iostream>
using namespace std;
Sun::Sun()
{
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
    sunExists=true;
    int temp=rand()%732 + 250;;
    mySunPos.X= temp;// According to lb and ub of gamegrid
    yBound=rand()%490 +80;
    mySunPos.Y=0;
    sunSprite.setScale(0.05,0.05);
    sunSprite.setPosition(mySunPos.X,mySunPos.Y);
    //hitbox.setPosition(temp,0);
    //hitbox.setSize(sf::Vector2f(30.f, 30.f));
    //hitbox.setOutlineColor(sf::Color::Red);
    //hitbox.setFillColor(sf::Color::Transparent);
}

void SunFromSky::sunMove()
{
    if(sunExists&& moveClock.getElapsedTime().asMilliseconds()>100 && mySunPos.Y<yBound)
    {
        mySunPos.Y+=6;
        //hitbox.setPosition(mySunPos.X,mySunPos.Y);
        sunSprite.setPosition(mySunPos.X,mySunPos.Y);
        moveClock.restart();
    }
    
}

void SunFromSky::animateSun(sf::RenderWindow& window)
{   
    if(sunExists)
        window.draw(sunSprite);
    //window.draw(hitbox);

}

/*bool SunFromSky:: releaseSunFromSky()
{
    if(releaseSunSkyClock.getElapsedTime().asSeconds()>=10)
    {
        releaseSunSkyClock.restart();
        return true;
    }
    return false;
}*/
/*
bool SunFromFlower:: releaseSunFromFlower()
{
    if(releaseSunFlowClock.getElapsedTime().asSeconds()==10)
    {
        releaseSunFlowClock.restart();
        return true;
    }
    return false;
}
*/
