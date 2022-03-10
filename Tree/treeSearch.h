#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "syntaxUtil.h"
#include "tree.h"

Node* getLastNode(Node* n);
bool contains(Tree* t, int info);
bool containsInNode(Node* n, int info);
Node* findNodeWithInfo(Tree* t, int info);
Node* getFirstOrDefault(Node* n, int info);

bool contains(Tree* t, int info)
{
	return containsInNode(t->root, info);
}

bool containsInNode(Node* n, int info)
{
	if(n == null)
		return false;
		
	if(n->info == info)
		return true;
		
	if(containsInNode(n->left, info))
		return true;
		
	if(containsInNode(n->right, info))
		return true;
		
	return false;
}

Node* findNodeWithInfo(Tree* t, int info)
{
    return getFirstOrDefault(t->root, info);
}

Node* getFirstOrDefault(Node* n, int info)
{
    if(n == null)
        return null;

    if(n->info == info)
        return n;
    else if(getFirstOrDefault(n->left, info) != null)
        return n->left;
    else if(getFirstOrDefault(n->right, info) != null)
        return n->right;

    return null;
}

Node* getLastNode(Node* n)
{
    if(n == null)
        return null;

    int leftSize = heightOfNode(n->left);
    int rightSize = heightOfNode(n->right);

    if(n->left != null && leftSize >= rightSize)
    {
        return getLastNode(n->left);
    }
    else if(n->right != null)
    {
        return getLastNode(n->right);
    }
    else
    {
        return n;
    }
}

void insertNode(Tree* t, Node* child)
{
    addChildToNode(getLastNode(t->root), child) ;
}