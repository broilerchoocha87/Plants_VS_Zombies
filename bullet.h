#pragma once

#ifndef BULLETS_H
#define BULLETS_H

#include"SFML/Graphics.hpp"

/*
    will have to prevent snow bullet from stacking
*/
struct coordinates
{
    int x;
    int y;
};


class bullet
{
public:
    coordinates bulletCoord;
    bool bulletExists;
    int bulletDamage;
    float bulletSpeed;


    bullet();
    bullet(int xCoord, int yCoord, bool thisbulletExists, int thisbulletDamage,float thisBulletSpeed);
};

class SnowBullet: public bullet
{
public:
    float speedReduction;
    int freezeTime;
public:
    SnowBullet();
    SnowBullet(int xCoord, int yCoord, bool thisbulletExists, int thisbulletDamage,float thisBulletSpeed);
};

#endif // !BULLETS_H