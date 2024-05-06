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
    sf:: Clock bulletAnimationClock;
    sf:: Clock bulletMoveClock;
    sf::Image bulletImage;
    sf::Texture bulletTexture; //Loads the spriteSheet
    sf:: Sprite bulletSprite; // Stores different variations of peashooter at different times
    sf:: IntRect frame; // Used in Animation() to choose different sprites

    bullet();
    //bullet(int xCoord, int yCoord, bool thisbulletExists, int thisbulletDamage,float thisBulletSpeed);
    void moveBullet();
    void animateBullet(sf::RenderWindow& window);
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

#endif
