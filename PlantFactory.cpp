#include "PlantFactory.h"

#include <iostream>
using namespace std;

//Constructor

PlantFactory::PlantFactory()
{
	myNumPlants = 0;
}


// Upon selection of user and condtions being met, a new plant is created and added to the array
bool PlantFactory::createPlant(int thisplantCode, int x, int y)
{
	// Create a similar but larger temporary dynamic memory
	Plants** temp = new Plants * [myNumPlants + 1];
	for (int i = 0; i < myNumPlants; i++)
	{
		temp[i] = myActivePlants[i];
	}
	// Delete the array of pointers (Not the object) subject to discussion
	//for(int i =0;i<myNumPlants;i++)
	delete[] myActivePlants;
	myActivePlants = temp;
	temp = 0;

	// Actually create the new plant
	switch (thisplantCode)
	{
	case 0://Peashooter
	{
		myActivePlants[myNumPlants] = new PeaShooter(x, y);
		break;
	}
	case 1:
	{//Sunflower
		myActivePlants[myNumPlants] = new Sunflower(x, y);
		break;
	}
	case 2:
	{//Wallnut
		myActivePlants[myNumPlants] = new Wallnut(x, y);
		break;
	}
	// Add more plants-->
	}
	myNumPlants++;

	return true;

}
// Animates all plants stored in myActivePlants
void PlantFactory::animatePlants(sf::RenderWindow& window)
{
    

    for(int i =0; i<myNumPlants;i++)
    {
        
        //Check plant type
        switch(myActivePlants[i]->myPlantCode)
        {
            case 0:
            {
                // To access derived class members
                PeaShooter* temp0= dynamic_cast<PeaShooter*>((myActivePlants[i]));
                // Animating
                temp0->animatePlant(window);
                temp0=0;
                break;
            }
			case 1:
            {
                
                // To access derived class members
                Sunflower* temp1= dynamic_cast<Sunflower*>((myActivePlants[i]));
                // Animating

                temp1->animatePlant(window);
				//Render suns generated from sunflower
				if(temp1->sunExists)
					temp1->mySun->animateSun(window);

                temp1=0;
                break;
            }
            case 2:
            {
                
                // To access derived class members
                Wallnut* temp2= dynamic_cast<Wallnut*>((myActivePlants[i]));
                // Animating

                temp2->animatePlant(window);

                temp2=0;
                break;
            }
            //--> Add more plants
        }
    }
	
}

void PlantFactory::updatePlants()
{
	for (int i = 0; i < myNumPlants; i++)
	{
		if (myActivePlants[i]->myHealth <= 0)
			destroyPlant(i);
		if(myActivePlants[i]->myPlantCode==1)
		{
			Sunflower* temp= dynamic_cast<Sunflower*>((myActivePlants[i]));
			temp->dropSun();
		}
	}
}

void PlantFactory::destroyPlant(int deadPlantIndex)
{
	delete myActivePlants[deadPlantIndex];
	myActivePlants[deadPlantIndex] = nullptr;

	Plants** temp = new Plants * [myNumPlants - 1];

	int c = 0;
	for (int i = 0; i < myNumPlants; i++)
	{
		if (myActivePlants[i] != nullptr)
		{
			temp[c++] = myActivePlants[i];
		}
	}

	delete[] myActivePlants;
	myActivePlants = temp;

	myNumPlants--;
}


PlantFactory:: ~PlantFactory()
{
	//Deleting 2d array
	if (myNumPlants > 0)
	{
		for (int i = 0; i < myNumPlants; i++)
		{
			delete myActivePlants[i];
		}
		delete[] myActivePlants;
	}
}
