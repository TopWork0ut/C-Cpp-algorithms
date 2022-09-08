#include "RedBlackTree.h"


void inorderPrint(RBNode *root)
{
    if (root == nullptr)
        return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

void preorderPrint(RBNode *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    inorderPrint(root->left);
    inorderPrint(root->right);
}

void postorderPrint(RBNode *root)
{
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

void RedBlackTree::leftRotate(RBNode *&root, RBNode *&pt)
{
    RBNode *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != nullptr)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RedBlackTree::rightRotate(RBNode *&root, RBNode *&pt)
{
    RBNode *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != nullptr)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

// This function fixes violations
// caused by BST insertion
void RedBlackTree::fixBadNodePosition(RBNode *&root, RBNode *&pt)
{
    RBNode *parent_pt = nullptr;
    RBNode *grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /* Case : A
            Parent of pt is left child
            of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {

            RBNode *uncle_pt = grand_parent_pt->right;

            /* Case : 1
            The uncle of pt is also red
            Only Recoloring required */
            if (uncle_pt != nullptr && uncle_pt->color ==
                                       RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }

            else
            {
                /* Case : 2
                pt is right child of its parent
                Left-rotation required */
                if (pt == parent_pt->right)
                {
                    leftRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                pt is left child of its parent
                Right-rotation required */
                rightRotate(root, grand_parent_pt);
                swap(parent_pt->color,
                     grand_parent_pt->color);
                pt = parent_pt;
            }
        }

            /* Case : B
            Parent of pt is right child
            of Grand-parent of pt */
        else
        {
            RBNode *uncle_pt = grand_parent_pt->left;

            /* Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != nullptr) && (uncle_pt->color ==
                                          RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                pt is left child of its parent
                Right-rotation required */
                if (pt == parent_pt->left)
                {
                    rightRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                pt is right child of its parent
                Left-rotation required */
                leftRotate(root, grand_parent_pt);
                swap(parent_pt->color,
                     grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

void RedBlackTree::insertNode(const int &data)
{
    RBNode *pt = new RBNode(data);

    root = RedBlackTreeInsert(root, pt);

    fixBadNodePosition(root, pt);
}

RBNode* RedBlackTreeInsert(RBNode* root, RBNode *pt)
{
    /* If the tree is empty, return a new node */
    if (root == nullptr)
        return pt;

    /* Otherwise, recur down the tree */
    if (pt->data < root->data)
    {
        root->left = RedBlackTreeInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = RedBlackTreeInsert(root->right, pt);
        root->right->parent = root;
    }

    /* return the (unchanged) node pointer */
    return root;
}