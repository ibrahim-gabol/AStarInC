

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"
#include "constants.h"




struct node* newNode(char name, char connections[NUMNODES - 1], int connectionWeights[NUMNODES - 1], int xCord, int yCord)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->name = name;
    temp->shortestPathVal = 999;
    temp->shortestPathPrev = '\0';
    temp->x = xCord;
    temp->y = yCord;
    temp->directDistance = 999;
    temp->directDistancePlusShortestDistance = 999;
    temp->explored = false;
    for (int i = 0; i < NUMNODES - 1; i++)
    {
        temp->connections[i] = connections[i];
        temp->connectionWeights[i] = connectionWeights[i];

    }
    return temp;

}

#endif //UNTITLED1_NODE_H
