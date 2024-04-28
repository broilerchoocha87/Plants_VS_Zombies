#pragma once
#include "bullets.cpp"
struct coordinates
{
    int x;
    int y;
};

class Plants
{
protected:
    int health; // Subject to change
    coordinates plantCoord;
public:
    Plants(int thisHealth, int xCoord,int yCoord );
            
};

class PeaShooter : public Plants
{
    protected:
        bullet * myBullet;
    public:
        PeaShooter(int thisHealth,int xCoord,int yCoord);
        void shootBullet();
};

class Wallnut : public Plants
{
    public:
        Wallnut(int thisHealth,int xCoord,int yCoord);
        
};

class Repeater: public Plants
{
    protected:
        bullet * myBullet;
    public:
        Repeater(int thisHealth, int xCoord, int yCoord);
        void shootBullet();
};

class SnowPea: public Plants
{
    protected:
        SnowBullet* myBullet;
    public:
        SnowPea(int thisHealth, int xCoord, int yCoord);
        void shootBullet();
};
