#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

typedef struct bstCDT bst;
struct bstCDT {
    int val;
    bst *left;
    bst *right;
    int height;
};

//get all value in tree and sort in order
void getvalue(bst* tree, vector<int> &num){
    if (tree != NULL) {
        getvalue(tree->left, num);
        num.push_back(tree->val);
        getvalue(tree->right, num);
    }
}

//check whether the orignial tree is balanced
void checkbalance(bst* tree, int &i) {
    if (tree->left != NULL && tree->right != NULL) {
        int l = tree->left->height;
        int r = tree->right->height;

        i = abs(l - r);

        if (i > 1)
            return;

        checkbalance(tree->left, i);
        checkbalance(tree->right, i);
    }
}

//create a balanced bst using the middle value as root
bst* makebst(vector<int> num, int head, int tail) {
    if (head <= tail) {
        int mid = (head + tail) / 2;

        bst* newtree = (bst*)malloc(sizeof(bst));
        newtree->val = num[mid];
        newtree->left = makebst(num, head, mid - 1);
        newtree->right = makebst(num, mid + 1, tail);

        return newtree;
    }
    else return NULL;
}

//function to get the height of each node
int getheight(bst* tree) {
    if (tree == NULL)
        return -1;

    int l = getheight(tree->left);
    int r = getheight(tree->right);

    if (l > r)
        return l + 1;
    else
        return r + 1;
}

//function to renew the height of each node in the balanced bst
void newheight(bst* tree) {
    tree->height = getheight(tree);
    if (tree->left != NULL) 
        newheight(tree->left);
    if (tree->right != NULL)
        newheight(tree->right);
}

//function to display the bst preorderly
void display(bst* t) {
    if (t != NULL) {
        cout << t->val << " ";
        display(t->left);
        display(t->right);
    }
}

// This is just an example.
// The real test cases will be more complex.
// You also can change this function to test your code.
bst* TreeGenerator()
{
    bst* tree = (bst*)malloc(sizeof(bst));
    tree->val = 3;
    tree->height = 3;
    tree->right = (bst*)malloc(sizeof(bst));
    tree->right->val = 4;
    tree->right->height = 0;
    tree->right->right = NULL;
    tree->right->left = NULL;
    tree->left = (bst*)malloc(sizeof(bst));
    tree->left->val = 2;
    tree->left->height = 2;
    tree->left->right = NULL;
    tree->left->left = (bst*)malloc(sizeof(bst));
    tree->left->left->val = 1;
    tree->left->left->height = 1;
    tree->left->left->right = NULL;
    tree->left->left->left = (bst*)malloc(sizeof(bst));
    tree->left->left->left->val = 0;
    tree->left->left->left->left = NULL;
    tree->left->left->left->right = NULL;
    return tree;
}

bst* Rebuild(bst* tree);

int main() {
    bst* tree = TreeGenerator();
    display(tree);
    tree = Rebuild(tree);
    display(tree);
    return 0;
}

// Please finish this function implementation.
bst* Rebuild(bst* tree)
{
    int i = 0;
    checkbalance(tree, i);

    if (i > 1) {
        vector<int> num;
        getvalue(tree, num);

        int tail = num.size() - 1;

        bst* newtree = makebst(num, 0, tail);
        newheight(newtree);

        return newtree;
    }
    else
        return tree;
}