#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct bstCDT bst;
struct bstCDT {
    int val;
    bst *left;
    bst *right;
};

//function to find val with smallest difference
void finddiff(bst* tree, int num, int &d, int &a) {
    if (tree != NULL) {

        if (tree->val == num) {
            a = num;
            return;
        }

        if (abs(tree->val - num) < d) {
            d = abs(tree->val - num);
            a = tree->val;
        }

        if (abs(tree->val - num) == d) {
            if(tree->val < a)
                a = tree->val;
        }

        if (tree->val > num)
            finddiff(tree->left, num, d, a);
        else
            finddiff(tree->right, num, d, a);

    }
}

// This is just an example.
// The real test cases will be more complex.
// You also can change this function to test your code.
bst* TreeGenerator()
{
    bst* tree = (bst*)malloc(sizeof(bst));
    tree->val = 3;
    tree->right = (bst*)malloc(sizeof(bst));
    tree->right->val = 5;
    tree->right->right = NULL;
    tree->right->left = NULL;
    tree->left = (bst*)malloc(sizeof(bst));
    tree->left->val = 2;
    tree->left->right = NULL;
    tree->left->left = (bst*)malloc(sizeof(bst));
    tree->left->left->val = 0;
    tree->left->left->right = NULL;
    tree->left->left->left = NULL;
    return tree;
}

// This is just an example.
int NumGenerator()
{
    return 1;
}

int Find_closest(bst* tree, int num);

int main() {
    bst* tree = TreeGenerator();
    int num = NumGenerator();
    int ans = Find_closest(tree, num);
    // For this example, the ans is 3;
    printf("%d\n", ans);
    return 0;
}

// Please finish this function implementation.
int Find_closest(bst* tree, int num)
{
    int temp = INT_MAX, res = INT_MAX;

    finddiff(tree, num, temp, res);

    return res;
}