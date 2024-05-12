#include "Hotbar.h"
#include<iostream>
using namespace std;
Hotbar::Hotbar()
{
    allowedSlot=6;
    // For pea Shooter
    peaShooterImage.loadFromFile("Images/Plants/Peashooter.png");
    peaShooterImage.createMaskFromColor(sf::Color(117,101,255,255));
    peaShooterTexture.loadFromImage(peaShooterImage);  
    peaShooterFrame.left = 113;
    peaShooterFrame.top = 36;
    peaShooterFrame.width = 25;
    peaShooterFrame.height = 59 - 36;
    peashooterSprite.setTexture(peaShooterTexture);
    peashooterSprite.setTextureRect(peaShooterFrame);
    peashooterSprite.setPosition(100.0f, 60.0f);
    peashooterSprite.setScale(2.6f, 2.6f);

    sunflowerImage.loadFromFile("Images/Plants/sunflower.png");
    sunflowerImage.createMaskFromColor(sf::Color(255,155,226,255)); 
    sunflowerTexture.loadFromImage(sunflowerImage); 
    sunflowerFrame.left = 160;
    sunflowerFrame.top = 1;
    sunflowerFrame.width = 26;
    sunflowerFrame.height = 25;
    sunflowerSprite.setTexture(sunflowerTexture);
    sunflowerSprite.setTextureRect(sunflowerFrame);
    sunflowerSprite.setPosition(100.0f, 140.0f);
    sunflowerSprite.setScale(2.6f, 2.6f);
    //Wall nut
    wallnutImage.loadFromFile("Images/Plants/wallnut.png");
    wallnutImage.createMaskFromColor(sf::Color(117,101,255,255)); 
    wallnutTexture.loadFromImage(wallnutImage);
    wallnutFrame.left = 135;
    wallnutFrame.top = 7;
    wallnutFrame.width = 25;
    wallnutFrame.height = 24;
    wallnutSprite.setTexture(wallnutTexture);
    wallnutSprite.setTextureRect(wallnutFrame);
    wallnutSprite.setPosition(100.0f, 220.0f);
    wallnutSprite.setScale(2.6f, 2.6f);

    //repeater
    repeaterImage.loadFromFile("Images/Plants/Repeater.png");
    repeaterImage.createMaskFromColor(sf::Color(117,101,255,255)); 
    repeaterTexture.loadFromImage(repeaterImage); 
    repeaterFrame.left = 116;
    repeaterFrame.top = 34;
    repeaterFrame.width = 25;
    repeaterFrame.height = 23;
    repeaterSprite.setTexture(repeaterTexture);
    repeaterSprite.setTextureRect(repeaterFrame);
    repeaterSprite.setPosition(100.0f, 300.0f);
    repeaterSprite.setScale(2.6f, 2.6f);

    snowPeaShooterImage.loadFromFile("Images/Plants/snow_pea.png");
    snowPeaShooterImage.createMaskFromColor(sf::Color(117,101,255,255)); 
    snowPeaShooterTexture.loadFromImage(snowPeaShooterImage);
    snowPeaShooterFrame.left = 168;
    snowPeaShooterFrame.top = 40;
    snowPeaShooterFrame.width = 28;
    snowPeaShooterFrame.height = 22;
    snowPeaShooterSprite.setTexture(snowPeaShooterTexture);
    snowPeaShooterSprite.setTextureRect(snowPeaShooterFrame);
    snowPeaShooterSprite.setPosition(100.0f, 380.0f);
    snowPeaShooterSprite.setScale(2.6f, 2.6f);

    cherryBombImage.loadFromFile("Images/Plants/cherrybomb.png");
    cherryBombTexture.loadFromImage(cherryBombImage);
    cherryBombImage.createMaskFromColor(sf::Color(117,101,255,255));
    cherryBombFrame.left = 265;
    cherryBombFrame.top = 11;
    cherryBombFrame.width = 25;
    cherryBombFrame.height = 26;
    cherryBombSprite.setTexture(cherryBombTexture);
    cherryBombSprite.setTextureRect(cherryBombFrame);
    cherryBombSprite.setPosition(100.0f, 460.0f);
    cherryBombSprite.setScale(2.6f, 2.6f);
        




}

void Hotbar::displayHotbar(sf:: RenderWindow& window)
{
    if(allowedSlot>=2)
    {
        window.draw(peashooterSprite);
        window.draw(sunflowerSprite);
    }
    if(allowedSlot>=3)
    {
        window.draw(wallnutSprite);
    }
    if(allowedSlot>=4)
    {
        window.draw(repeaterSprite);
    }
    if(allowedSlot>=5)
    {
        window.draw(snowPeaShooterSprite);
    }
    if(allowedSlot>=6)
    {
        window.draw(cherryBombSprite);
    }
    
}
void Hotbar::setSlots(int a)
{
    allowedSlot=a;
}