#ifndef LAB2_QUEUE_H
#define LAB2_QUEUE_H

#include "BreadthFirstSearch.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    struct Node* data;
    struct Queue* next;
}Queue;

void Enqueue(struct Node *data);

struct Node* Dequeue();

#endif //LAB2_QUEUE_H


