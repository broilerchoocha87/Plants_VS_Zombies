#pragma once

#ifndef HOTBAR_H
#define HOTBAR_H
#include"SFML/Graphics.hpp"
class Hotbar
{
private:
// Conatains all sprites and textures of plantsChoices          
    sf::Sprite *myPlantChoices; 
    sf::Sprite l;
    int mySlots; 
    sf:: Image tempImage;
    sf:: Texture tempText;
    sf:: IntRect tempFrame;


public:
    Hotbar();
    void displayHotbar(sf:: RenderWindow& window);
    void setSlots(int a);

};
#endif