#include <bits/stdc++.h>
using namespace std;

enum Color {
    BLACK,
    RED
};

struct RBNode
{
    RBNode *left,
    *right,
    *parent;
    int data;
    bool color;

    RBNode(int data)
    {
        left =  nullptr;
        right = nullptr;
        parent = nullptr;
        this->color = RED;
        this->data = data;
    }
};

class RedBlackTree
{
private:
    RBNode *root;
public:
    RedBlackTree() {
        root = nullptr;
    }

    void insertNode(const int &n);
    void inorder();
    void preorder();
    void postorder();

    void leftRotate(RBNode *&, RBNode *&);
    void rightRotate(RBNode *&, RBNode *&);
    void fixBadNodePosition(RBNode *&, RBNode *&);
};

void inorderPrint(RBNode *root);
void preorderPrint(RBNode *root);
void postorderPrint(RBNode *root);


RBNode* RedBlackTreeInsert(RBNode* root, RBNode *pt);












