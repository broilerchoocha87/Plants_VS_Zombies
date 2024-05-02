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

    myTotalZombies = 1;
    myZombieTypes = new int[myTotalZombies] {1};

    myZombieFactory = new ZombieFactory(myTotalZombies, myZombieTypes);

}

levels::~levels()
{
    delete [] myAllowedPlants;
    delete[] myAllowedPlants;
    delete myZombieFactory;
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
    imageBackground.loadFromFile("Images/Backgrounds/level1.png");
    textureBackground.loadFromImage(imageBackground);
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);
    window.draw(spriteBackground);
}

void beginnerGarden::animate(sf::RenderWindow& window)
{
    myZombieFactory->animateZombies(window);
}