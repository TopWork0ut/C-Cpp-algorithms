#include "AVLTree.h"

int getHeightOfTheTree(AVLNode *node)
{
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int fintMaxValue(int valueOne, int valueTwo)
{
    return (valueOne > valueTwo)? valueOne : valueTwo;
}

AVLNode* newNode(int data)
{
    AVLNode* node = new AVLNode();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return(node);
}

AVLNode *rightRotate(AVLNode *grandParent)
{
    AVLNode *parent = grandParent->left;
    AVLNode *z = parent->right;

    parent->right = grandParent;
    grandParent->left = z;


    grandParent->height = fintMaxValue(getHeightOfTheTree(grandParent->left),getHeightOfTheTree(grandParent->right)) + 1;
    parent->height = fintMaxValue(getHeightOfTheTree(parent->left),getHeightOfTheTree(parent->right)) + 1;
    return parent;
}

AVLNode *leftRotate(AVLNode *grandParent)
{
    AVLNode *parent = grandParent->right;
    AVLNode *child = parent->left;


    parent->left = grandParent;
    grandParent->right = child;

    grandParent->height = fintMaxValue(getHeightOfTheTree(grandParent->left),getHeightOfTheTree(grandParent->right)) + 1;
    parent->height = fintMaxValue(getHeightOfTheTree(parent->left),getHeightOfTheTree(parent->right)) + 1;

    return parent;
}

int getHeightDifference(AVLNode *difference)
{
    if (difference == nullptr)
        return 0;
    return getHeightOfTheTree(difference->left) - getHeightOfTheTree(difference->right);
}

AVLNode* insert(AVLNode* node, int data)
{
    if (node == nullptr)
        return(newNode(data));

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + fintMaxValue(getHeightOfTheTree(node->left),getHeightOfTheTree(node->right));

    int balance = getHeightDifference(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

AVLNode * minValueNode(AVLNode* node)
{
    AVLNode* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

AVLNode* deleteNode(AVLNode* root, int data)
{
    if (root == nullptr) {
        return root;
    }

    if ( data < root->data ) {
        root->left = deleteNode(root->left, data);
    }

    else if( data > root->data ) {
        root->right = deleteNode(root->right, data);
    }

    else {
        if( (root->left == nullptr) || (root->right == nullptr) ) {
            AVLNode *tempNode = root->left ? root->left : root->right;
            if (tempNode == nullptr)
            {
                tempNode = root;
                root = nullptr;
            }
            else
                *root = *tempNode;
            free(tempNode);
        }
        else {
            AVLNode* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right,temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + fintMaxValue(getHeightOfTheTree(root->left),getHeightOfTheTree(root->right));

    int balance = getHeightDifference(root);

    if (balance > 1 && getHeightDifference(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getHeightDifference(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getHeightDifference(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getHeightDifference(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preorder(AVLNode *root)
{
    if(root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(AVLNode *root)
{
    if(root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(AVLNode *root)
{
    if(root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}