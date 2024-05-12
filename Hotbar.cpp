#include "Hotbar.h"
#include<iostream>
using namespace std;
Hotbar::Hotbar()
{
    mySlots=6;
        myPlantChoices=new sf::Sprite [mySlots];
        tempImage.loadFromFile("Images/Plants/Peashooter.png");
        //tempImage.createMaskFromColor(sf::Color(117,101,255,255));
        tempText.loadFromImage(tempImage);
        tempFrame.left=113;
        tempFrame.top=36;
        tempFrame.width=25;
        l.setTexture(tempText);
        l.setTextureRect(tempFrame);
        l.setPosition(200.0,200.0);
        l.setScale(1.5,1.5);


}

void Hotbar::displayHotbar(sf:: RenderWindow& window)
{
    window.draw(l);
}
void Hotbar::setSlots(int a)
{
    mySlots=a;
}