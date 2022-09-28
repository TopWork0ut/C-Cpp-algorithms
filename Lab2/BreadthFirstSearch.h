#ifndef LAB2_BREADTHFIRSTSEARCH_H
#define LAB2_BREADTHFIRSTSEARCH_H

struct Node{
    int data;
    int depth;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Node* createNode(int data);

int calculateHeightOfTree(struct Node* node);

void printCurrentLevel(struct Node* root, int level);

void printLevelOrder(struct Node* root);

void deleteAllFromQueue();

int findMinDepth(struct Node* root);


#endif //LAB2_BREADTHFIRSTSEARCH_H
