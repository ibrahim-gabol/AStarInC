#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


#include "queueentry.h"
#include "node.h"


struct PriorityQueue {
    struct QueueEntry* front;
    int size;
};

struct PriorityQueue* initialisePriorityQueue();

void enqueue(struct node* node, struct PriorityQueue* pq);

struct QueueEntry* dequeue(struct PriorityQueue* pq);

struct node* dequeueNode(struct node* node, struct PriorityQueue* pq);

struct QueueEntry* peek(struct PriorityQueue* pq);

void printPriorityQueue(struct PriorityQueue* pq);

#endif //PRIORITYQUEUE_H
