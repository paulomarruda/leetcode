/*
 * Given the head of a sorted linked list, 
 * delete all duplicates such that each element 
 * appears only once. Return the linked list sorted as well.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linear.h"

Node* removeDuplicates(Node* list, bool inplace){
    Node* current = list;
    if (!current){ return current; }
    Node *next;
    void *elem;
    while(current){
        elem = current->data;
        next = current->next;
        if (next){
            if ( areEqualInt(elem, next->data) ){
                current->next = next->next;
                if (inplace) { free(next); }
            } else { current = next; }
        } else { break; }
    }
    return list;
}

int main(){
    Node* head = NULL;
    int arr[10];
    for (int i=0; i<10; i++){
        arr[i] = i;
        prependLinkedList(&head, &arr[i]);
        prependLinkedList(&head, &arr[i]);
        prependLinkedList(&head, &arr[i]);
        prependLinkedList(&head, &arr[i]);
    }
    printf("Before: \n");
    printLinkedList(head, printInt);
    printf("After: \n");
    head = removeDuplicates(head, true);
    printLinkedList(head, printInt);
    destructLinkedList(&head);
    return 0;
}
