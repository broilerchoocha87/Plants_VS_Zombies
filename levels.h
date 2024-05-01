#pragma once
#include "PlantFactory.h"
class levels
{
    protected:
        int gameGrid[5][9];// Stores whether plantable area or not and its reason
        PlantFactory myPlantFactory;
        int* myAllowedPlants;
        int myNumAllowedPlants;
        int sun;
        // Add info for zombie as well
    public:
        virtual ~levels()=0;
};

class beginnerGarden:public levels
{
    public:
        beginnerGarden();
        void createPlant(int thisplantCode, int x, int y);

        
};