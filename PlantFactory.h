#pragma once

#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include <SFML/Graphics.hpp>
#include "Plants.h"
class PlantFactory
{
    protected:
    
    public:
        int myNumPlants;// stores number of plants and next free location in myActivePlants
        Plants** myActivePlants;
        PlantFactory();
        // Upon selection of user and condtions being met, a new plant is created and added to the array
        bool createPlant(int thisplantCode, int x, int y);
       
        // Either when plant dies or is forcefully removed
        void destroyPlant(int deadPlantIndex);

        void animatePlants(sf::RenderWindow &window);
        void updatePlants();
        
        ~PlantFactory();
        

};

#endif // !PLANTFACTORY_H