#include "Plants.h"
#include "bullet.h"
#include<iostream>



Plants::~Plants (){} // Definition of destructor required for a virtual destructor

Plants::Plants (int x, int y) // For ease of coordinate assignment 
{
    myPlantCoord.x=x;
    myPlantCoord.y=y;
} 


PeaShooter::PeaShooter(int xCoord, int yCoord): Plants(xCoord,yCoord)
{
    myHealth=300;
    myCost=100;
    myPlantCode=0;
    plantTexture.loadFromFile("Images/Plants/Peashooter.png");
    frame.top=0;
    frame.left=0;
    frame.height=22;
    frame.width=27;
    plantSprite.setTexture(plantTexture);
    plantSprite.setTextureRect(frame);
    plantSprite.setPosition(myPlantCoord.x,myPlantCoord.y);
    myBullet=new bullet[3]; // 3 is max bullets that can be shot at a time
}

void PeaShooter :: animatePeaShooter(sf::RenderWindow& window)
{
    /*
 logic used in future
         if(plantClock.getElpased== 1)
            frame.left+=27;
        plantSPrite.settexurerect(frame);
    */
   window.draw(plantSprite);
   std::cout<<"he"<<std::endl;
}





