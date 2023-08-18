#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

Node* invertLinkedList(Node* head){
    // empty list 
    if (head == NULL){ return NULL; }
    // list of one element
    else if (head->next == NULL){ return head; }

    Node* new_head = head->next;
    Node* tmp = new_head->next;
    new_head->next = head;
    head->next = tmp;
    return new_head;
}

int main(){
    Node* head = NULL;
    for (int i=0; i<10; i++){
        prependLinkedList(&head, i);
    }
    printf("Original list: ");
    printLinkedList(head);

    head = invertLinkedList(head);
    printLinkedList(head);
    return 0;
}
