#pragma once

#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include <SFML/Graphics.hpp>
#include "Plants.h"
class PlantFactory
{
    protected:
        int myNumPlants;// stores number of plants and next free location in myActivePlants
    public:
        Plants** myActivePlants;
        PlantFactory();
        // Upon selection of user and condtions being met, a new plant is created and added to the array
        bool createPlant(int thisplantCode, int x, int y);
       
        // Either when plant dies or is forcefully removed
        void destroyPlant();

        void animatePlants(sf::RenderWindow &window);
        
        ~PlantFactory();
        

};

#endif // !PLANTFACTORY_H