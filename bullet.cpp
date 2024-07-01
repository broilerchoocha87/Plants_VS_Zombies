#include "bullet.h"

bullet::bullet()
{
    bulletExists=false;
}

bullet:: bullet(int xCoord, int yCoord, bool thisbulletExists, int thisbulletDamage,float thisBulletSpeed)
{
    bulletCoord.x=xCoord;
    bulletCoord.y=yCoord;
    bulletExists=thisbulletExists;
    bulletDamage=thisbulletDamage;
    bulletSpeed=thisBulletSpeed;
}

SnowBullet::SnowBullet()
{
    bulletExists=false;
}

SnowBullet:: SnowBullet(int xCoord, int yCoord, bool thisbulletExists, int thisbulletDamage,float thisBulletSpeed)
{
    bulletCoord.x=xCoord;
    bulletCoord.y=yCoord;
    bulletExists=thisbulletExists;
    bulletDamage=thisbulletDamage;
    freezeTime=10;//seconds
    speedReduction=0.5;
    bulletSpeed=thisBulletSpeed;
}