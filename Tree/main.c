#include <stdio.h>
#include <stdlib.h>
#include "syntaxUtil.h"
#include "tree.h"
#include "treeSearch.h"
#include "destruction.h"

int main()
{
    Node* l1 = createNode(1);
    Node* l2 = createNode(2);
    Node* root = createNode(0);
    Tree* tree = createTree(root);

    root->left = l1;
    root->right = l2;

    l1->left = createNode(3);
    l1->right = createNode(4);
    l1->right->right = createNode(5);
    l2->left = createNode(6);
    l2->left->right = createNode(7);
    l2->left->right->left = createNode(8);
    l2->left->right->left->left = createNode(9);

    insertNode(tree, createNode(10));
    insertNode(tree, createNode(11));
    insertNode(tree, createNode(12));

    printTree(tree);
    puts("");

    destroyNode(&(tree->root->left));
    printTree(tree);

    int infoToSearch = 2;
    if(contains(tree, infoToSearch))
    {
        printf("was able to find number %d \n", findNodeWithInfo(tree, infoToSearch)->info);
    }
    else
    {
        puts("tree does not contains this value\n");
    }
    
    printf("size of tree: %d \n", heightOfNode(tree->root));
    printf("last node info %d \n", getLastNode(tree->root)->info);

    return 0;
}