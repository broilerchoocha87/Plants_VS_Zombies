#include "GameGrid.h"

GameGrid::GameGrid()
{
    minBoundx=259;// the least x value of grid
    minBoundy=100; // the least y value of grid
    maxBoundx=976;// max x calue of grid
    maxBoundy=570; // max y value of grid
    gridLenght=80;
    gridHeight=94;
    xBlocks=9;// number of col
    yBlocks=5;// number of row
    // Initialise the grid
    for(int i =0;i<yBlocks;i++)
    {
        for (int j=0;j<xBlocks;j++)
        {
            grid[i][j]=plantable;
        }
    }
}

bool GameGrid::anyPlanted()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == planted)
                return true;
        }
    }

    return false;
}
