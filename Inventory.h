#pragma once

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory // List of plant codes,
{
protected:
    int* myUnlockedPlants;
    int myNumUnlocked;
    int* myLockedPlants;
    int myNumLocked;

public:
    Inventory();
    void setMyUnlockedPlants(); // Updates inventory

};
#endif