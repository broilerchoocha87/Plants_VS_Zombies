#pragma once

#ifndef GAMEGRID_H
#define GAMEGRID_H
class GameGrid
{
    public:
        float minBoundx;// the least x value of grid
        float minBoundy; // the least y value of grid
        float maxBoundx;// max x value of grid
        float maxBoundy;// max y value of grid
        int xBlocks;// number of col
        int yBlocks;// number of row
        int gridLenght;
        int gridHeight;
        int grid[5][9];
        //Codes
        int plantable;
        int water;
        int grave;
        int planted;

        GameGrid();
        bool anyPlanted();
};
#endif
