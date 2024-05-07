#include "GameGrid.h"

GameGrid::GameGrid()
{
    minBoundx=250;// the least x value of grid
    minBoundy=80; // the least y value of grid
    maxBoundx=980;// max x calue of grid
    maxBoundy=570; // max y value of grid
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
            if (grid[i][j] == plantable)
                return true;
        }
    }

    return false;
}
