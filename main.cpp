#include "AVLTree.h"
#include "RedBlackTree.h"

int main()
{
    RedBlackTree tree;

    tree.insertNode(15);
    tree.insertNode(9);
    tree.insertNode(21);
    tree.insertNode(4);
    tree.insertNode(10);
    tree.insertNode(6);
    tree.insertNode(2);
    tree.insertNode(7);

    cout << "-----------------------\n\n";
    cout << "RedBlack Tree \n\n";
//  (Left, Root, Right)
    cout << "Inorder Traversal \n";
    tree.inorder();

//  (Root, Left, Right)
    cout << "\n\nPreorder Traversal \n";
    tree.preorder();

//  (Left, Right, Root)
    cout << "\n\nPostOrder Traversal \n";
    tree.postorder();


    AVLNode *root = nullptr;


    root = insert(root, 14);
    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 16);
    root = insert(root, 21);
    root = insert(root, 23);

    cout << "\n\n-----------------------  \n";
    cout << "\nAVL Tree \n\n";



    //  (Left, Root, Right)
    cout << "Inorder Traversal \n";
    inorder(root);

    cout <<"\n\nAfter DELETING";
    root = deleteNode(root, 10);

//  (Root, Left, Right)
    cout << "\n\nPreorder Traversal \n";
    preorder(root);

//  (Left, Right, Root)
    cout << "\n\nPostorder Traversal \n";
    postorder(root);

    return 0;
}
