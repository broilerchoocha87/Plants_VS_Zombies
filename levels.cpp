#include "levels.h"

beginnerGarden::beginnerGarden()
{
    // Set GameGrid
    for (int i =0;i<5;i++)
    {
        for (int j=0;j<9;j++)
        {
            gameGrid[i][j]=1; // Plantable
        }
    }
    //declare allowed plants
    myAllowedPlants=new int [1];
    myAllowedPlants[0]= 0;
    myNumAllowedPlants=1;

    
}

void beginnerGarden:: createPlant(int thisplantCode, int x, int y)
{
    bool plantAllowed=false;

    // check if that plant is allowed (for further levels)
    plantAllowed=myPlantFactory.createPlant(thisplantCode,x,y);
    if(plantAllowed)
    {
        gameGrid[y][x]=2; //Plant placed
    }
}

void beginnerGarden:: drawBackground(sf:: RenderWindow &window)
{
    textureBackground.loadFromFile("Images/Backgrounds/level1.png");
    spriteBackground.setTexture(textureBackground);
    window.draw(spriteBackground);
}