//
// Created by Gregory Knapp on 5/11/20.
//

#include "Pathfinder.h"

bool Pathfinder::importMaze(string fileName) {
    cout << "importMaze from " << fileName << endl;

    string grid;

    int safetyCopy[ROW_SIZE][COL_SIZE][DEEP_SIZE];
    for (int deep = 0; deep < DEEP_SIZE; deep++) {
        for (int row = 0; row < ROW_SIZE; row++) {
            for (int col = 0; col < COL_SIZE; col++) {
                safetyCopy[col][row][deep] = maze_grid[col][row][deep];
            }
        }
    }

    ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        return false;
    }
    else {
        string line;
        while(!file.eof()) {
            getline(file,line);
            grid += line + " ";
        }
    }
    file.close();

    stringstream ss(grid);
    stringstream check(grid);
    int arrayCounter = 0;
    int test;

    while (check >> test && !cin.fail()) {
        arrayCounter += 1;
    }

    if (arrayCounter != 125) {
        return false;
    }

    for (int deep = 0; deep < DEEP_SIZE; deep++) {
        for (int row = 0; row < ROW_SIZE; row++) {
            for (int col = 0; col < COL_SIZE; col++) {
                int value;
                ss >> value;
                if (value != 1) {
                    if (value != 0) {
                        return false;
                    }
                }
                maze_grid[col][row][deep] = value;
            }
        }
    }

    if (maze_grid[0][0][0] == 0 || maze_grid[4][4][4] == 0) {
        cout << "this maze is no good!!" << endl;
        resetArray(safetyCopy);
        return false;
    }

    return true;
}
vector<string> Pathfinder::solveMaze() {

    while (!solution.empty()) {
        solution.pop_back();
    }

    int copyArray[COL_SIZE][ROW_SIZE][DEEP_SIZE];
    for (int deep = 0; deep < DEEP_SIZE; deep++) {
        for (int row = 0; row < ROW_SIZE; row++) {
            for (int col = 0; col < COL_SIZE; col++) {
                copyArray[col][row][deep] = maze_grid[col][row][deep];
            }
        }
    }

    find_maze_path(copyArray, 0,0,0);

    for(auto s:solution) {
        cout << s <<endl;
    }
    return solution;
}
string Pathfinder::toString() const {
    stringstream ss;
    for (int deep = 0; deep < DEEP_SIZE; deep++) {
        for (int row = 0; row < ROW_SIZE; row++) {
            for (int col = 0; col < COL_SIZE; col++) {
                if (col != 4) {
                    ss << maze_grid[col][row][deep] << " ";
                }
                else {
                    ss << maze_grid[col][row][deep];
                }

            }
            ss << endl;
        }
        if (deep != 4) {
            ss << endl;
        }
    }
    return ss.str();
}

void Pathfinder::createRandomMaze() {
    for (int deep = 0; deep < DEEP_SIZE; deep++) {
        for (int row = 0; row < ROW_SIZE; row++) {
            for (int col = 0; col < COL_SIZE; col++) {
                maze_grid[col][row][deep] = rand() % 2;
            }
        }
    }
    maze_grid[0][0][0] = 1;
    maze_grid[0][0][0] = 1;
}

bool Pathfinder::find_maze_path(int grid[COL_SIZE][ROW_SIZE][DEEP_SIZE], int c, int r, int d) {
    solution.push_back("("+to_string(c)+", "+to_string(r)+", "+to_string(d)+")"); //Add current square to vector

    if (r < 0 || r > ROW_SIZE - 1 || c < 0 || c > COL_SIZE - 1|| d < 0 || d > DEEP_SIZE - 1) { //Base Case - Outside of map
        solution.pop_back();
        return false;
    }
    else if (grid[c][r][d] == WALL) { //Base Case - Hit a Wall
        solution.pop_back();
        return false;
    }
    else if (grid[c][r][d] == PATH) { //Base Case - Already visited spot
        solution.pop_back();
        return false;
    }
    else if (r == ROW_SIZE - 1 && c == COL_SIZE - 1 && d == DEEP_SIZE - 1) { //Base Case - Reached end of map
        grid[r][c][d] = PATH;
        return true;
    }
    else { //Recursive Case!!
        grid[c][r][d] = PATH;
        if (find_maze_path(grid, c - 1, r, d) // Left
            || find_maze_path(grid, c + 1, r, d) // Right
            || find_maze_path(grid, c, r - 1, d) // Up
            || find_maze_path(grid, c, r + 1, d ) // Down
            || find_maze_path(grid, c, r, d - 1) //Up a layer
            || find_maze_path(grid, c, r, d + 1)) { //Down a layer
            return true;
        }
        else {
            solution.pop_back();
            return false;
        }
    }
}

void Pathfinder::resetArray(int copy[ROW_SIZE][COL_SIZE][DEEP_SIZE]) {
    for (int deep = 0; deep < DEEP_SIZE; deep++) {
        for (int row = 0; row < ROW_SIZE; row++) {
            for (int col = 0; col < COL_SIZE; col++) {
                maze_grid[row][col][deep] = copy[row][col][deep];
            }
        }
    }
}