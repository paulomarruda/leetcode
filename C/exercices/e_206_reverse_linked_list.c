#include <stdlib.h>
#include "../include/linked_list.h"
/*
 * Problem
 * --------
 *  Given a linked list, return the reverse list.
 *
 *  Constraints
 *  -----------
 *
 *  Solution
 *  ---------
 *  We take advantage that the structure is ordered.
 *  In the iterative way, we inverse the order of the list:
 *  each node will point backwards instead of foward.
 */

int main() {
    Node* head = NULL;
    for (int i = 0; i < 1500; i++) {
        prependLinkedList(&head, i);
    }
    head = inverseLinkedList(head);
    printLinkedList(head);
    return 0;
}
