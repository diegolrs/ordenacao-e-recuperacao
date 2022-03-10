#pragma once

#include "BSTStructure.h"
#include "../Utils/syntaxUtil.h"

static BSTNode* search(BSTNode* root, int info)
{
    if(root == null) 
        return null;
    else if(root->info > info)
        return search(root->left, info);
    else if(root->info < info)
        return search(root->right, info);
    else
        return root;
}