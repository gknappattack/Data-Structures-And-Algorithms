#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Pathfinder.h"

using namespace std;

int main() {

    Pathfinder* pathptr = nullptr;//the Pathfinder
    pathptr = new Pathfinder();

    pathptr->createRandomMaze();
    cout << pathptr->toString() << endl;
    cout << "Next random maze!" << endl;
    pathptr->createRandomMaze();
    cout << pathptr->toString() << endl;


    exit(0);
}