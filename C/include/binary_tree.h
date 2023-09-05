

#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "comparison_functions.h" 

typedef struct BTreeNode {
    void *data;
    unsigned int amount;
    struct BTreeNode *parent;
    struct BTreeNode *left;
    struct BTreeNode *right;
} BTreeNode; 

BTreeNode *constructBT(void *rootdata);

void destructBT(BTreeNode *bt);
// inserts 
bool insertBT(BTreeNode **bt, void *data);

bool searchBT(BTreeNode *bt, void *data, ArithmeticComparisonFun lessThanFun, 
              ArithmeticComparisonFun isEqualFun);

#endif 
