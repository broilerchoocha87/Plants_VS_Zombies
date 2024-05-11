#pragma once

#ifndef HOTBAR_H
#define HOTBAR_H
#include"SFML/Graphics.hpp"
#include "Inventory.h"
class Hotbar: public Inventory
{
private:
// Conatains all sprites and textures of plantsChoices          
    sf::Sprite myPlantChoices[6]; 
    int mySlots;   

public:
    Hotbar();
    void displayHotbar();
    void setSlots();

};
#endif