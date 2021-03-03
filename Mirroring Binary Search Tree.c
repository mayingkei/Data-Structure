#include <stdio.h>
#include <stdlib.h>
typedef struct btCDT bt;
struct btCDT {
    int val;
    bt *left;
    bt *right;
};

bt* Mirror(bt* tree);

// This is just an example.
// The real test cases will be more complex.
// You also can change this function to test your code.
bt* TreeGenerator()
{
    bt* tree = (bt*)malloc(sizeof(bt));
    tree->val = 3;
    tree->right = (bt*)malloc(sizeof(bt));
    tree->right->val = 4;
    tree->right->right = NULL;
    tree->right->left = NULL;
    tree->left = (bt*)malloc(sizeof(bt));
    tree->left->val = 2;
    tree->left->right = NULL;
    tree->left->left = (bt*)malloc(sizeof(bt));
    tree->left->left->val = 1;
    tree->left->left->right = NULL;
    tree->left->left->left = NULL;
    return tree;
}
int main() {
    bt* tree = TreeGenerator();
    tree = Mirror(tree);
    return 0;
}


// Please finish this function implementation.
bt* Mirror(bt* tree)
{
    bt* newtree = (bt*)malloc(sizeof(bt));
    newtree->val = tree->val;

    if (tree->left != NULL) {
        newtree->right = Mirror(tree->left);
    }
    if (tree->right != NULL) {
        newtree->left = Mirror(tree->right);
    }

    return newtree;
}