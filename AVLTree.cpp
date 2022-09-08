#include "AVLTree.h"

int height(AVLNode *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

AVLNode* newNode(int key)
{
    AVLNode* node = new AVLNode();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return(node);
}

AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *z = x->right;

    x->right = y;
    y->left = z;


    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    return x;
}

AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *z = y->left;


    y->left = x;
    x->right = z;

    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}

int getBalance(AVLNode *difference)
{
    if (difference == nullptr)
        return 0;
    return height(difference->left) - height(difference->right);
}

AVLNode* insert(AVLNode* node, int key)
{

    if (node == nullptr)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);



    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
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

AVLNode* deleteNode(AVLNode* root, int key)
{
    if (root == nullptr)
        return root;


    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    else
    {
        // node with only one child or no child
        if( (root->left == nullptr) ||
            (root->right == nullptr) )
        {
            AVLNode *temp = root->left ?
                            root->left :
                            root->right;

            // No child case
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else // One child case
                *root = *temp;
            free(temp);
        }
        else
        {
            AVLNode* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));


    int balance = getBalance(root);


    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
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
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(AVLNode *root)
{
    if(root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void postorder(AVLNode *root)
{
    if(root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}