#include "PlantFactory.h"

#include <iostream>
using namespace std;

//Constructor

PlantFactory::PlantFactory()
{
    myNumPlants=0;
}


// Upon selection of user and condtions being met, a new plant is created and added to the array
bool PlantFactory:: createPlant(int thisplantCode, int x , int y)
{
    // Create a similar but larger temporary dynamic memory
    Plants **temp = new Plants*[myNumPlants+1];
    for(int i =0; i< myNumPlants;i++)
    {
        temp[i]=myActivePlants[i];
    }
    // Delete the array of pointers (Not the object) subject to discussion
    //for(int i =0;i<myNumPlants;i++)
        delete [] myActivePlants;
    myActivePlants=temp;
    temp=0;

    // Actually create the new plant
    switch(thisplantCode)
    {
        case 0://Peashooter
            myActivePlants[myNumPlants]=new PeaShooter(x,y);
            break;
        // Add more plants-->
    }
    myNumPlants++;
    return true;

}
// Animates all plants stored in myActivePlants
void PlantFactory:: animatePlants(sf::RenderWindow &window)
{
    for(int i =0; i<myNumPlants;i++)
    {

        //Check plant type
        switch(myActivePlants[i]->myPlantCode)
        {
            case 0:
                // To access derived class members
                PeaShooter* temp= dynamic_cast<PeaShooter*>((myActivePlants[i]));
                // Animating
                temp->animatePeaShooter(window);
                temp=0;
                break;
            //--> Add more plants
        }
    }
}


PlantFactory:: ~PlantFactory()
{
    //Deleting 2d array
    if(myNumPlants>0)
    {
        for(int i=0; i<myNumPlants;i++)
        {
            delete myActivePlants[i];
        }
        delete[] myActivePlants;
    }
}
