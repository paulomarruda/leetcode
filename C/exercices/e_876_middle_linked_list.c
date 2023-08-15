#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h" 
/*
 * Problem
 * -------
 * Given a non-empty linked list, return its middle (if even odd, one 
 * element or, if odd size, two elements).
 *
 * Constrains
 * ----------
 *  - 1<= size(linked_list) <= 100
 *  - 0 <= node->data <= 100
 *
 * Approach
 * --------
 * Using two pointers, we loop over the linked list.
 * The slow pointer is incremented linearly by x1 
 * while the fast pointer is incremented linearly x2.
 * The loop ends when fast reaches the tail of the 
 * linked list.
 *
 * Complexity
 * ----------
 *  time: O(N)
 *  space:
 */

Node* middleNode(Node* head){
    if (head == NULL){
        return NULL;
    }
    //using head as the slow pointer
    Node* fast = head;
    Node* middle = NULL;
    while (fast != NULL){
        //number of "nexts" reaches the end
        //in a odd number of cases, i.e. the 
        // size of the list is odd
        if (fast->next == NULL){
            insertLinkedList(&middle, head->data);
            return middle;
        } else if ((fast->next)->next == NULL){
            // even case
            insertLinkedList(&middle, head->data);
            head = head->next;
            break;
        } else{
            fast = (fast->next)->next;
        }
        head = head->next;
    }
    insertLinkedList(&middle, head->data);
    return middle;
}

int main(){
    Node* head = NULL;
    // Size ODD
    for (int i=0; i<1000; i++){
        insertLinkedList(&head, i);
    }
    printLinkedList(head);
    Node* middle = middleNode(head);
    printLinkedList(middle);
    middle = NULL;
    head = NULL;
    // size even
    for (int i=0; i<1001; i++){
        insertLinkedList(&head, i);
    }
    printLinkedList(head);
    middle = middleNode(head);
    printLinkedList(middle);
    return 0;
}
