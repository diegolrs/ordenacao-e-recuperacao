#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "syntaxUtil.h"
#include "treeStructure.h"

void safeDestroyNode(Node **node);
void destroyNode(Node** n);
void destroyTree(Tree* tree);

void safeDestroyNode(Node **node)
{
    if(*node != null)
    {
        printf("node destroyed %d\n", (&**node)->info);
        free(*node);
        (*node) = null;

    }
    else
        puts("node already is null");
}

void destroyNode(Node** n)
{
    if(*n != null)
    {
        destroyNode(&((*n)->left));
        destroyNode(&((*n)->right));

        safeDestroyNode(n);
    }
}

void destroyTree(Tree* tree)
{
    if(tree != null)
    {
        destroyNode(&(tree->root));
        tree = null;
    }
}