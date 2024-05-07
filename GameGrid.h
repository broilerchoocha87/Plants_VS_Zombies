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
        int grid[5][9];
        //Codes
        const int plantable=0;
        const int water=1;
        const int grave=2;
        const int planted=3;

        GameGrid();
        bool anyPlanted();
};
#endif
