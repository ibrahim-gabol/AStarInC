

#include <malloc.h>
#include "priorityqueue.h"
#include "queueentry.h"
#include "node.h"






struct PriorityQueue* initialisePriorityQueue()
{
    struct PriorityQueue* pq = malloc(sizeof(struct PriorityQueue));


    pq->size = 0;
    pq->front = malloc(sizeof(struct QueueEntry));
    pq->front->next = NULL;
    pq->front->previous = NULL;

    return pq;
}

// Insert in PriorityQueue and update corresponding next/previous values of adjacent items
void enqueue(struct node* node, struct PriorityQueue* pq) {

    struct QueueEntry* toInsert = malloc(sizeof(struct QueueEntry));
    toInsert->node = node;
    toInsert->next = NULL;
    toInsert->previous = NULL;

    if (pq->size == 0) {
        pq->front = toInsert;
    } else {
        struct QueueEntry *qe = pq->front;
        struct QueueEntry *prevqe = pq->front;

        int i = 0;
        while (qe->node->directDistancePlusShortestDistance <= node->directDistancePlusShortestDistance) {
            prevqe = qe;
            qe = qe->next;
            i++;
            if (i == pq->size){break;}
        }


        toInsert->next = qe;

        // Edge cases considered
        if (qe == pq->front) {
            pq->front = toInsert;
            toInsert->next = qe;
            qe->previous = toInsert;
        }
        else
        {
            if (qe != NULL) {
                qe->previous->next = toInsert;
                toInsert->previous = qe->previous;
                qe->previous = toInsert;
            } else {
                prevqe->next = toInsert;
                toInsert->previous = prevqe;
                //prevqe->previous = toInsert;
            }
        }


    }
    pq->size++;
}

struct QueueEntry* dequeue(struct PriorityQueue* pq){
    struct QueueEntry* temp = pq->front;
    pq->front = pq->front->next;
    pq->size--;
    return temp;
}

struct node* dequeueNode(struct node* node, struct PriorityQueue* pq){
    struct QueueEntry* temp = pq->front;


    while (temp->node != node)
    {
        temp = temp->next;
    }

    // Edge cases considered
    if (temp == pq->front)
    {
        pq->front = pq->front->next;
        if (pq->front != NULL)
        {
            pq->front->previous = NULL;
        }
    }
    else if (temp->next == NULL)
    {
        temp->previous->next = NULL;
    }
    else
    {
        temp->next->previous = temp->previous;
        temp->previous->next = temp->next;
    }



    pq->size--;
    return temp->node;
}

struct QueueEntry* peek(struct PriorityQueue* pq)
{
    return pq->front;
}

void printPriorityQueue(struct PriorityQueue* pq)
{
    struct QueueEntry* temp = pq->front;
    for (int i = 0; i < pq->size; i++)
    {
        printf("%c \n ", temp->node->name);
        temp = temp->next;

    }
}
