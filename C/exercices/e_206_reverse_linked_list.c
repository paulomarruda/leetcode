#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/linear.h"
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
    int arr[20];
    for (int i=0; i<20; i++){
        arr[i] = i;
        prependLinkedList(&head, &arr[i]);
    }
    printf("Before:\n");
    printLinkedList(head, printInt);
    head = inverseLinkedList(head);
    printf("After inversion: \n");
    printLinkedList(head, printInt);
    destructLinkedList(&head);
    return 0;
}
