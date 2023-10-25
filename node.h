#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#include "constants.h"


struct node{
    char name;

    char connections[NUMNODES - 1]; // One node can, at most, connect to all other nodes (not including itself)
    int connectionWeights[NUMNODES - 1];

    int shortestPathVal;
    char shortestPathPrev;

    int directDistance; // Used so that A* can determine if searching along this node is appropriate
    int x,y;

    int directDistancePlusShortestDistance;

    bool explored;
};
struct node* newNode(char name, char connections[NUMNODES - 1], int connectionWeights[NUMNODES - 1], int xCord, int yCord);

#endif //NODE_H
