#include "Inventory.h"

Inventory::Inventory()
{
    /*
    Peashooter=0
    Sunflower=1
    Wallnut=2
    Snowpeashooter=3
    Repeater=4
    CherryBomb=5
    */
    myNumUnlocked=2; // Sunflower and Peashooter will always be availible
    myUnlockedPlants= new int [myNumUnlocked]{0,1};//Peashooter=0, SUnflower=1

    myNumLocked=4;
    myLockedPlants= new int [myNumLocked]{2,3,4,5};
}

void Inventory:: setMyUnlockedPlants()
{
    myNumUnlocked++;
    int *temp= new int [myNumUnlocked];
    temp[myNumUnlocked-1]=myLockedPlants[0];
    //Copy rest of the list
    for(int i=0;i<myNumLocked-1;i++)
    {
        temp[i]=myUnlockedPlants[i];
    }
    delete [] myUnlockedPlants;

    myUnlockedPlants=temp;

    temp =new int [--myNumLocked];
    //Copy rest of the list
    for(int i=1;i<myNumUnlocked+1;i++)
    {
        temp[i-1]=myUnlockedPlants[i];
    }
    delete[]myLockedPlants;
    myLockedPlants=temp;
    temp=0;

}
