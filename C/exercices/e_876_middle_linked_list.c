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


int main(){
    Node* head;
    for (int i=0; i<20; i++){
        prependLinkedList(&head, i);
    }
    printLinkedList(head);

    Node* begin = head;
    Node* middle = begin->next;
    Node* end = middle->next;
    Node* fast = middle->next;

    printf("B: %d M: %d E: %d F: %d\n", begin->data, middle->data, end->data, fast->data);

    begin = begin->next;
    middle = middle->next;
    end = end->next;
    fast = (fast->next)->next;
    printf("B: %d M: %d E: %d F: %d\n", begin->data, middle->data, end->data, fast->data);

    return 0;
}
