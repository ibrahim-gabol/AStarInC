//
// Created by hhyyt on 28/06/2023.
//

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H

#include <malloc.h>
#include <string.h>
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
