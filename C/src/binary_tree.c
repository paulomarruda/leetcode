#include <stdlib.h>
#include <stdbool.h>
#include "../include/binary_tree.h" 

static BTreeNode *_newNode(BTreeNode *parent, void *data){
    BTreeNode *new_node = malloc(sizeof(BTreeNode));
    // malloc failed
    if (!new_node){ return NULL; }
    new_node->data = data;
    new_node->amount = 1;
    new_node->parent = parent;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

BTreeNode *constructBT(void *rootdata){
    BTreeNode *root = malloc(sizeof(BTreeNode));
    if (!root) { return NULL; }
    root->data = rootdata;
    root->amount = 1;
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;
}

// recursive 
void destructBT(BTreeNode *root){
    if (!root){ return; }
    BTreeNode *left = root->left;
    BTreeNode *right = root->right;
    free(root);
    destructBT(left);
    destructBT(right);
}


bool searchBT(BTreeNode *bt, void *data, ArithmeticComparisonFun lessThanFun, 
         ArithmeticComparisonFun isEqualFun){
    if (!bt){ return false; }
    if ( isEqualFun(bt->data, data) ){ return true; }
    else if ( lessThanFun(data, bt->data) ){ 
        return searchBT(bt->left, data, lessThanFun, isEqualFun);
    } else{
        return searchBT(bt->right, data, lessThanFun, isEqualFun); 
    }
}


