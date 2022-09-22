//
// Created by Gregory Knapp on 5/11/20.
//

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <ctime>
#include "PathfinderInterface.h"

const int ROW_SIZE = 5;
const int COL_SIZE = 5;
const int DEEP_SIZE = 5;
const int BACKGROUND = 1;
const int WALL = 0;
const int PATH = 2;

using namespace std;

class Pathfinder : public PathfinderInterface {
public:
    Pathfinder() {
        srand(time(0));
        for (int deep = 0; deep < DEEP_SIZE; deep++) {
            for (int row = 0; row < ROW_SIZE; row++) {
                for (int col = 0; col < COL_SIZE; col++) {
                    maze_grid[col][row][deep] = 1;
                }
            }
        }
    }
    ~Pathfinder() {}
    string toString() const;
    void createRandomMaze();
    bool importMaze(string fileName);
    vector<string> solveMaze();
    void resetArray(int copy[COL_SIZE][ROW_SIZE][DEEP_SIZE]);
protected:
    int maze_grid[COL_SIZE][ROW_SIZE][DEEP_SIZE];
    bool find_maze_path(int grid[COL_SIZE][ROW_SIZE][DEEP_SIZE], int c, int r, int d);
    vector<string> solution;
};