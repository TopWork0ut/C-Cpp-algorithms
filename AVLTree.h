// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
class AVLNode
{
public:
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;
};

int height(AVLNode *N);
int max(int a, int b);

AVLNode* newNode(int key);
AVLNode *rightRotate(AVLNode *y);
AVLNode *leftRotate(AVLNode *x);

int getBalance(AVLNode *difference);
AVLNode* insert(AVLNode* node, int key);
AVLNode * minValueNode(AVLNode* node);
AVLNode* deleteNode(AVLNode* root, int key);

void inorder(AVLNode *root);
void preorder(AVLNode *root);
void postorder(AVLNode *root);



