#pragma once

#ifndef HOTBAR_H
#define HOTBAR_H
#include"SFML/Graphics.hpp"
class Hotbar
{
private:
// Conatains all sprites and textures of plantsChoices          
    int allowedSlot; 
    //Pea shooter
// Pea Shooter
  sf::Sprite peashooterSprite;
  sf::Image peaShooterImage;
  sf::Texture peaShooterTexture;
  sf::IntRect peaShooterFrame;

  // Sunflower
  sf::Sprite sunflowerSprite;
  sf::Image sunflowerImage;
  sf::Texture sunflowerTexture;
  sf::IntRect sunflowerFrame;

  // Wall-nut
  sf::Sprite wallnutSprite;
  sf::Image wallnutImage;
  sf::Texture wallnutTexture;
  sf::IntRect wallnutFrame;

  // Repeater
  sf::Sprite repeaterSprite;
  sf::Image repeaterImage;
  sf::Texture repeaterTexture;
  sf::IntRect repeaterFrame;

  // Snow Pea Shooter
  sf::Sprite snowPeaShooterSprite;
  sf::Image snowPeaShooterImage;
  sf::Texture snowPeaShooterTexture;
  sf::IntRect snowPeaShooterFrame;

  // Cherry Bomb
  sf::Sprite cherryBombSprite;
  sf::Image cherryBombImage;
  sf::Texture cherryBombTexture;
  sf::IntRect cherryBombFrame;
    


public:
    Hotbar();
    void displayHotbar(sf:: RenderWindow& window);
    void setSlots(int a);

};
#endif