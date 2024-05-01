#include "Plants.h"
#include "bullets.cpp"
/*
-- Will have to calculate exact coordinates of bullet
-- Will have to decide on where to use moveBullet function
*/


Plants::Plants (int thisHealth, int xCoord, int yCoord)
{
    plantCoord.x=xCoord;
    plantCoord.y=yCoord;
    health=thisHealth;
    
}


PeaShooter::PeaShooter(int xCoord, int yCoord): Plants(300,xCoord,yCoord)
{
    myPlantCode=0;
    myBullet= new bullet[3]; // The maximum bullets at a time for peashooter can be 3(rough)

    // Set damage and Speed
    for(int i =0;i<3;i++)
    {
        myBullet[i].bulletDamage=20;
        myBullet[i].bulletSpeed=0.8;    
    }
   
}

void PeaShooter :: shootBullet()
{
    // Check for new slot
    int freeSlot=0;
    while(myBullet[freeSlot].bulletExists==true)
    {
        freeSlot++;
    }
    myBullet[freeSlot].bulletCoord.x=plantCoord.x + 32; // Subject to change
    myBullet[freeSlot].bulletCoord.y=plantCoord.y;
    myBullet[freeSlot].bulletExists=true;
    
    // Where to make bullet move?
} 

Wallnut::Wallnut(int xCoord,int yCoord):Plants(4000, xCoord, yCoord)
{
    myPlantCode=1;
}

Repeater:: Repeater(int xCoord,int yCoord):Plants(300, xCoord, yCoord)
{
    myPlantCode=2;
    myBullet= new bullet[4]; //  The maximum bullets at a time for peashooter can be 3(rough)
    // Set damage
    for(int i =0;i<4;i++)
    {
        myBullet[i].bulletDamage=20;
        myBullet[i].bulletSpeed=0.8;    
    }
}

void Repeater :: shootBullet()
{
    // Check for new slot
    int freeSlot=0;
    while(myBullet[freeSlot].bulletExists==true)
    {
        freeSlot++;
    }
    myBullet[freeSlot].bulletCoord.x=plantCoord.x + 32; // Subject to change
    myBullet[freeSlot].bulletCoord.y=plantCoord.y;
    myBullet[freeSlot].bulletExists=true;
    // Where to make bullet move?
} 

SnowPea:: SnowPea(int xCoord,int yCoord):Plants(300, xCoord, yCoord)
{
    myPlantCode=3;
    myBullet= new SnowBullet[3]; //  The maximum bullets at a time for peashooter can be 3(rough)
    // Set damage
    for(int i =0;i<3;i++)
    {
        myBullet[i].bulletDamage=20;
        myBullet[i].bulletSpeed=0.8;    
    }
}

void SnowPea :: shootBullet()
{
    // Check for new slot
    int freeSlot=0;
    while(myBullet[freeSlot].bulletExists==true)
    {
        freeSlot++;
    }
    myBullet[freeSlot].bulletCoord.x=plantCoord.x + 32; // Subject to change
    myBullet[freeSlot].bulletCoord.y=plantCoord.y;
    myBullet[freeSlot].bulletExists=true;
    // Where to make bullet move?
} 