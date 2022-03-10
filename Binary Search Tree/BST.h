#pragma once

#include "BSTStructure.h"
#include "BSTSearch.h"

static bool isNodeEmpty(BSTNode* root)
{
    return root == null;
}

static BSTNode* insertBSTNode(BSTNode *root, int info)
{
    if(isNodeEmpty(root))
    {
        root = createBSTNode(info);
    }
    else if(root->info > info)
    {
        root = insertBSTNode(root->left, info);
    }
    else if(root->info < info)
    {
        root = insertBSTNode(root->right, info);   
    }

    return root;
}