#include <stdio.h>
#include <stdlib.h>
#include "../include/linear.h"

int main(){
    Node* head = NULL;
    int data[5] = {10,5,8,9,16};
    for(int i=0; i<5; i++){
        prependLinkedList(&head, &data[i]);
    }
    for(int i=0; i<5; i++){
        prependLinkedList(&head, &data[i]);
    }
    printLinkedList(head, printInt);
    return 0;

}
