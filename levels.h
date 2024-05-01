#pragma once
#include "PlantFactory.cpp"
class levels
{
    protected:
        int gameGrid[5][9];// Stores whether plantable area or not and its reason
        PlantFactory myPlantFactory;
        int* myAllowedPlants;
        int myNumAllowedPlants;
        sf::Image imageBackground;
        sf::Texture textureBackground;
        sf::Sprite spriteBackground;
        // Add info for zombie as well
    public:
        virtual ~levels()=0;
};

class beginnerGarden:public levels
{
    public:
        beginnerGarden();
        void createPlant(int thisplantCode, int x, int y);
        void drawBackground(sf::RenderWindow &window);

        
};