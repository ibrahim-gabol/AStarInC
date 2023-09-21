#include <stdio.h>
#include "priorityqueue.h"
#include "graph.h"



int main() {

    struct Graph* g;
    g = initialiseGraph();

    // A
    char connections[NUMNODES - 1] = {'D', 'S', '\0'};
    int connectionWeights[NUMNODES - 1] = {2, 2};
    // B
    char connections1[NUMNODES - 1] = {'S', 'C', '\0'};
    int connectionWeights1[NUMNODES - 1] = {2, 1};
    // C
    char connections2[NUMNODES - 1] = {'E', 'B','\0'};
    int connectionWeights2[NUMNODES - 1] = {1, 1};
    // D
    char connections3[NUMNODES - 1] = {'E', 'A', '\0'};
    int connectionWeights3[NUMNODES - 1] = {3, 2};

    // F
    char connections6[NUMNODES - 1] = {'H', '\0'};
    int connectionWeights6[NUMNODES - 1] = {1};

    // G
    char connections7[NUMNODES - 1] = {'S', 'H',  '\0'};
    int connectionWeights7[NUMNODES - 1] = {1, 1};

    // H
    char connections8[NUMNODES - 1] = {'G', 'F', '\0'};
    int connectionWeights8[NUMNODES - 1] = {1, 1};


    // E (end)
    char connections4[NUMNODES - 1] = {'C', 'D', '\0'};
    int connectionWeights4[NUMNODES - 1] = {1,3};
    // S (start)
    char connections5[NUMNODES - 1] = {'B', 'A', 'G', '\0'};
    int connectionWeights5[NUMNODES - 1] = {2, 2, 1};

    addNode('A', connections, connectionWeights, g, 1,1);
    addNode('B', connections1,connectionWeights1,g, -1,1);
    addNode('C', connections2,connectionWeights2,g, -1,2);
    addNode('D', connections3,connectionWeights3,g, 1,2);
    addNode('F', connections6,connectionWeights6,g, 3,-3);
    addNode('G', connections7,connectionWeights7,g, 1,-1);
    addNode('H', connections8,connectionWeights8,g, 2,-2);
    addNode('E', connections4,connectionWeights4,g, 0,3);
    addNode('S', connections5,connectionWeights5,g, 0,0);

    printNodes(g);
    printf("\n");


    aStarSearch(g,'S','E');

    return 0;
}
