

#ifndef QUEUEENTRY_H
#define QUEUEENTRY_H
#include "node.h"

// Dynamic Priority Queue ordered by ascending order (lowest priority value has highest priority)

struct QueueEntry {
    struct node* node;
    struct QueueEntry* next;
    struct QueueEntry* previous;

};
#endif //QUEUEENTRY_H
