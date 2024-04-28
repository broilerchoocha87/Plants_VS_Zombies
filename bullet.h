#pragma once
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