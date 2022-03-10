#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "syntaxUtil.h"
#include "treeStructure.h"

Tree* createTree(Node* rootNode);
Node* createNode(int info);

void printNode(Node* n);
void printTree(Tree* t);

bool compareInfo(Node* node, int info);

int heightOfNode(Node* node);
void addChildToNode(Node* child, Node* parent);
void insertNode(Tree* t, Node *node);

Tree* createTree(Node* rootNode)
{
    Tree* t = (Tree*) malloc(sizeof(struct tree));

    if(t == null)
        return null;
    else
    {
        t->root = rootNode;
        return t;
    }
}

Node* createNode(int info)
{
    Node* n = (Node*) malloc(sizeof(struct node));

    if(n == null)
        return null;
    else
    {
        n->left = null;
        n->right = null;
        n->info = info;

        return n;
    }
}

void printNode(Node* n)
{
    if(n == null)
        return;

    printNode(n->left);
    printf("%d ", n->info);
    printNode(n->right);
}

void printTree(Tree* t)
{
    if(t == null)
        return;

    printNode(t->root);
}

bool compareInfo(Node* node, int info)
{
    return node != null && node->info == info;
}

int heightOfNode(Node* node)
{
    if (node == null)  
        return 0;  
    else
        return(heightOfNode(node->left) + 1 + heightOfNode(node->right));  
}

void addChildToNode(Node* parent, Node* child)
{
    if(parent->left == null)
        parent->left = child;
    else if(parent->right == null)
        parent->right = child;
}