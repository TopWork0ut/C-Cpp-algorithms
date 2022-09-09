#include "RedBlackTree.h"

void inorderPrint(RBNode *root) {
    if (root == nullptr)
        return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

void preorderPrint(RBNode *root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    inorderPrint(root->left);
    inorderPrint(root->right);
}

void postorderPrint(RBNode *root) {
    if (root == nullptr)
        return;

    inorderPrint(root->left);
    inorderPrint(root->right);
    cout << root->data << " ";
}

void RedBlackTree::inorder() {
    inorderPrint(root);
}

void RedBlackTree::preorder() {
    preorderPrint(root);
}

void RedBlackTree::postorder() {
    postorderPrint(root);
}

void RedBlackTree::leftRotate(RBNode *&root, RBNode *&node) {
    RBNode *node_right = node->right;

    node->right = node_right->left;

    if (node->right != nullptr)
        node->right->parent = node;

    node_right->parent = node->parent;

    if (node->parent == nullptr)
        root = node_right;

    else if (node == node->parent->left)
        node->parent->left = node_right;

    else
        node->parent->right = node_right;

    node_right->left = node;
    node->parent = node_right;
}

void RedBlackTree::rightRotate(RBNode *&root, RBNode *&node) {
    RBNode *node_left = node->left;

    node->left = node_left->right;

    if (node->left != nullptr)
        node->left->parent = node;

    node_left->parent = node->parent;

    if (node->parent == nullptr)
        root = node_left;

    else if (node == node->parent->left)
        node->parent->left = node_left;

    else
        node->parent->right = node_left;

    node_left->right = node;
    node->parent = node_left;
}


void RedBlackTree::fixBadNodePosition(RBNode *&root, RBNode *&node) {
    RBNode *parent_node = nullptr;
    RBNode *grand_parent_node = nullptr;

    while ((node != root) && (node->color != BLACK) &&
           (node->parent->color == RED))
    {

        parent_node = node->parent;
        grand_parent_node = node->parent->parent;


        if (parent_node == grand_parent_node->left)
        {

            RBNode *uncle_node = grand_parent_node->right;

            if (uncle_node != nullptr && uncle_node->color ==
                                       RED)
            {
                grand_parent_node->color = RED;
                parent_node->color = BLACK;
                uncle_node->color = BLACK;
                node = grand_parent_node;
            }

            else
            {
                if (node == parent_node->right)
                {
                    leftRotate(root, parent_node);
                    node = parent_node;
                    parent_node = node->parent;
                }

                rightRotate(root, grand_parent_node);
                swap(parent_node->color,
                     grand_parent_node->color);
                node = parent_node;
            }
        }

        else
        {
            RBNode *uncle_pt = grand_parent_node->left;

            if ((uncle_pt != nullptr) && (uncle_pt->color ==
                                          RED))
            {
                grand_parent_node->color = RED;
                parent_node->color = BLACK;
                uncle_pt->color = BLACK;
                node = grand_parent_node;
            }
            else
            {
                if (node == parent_node->left)
                {
                    rightRotate(root, parent_node);
                    node = parent_node;
                    parent_node = node->parent;
                }

                leftRotate(root, grand_parent_node);
                swap(parent_node->color,
                     grand_parent_node->color);
                node = parent_node;
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::insertNode(const int &data) {
    RBNode *node = new RBNode(data);
    root = RedBlackTreeInsert(root, node);
    fixBadNodePosition(root, node);
}

RBNode* RedBlackTreeInsert(RBNode* root, RBNode *node)
{
    if (root == nullptr)
        return node;

    if (node->data < root->data)
    {
        root->left = RedBlackTreeInsert(root->left, node);
        root->left->parent = root;
    }
    else if (node->data > root->data)
    {
        root->right = RedBlackTreeInsert(root->right, node);
        root->right->parent = root;
    }
    return root;
}