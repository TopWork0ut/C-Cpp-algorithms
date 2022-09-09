#include<bits/stdc++.h>
using namespace std;

class AVLNode
{
public:
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;
};

int getHeightOfTheTree(AVLNode *node);
int fintMaxValue(int data1, int data2);

AVLNode* newNode(int data);
AVLNode *rightRotate(AVLNode *node);
AVLNode *leftRotate(AVLNode *node);

int getHeightDifference(AVLNode *difference);
AVLNode* insert(AVLNode* node, int data);
AVLNode * minValueNode(AVLNode* node);
AVLNode* deleteNode(AVLNode* root, int data);

void inorder(AVLNode *root);
void preorder(AVLNode *root);
void postorder(AVLNode *root);



