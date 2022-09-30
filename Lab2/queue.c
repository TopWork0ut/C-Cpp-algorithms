#include "queue.h"

Queue *Front = NULL, *Rear = NULL;

void Enqueue(struct Node *data) {
    Queue* temp;
    temp = (Queue*)malloc(sizeof(Queue));
    temp->data = data;
    temp->next = NULL;
    if (Front == NULL) {
        Front = Rear = temp;
    } else {
        Rear->next = temp;
        Rear = temp;
    }
}

struct Node* Dequeue() {
    if (Rear != NULL) {
        if (!Front->next) {
            struct Node *p;
            p = Front->data;
            free(Front);
            Front = Rear = NULL;

            return p;
        } else {
            struct Node *p;
            Queue* q;
            q = Front;
            p = Front->data;
            Front = Front->next;
            free(q);

            return p;
        }
    }
    return NULL;
}

