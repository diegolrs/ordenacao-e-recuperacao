#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct tree Tree;

struct node 
{
    int info;
    Node* left;
    Node* right;
};

struct tree
{
    Node* root;
};