#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Utils/syntaxUtil.h"

typedef struct bstNode BSTNode;

struct bstNode 
{
    int info;
    BSTNode* left;
    BSTNode* right;
};

void printBSTNode(bstNode* node)
{
    if(node == null)
        return;

    printBSTNode(node->left);
    printf("%d ", node->info);
    printBSTNode(node->right);
}