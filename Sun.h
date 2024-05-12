#pragma once

#ifndef SUN_H
#define SUN_H
#include"SFML/Graphics.hpp"
struct Coordinates
{
    int X;
    int Y;
};

class Sun
{
    protected:
        int mySunValue;// The value that each object of sun holds -- 25 (currency val)
    public:
        Coordinates mySunPos; // Position of sun
        bool sunExists;
        sf::Clock animationSunClock;  // CLock used to alter thru variations of sprite
        sf::Image sunImage; // Image if sun --used to mask
        sf::Texture sunTexture; //Loads the spriteSheet
        sf::Sprite sunSprite; // Stores different variations at different times
        sf::IntRect frame; // Used in Animation() to choose different sprites
        Sun();// constructor
        void virtual animateSun(sf::RenderWindow& window)=0;//Pure virtual
        int getSunValue();


};

class SunFromSky : public Sun // Class of sun that falls from sky
{
    public:
        int yBound;// The landing coordinate of sun
        sf::Clock moveClock; // Used for sun movement
        SunFromSky(); // constructor
        //bool releaseSunFromSky(); // Check if corret time to drop sun
        void sunMove(); // Movement of sun
        void animateSun(sf::RenderWindow& window); // animate falling sun
        // Temporary hitbox
        //sf::RectangleShape hitbox;
};
/*
class SunFromFlower : public Sun
{
    public: 
        SunFromFlower();
        sf::Clock releaseSunFlowClock;
        bool releaseSunFromFlower();
};
*/


#endif