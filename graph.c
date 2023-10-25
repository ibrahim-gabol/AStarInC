
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "constants.h"
#include "node.h"
#include "priorityqueue.h"
#include "queueentry.h"



struct Graph* initialiseGraph()
{
    struct Graph* temp = malloc(sizeof(struct Graph));
    temp->size = 0;

    return temp;
}

void addNode(char name, char connections[NUMNODES - 1], int connectionWeights[NUMNODES - 1], struct Graph* graph, int x, int y){

    // Index where node is stored is like a Hashtable, the index is from the ASCII character - 65
    graph->nodes[name-65] = *(newNode(name, connections, connectionWeights, x , y));
    graph->size++;

}


bool isRealNode(struct node val ){
    return ((val.name <= 90) && (val.name >= 65) && (val.shortestPathVal <= LARGESTPATHVAL));
}

void printNodes(struct Graph* graph){
    for (int i = 0; i < NUMLETTERS; i++)
    {
        if (isRealNode(graph->nodes[i]))
        {
            printf("%c ", graph->nodes[i].name);
            for (int j = 0; graph->nodes[i].connections[j] != '\0'; j++) {
                printf("%c(%d) ", graph->nodes[i].connections[j], graph->nodes[i].connectionWeights[j]);
            }
            printf("\n");
        }
    }
}

void aStarSearch(struct Graph* graph, char start, char end)
{
    struct PriorityQueue* pq = initialisePriorityQueue();

    int locationStart = start - 65;
    graph->nodes[locationStart].shortestPathVal = 0;
    graph->nodes[locationStart].directDistancePlusShortestDistance = graph->nodes[locationStart].directDistance;
    graph->nodes[locationStart].shortestPathPrev = start;

    int locationEnd = end - 65;

    for (int i = 0; i < NUMLETTERS; i++)
    {
        if (isRealNode(graph->nodes[i]))
        {
            graph->nodes[i].directDistance = round(sqrt((graph->nodes[locationEnd].x  -  graph->nodes[i].x)*(graph->nodes[locationEnd].x  -  graph->nodes[i].x) + (graph->nodes[locationEnd].y  -  graph->nodes[i].y)*(graph->nodes[locationEnd].y  -  graph->nodes[i].y)));
            if (i==start-65){graph->nodes[locationStart].directDistancePlusShortestDistance = graph->nodes[locationStart].directDistance;}
            enqueue(&graph->nodes[i],pq);
        }
    }

    struct node* currentNode;
    struct node* nextNode;

    while (pq->size != 0) {
        locationStart = dequeue(pq)->node->name - 65;
        currentNode = &graph->nodes[locationStart];
        currentNode->explored = true;
        if (currentNode->name == end){
            break;
        }
        for (int i = 0; graph->nodes[locationStart].connections[i] != '\0'; i++) {
            nextNode = &graph->nodes[graph->nodes[locationStart].connections[i] - 65];

            if (nextNode->explored == false &&
                currentNode->connectionWeights[i] + currentNode->shortestPathVal < nextNode->shortestPathVal) {
                nextNode->shortestPathVal = currentNode->shortestPathVal + currentNode->connectionWeights[i];
                nextNode->shortestPathPrev = currentNode->name;
                nextNode->directDistancePlusShortestDistance = nextNode->shortestPathVal + nextNode->directDistance;
                struct node *temp = dequeueNode(nextNode, pq);
                enqueue(temp, pq);
            }
        }
    }

    for (int i = 0; i < NUMLETTERS; i++)
    {
        if (isRealNode(graph->nodes[i]) && graph->nodes[i].name == end)
        {
            printf("The shortest path from %c to %c is:", start, end);
            currentNode = &graph->nodes[i];
            while(currentNode->name != start)
            {
                printf(" %c", currentNode->name);
                currentNode = &graph->nodes[currentNode->shortestPathPrev - 65];
            }
            printf(" %c", start);
            break;
        }



    }

}

