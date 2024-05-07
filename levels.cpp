#include "levels.h"
#include <iostream>
using namespace std;
beginnerGarden::beginnerGarden()
{
    //declare allowed plants
    myAllowedPlants=new int [1];
    myAllowedPlants[0]= 0;
    myNumAllowedPlants=1;
    //createPlant(0,255,470);
    myTotalZombies = 1;
    myZombieTypes = new int[myTotalZombies] {1};

    myZombieFactory = new ZombieFactory(myTotalZombies, myZombieTypes);

}

levels::~levels()
{
    delete [] myAllowedPlants;
    delete[] myZombieTypes;
    delete myZombieFactory;
}

void beginnerGarden:: createPlant(int thisplantCode, int x, int y)
{
    bool plantAllowed=false;
    // check if that plant is allowed (for further levels)
    plantAllowed=myPlantFactory.createPlant(thisplantCode,x,y);
    if(plantAllowed)
    {
       // gameGrid[y][x]=2; //Plant placed
    }
}

void beginnerGarden:: drawBackground(sf:: RenderWindow &window)
{
    textureBackground.loadFromFile("Images/Backgrounds/level1.png");
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);
    window.draw(spriteBackground);
}
