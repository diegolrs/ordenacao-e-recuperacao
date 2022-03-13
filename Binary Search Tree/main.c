#include <stdio.h>
#include <stdlib.h>
#include "../Utils/syntaxUtil.h"
#include "BST.h"

int main()
{
    BSTNode* root = createBSTNode(10);
    insertBSTNode(root, 11);
    insertBSTNode(root, 12);
    insertBSTNode(root, 8);
    insertBSTNode(root, 9);

    printBSTNode(root);

    puts("ola mundo");

    return 0;
}