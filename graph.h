#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#include "node.h"

struct Graph {
    struct node nodes[NUMLETTERS]; // 26 letters so 26 possible nodes
    int size;
};
struct Graph* initialiseGraph();

void addNode(char name, char connections[NUMNODES - 1], int connectionWeights[NUMNODES - 1], struct Graph* graph, int x, int y);

bool isRealNode(struct node val);

void printNodes(struct Graph* graph);

void aStarSearch(struct Graph* graph, char start, char end);

#endif //UNTITLED1_GRAPH_H
