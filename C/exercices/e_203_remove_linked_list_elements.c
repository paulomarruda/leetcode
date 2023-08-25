#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linear.h"

Node* removeAll(Node* head, void *data, ArithComparisonFun comFun, bool inplace);

int main(){
    Node* head = NULL;
    int data = 10;
    int a = 10;
    int b = 1;
    int c = 10;
    prependLinkedList(&head, &a);
    prependLinkedList(&head, &b);
    prependLinkedList(&head, &c);
    
    return 0;
}

