#pragma once

#ifndef PLANTS_H
#define PLANTS_H

#include "bullet.h"
#include"SFML/Graphics.hpp"

class Plants //Abstract class
{
public:
    int myHealth; // health
    int myCost; // Amount of sun
    int myPlantCode; // Specific code 
    coordinates myPlantCoord; // Coordinates of plant on window
    sf:: Clock plantClock; // Clock specific for plant (used for animation)
    sf::Image plantImage; // Image of Plant
    sf::Texture plantTexture; //Loads the spriteSheet
    sf:: Sprite plantSprite; // Stores different variations of peashooter at different times
    sf:: IntRect frame; // Used in Animation() to choose different sprites
    Plants(int xCoord,int yCoord ); // For ease of coordinate assignment
    virtual ~Plants()=0; // pure virtual function to make class abstract

};

class PeaShooter : public Plants
{
    protected:
        int myNumbullets; // Number of bullets it can store at a time
        sf:: Clock shootClock; // Clock used to determine when to shoot
    public:
        bullet* myBullet; // pointer to array of bullets
        PeaShooter(int xCoord,int yCoord); //Constructor
        void shootBullet(); // To release a bullet from peaShooter
        void animatePeaShooter(sf::RenderWindow& window); // Animation of Peashooter
        void zombieDamage(int Zombietype); 
        ~PeaShooter(); //Destructor
};



#endif // !PLANTS_H
