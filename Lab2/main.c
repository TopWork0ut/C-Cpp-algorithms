#include <stdio.h>
#include "queue.h"
#include "BreadthFirstSearch.h"
#include <string.h>
#include <stdbool.h>

extern Queue *Front;
extern Queue *Rear;

void writeToFile(char* outputFileName, int minDepth){
    FILE *fptr;
    fptr = fopen(outputFileName,"w");

    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr,"%d",minDepth);
    fclose(fptr);
}

struct Node* readFile(char* inputFileName, char* outputFileName){
    FILE* file;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    char parentChar;
    char childChar;

    if ((file = fopen(inputFileName,"r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    struct Node* root = NULL;
    bool isLeft = true;

    while (( read = getline(&line, &len, file)) != -1) {
        memcpy(&parentChar,&line[0],1);
        if (Front == NULL) {
            root = createNode(atoi(&parentChar));
            Enqueue(root);
        } else if (Front != NULL){
            memcpy(&childChar,&line[2],1);

            struct Node* node = createNode(atoi(&childChar));
            Enqueue(node);

            if (isLeft) {
                Front->data->leftChild = node;
            } else {
                Front->data->rightChild = node;
                Dequeue();;
            }
            isLeft = !isLeft;
        }
    }
    fclose(file);
    return root;
}

int main()
{
    char inputFileName[10] = "input.txt";
    char outputFileName[11] = "output.txt";
    struct Node* root = readFile(inputFileName,outputFileName);

    printf("\nLevelOrderTraversal:");
    printLevelOrder(root);
    writeToFile(outputFileName,findMinDepth(root));

    return 0;
}
