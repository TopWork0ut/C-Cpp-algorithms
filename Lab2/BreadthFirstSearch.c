#include "BreadthFirstSearch.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

extern Queue *Front;
extern Queue *Rear;

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
}

int calculateHeightOfTree(struct Node* node) {
    if (node == NULL)
        return 0;
    else {
        int leftSubTreeHeight = calculateHeightOfTree(node->leftChild);
        int rightSubTreeHeight = calculateHeightOfTree(node->rightChild);

        if (leftSubTreeHeight > rightSubTreeHeight)
            return (leftSubTreeHeight + 1);
        else
            return (rightSubTreeHeight + 1);
    }
}

void printCurrentLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->leftChild, level - 1);
        printCurrentLevel(root->rightChild, level - 1);
    }
}

void printLevelOrder(struct Node* root) {
    int height = calculateHeightOfTree(root);
    int i;
    for (i = 1; i <= height; i++) {
        printCurrentLevel(root, i);
    }
}

void deleteAllFromQueue() {
    while (Front != NULL) {
        Dequeue();
    }
}

int findMinDepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        deleteAllFromQueue();
        Enqueue(root);
        root->depth = 1;

        if (root->leftChild->data == 0 || root->rightChild->data == 0) {
            return 1;
        }
        while (Front != NULL) {
            struct Node* node = Front->data;
            int depth = Front->data->depth;

            if (Front->data->leftChild->data == 0 && Front->data->rightChild->data == 0) {
                return depth;
            }
            if (Front->data->leftChild) {
                node->leftChild->depth = node->depth + 1;
                Enqueue(node->leftChild);
            }
            if (Front->data->rightChild) {
                node->rightChild->depth = node->depth + 1;
                Enqueue(node->rightChild);
            }
            Dequeue();
        }
    }
}
