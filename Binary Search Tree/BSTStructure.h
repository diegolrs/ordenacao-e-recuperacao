#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../Utils/syntaxUtil.h"

typedef struct bstNode BSTNode;

struct bstNode 
{
    int info;
    BSTNode* left;
    BSTNode* right;
};

void printBSTNode(BSTNode* node)
{
    if(node == null)
        return;

    printBSTNode(node->left);
    printf("%d ", node->info);
    printBSTNode(node->right);
}

BSTNode* createBSTNode(int info)
{
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));

    if(node != null)
    {
        node->info = info;

        node->left = null;
        node->right = null;
    }

    return node;
}