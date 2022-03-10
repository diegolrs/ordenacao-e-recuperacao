#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode BSTNode;

struct bstNode 
{
    int info;
    BSTNode* left;
    BSTNode* right;
};