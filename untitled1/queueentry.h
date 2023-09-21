//
// Created by hhyyt on 28/06/2023.
//

#ifndef UNTITLED1_QUEUEENTRY_H
#define UNTITLED1_QUEUEENTRY_H
#include "node.h"


struct QueueEntry {
    struct node* node;
    struct QueueEntry* next;
    struct QueueEntry* previous;

};
#endif //UNTITLED1_QUEUEENTRY_H
