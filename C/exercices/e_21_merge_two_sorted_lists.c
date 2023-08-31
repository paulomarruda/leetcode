#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/linear.h"

Node *mergeSortedLists(Node *list1, Node *list2){
    Node *dummy_head = malloc(sizeof(Node));
    int dummy_data = -101;
    dummy_head->data = &dummy_data;
    dummy_head->next = NULL;
    Node *current = dummy_head;
    int value1;
    int value2;
    while (list1 && list2){
        if (list1) { value1 = *( (int *) list1->data); }
        else { value1 = 101; }
        if (list2) { value2 = *( (int *) list2->data); }
        else { value1 = 101; }
        if (value1 <= value2){
            current->next = list1;
            list1 = list1->next;
            current = current->next;
        } else{
            current->next = list2;
            list2 = list2->next;
            current = current->next;
        }
    }
    if (!list1 && list2){ current->next = list2; }
    else if (!list2 && list1) {current->next = list1; }
    current = dummy_head;
    dummy_head = dummy_head->next;
    free(current);
    return dummy_head;
}

int main(){
    Node *list1 = NULL;
    Node *list2 = NULL;
    int arr1[3] = {4,3,1};
    int arr2[3] = {4,2,1};
    for (int i=0; i<3; i++){
        (void) prependLinkedList(&list1, &arr1[i]);
        (void) prependLinkedList(&list2, &arr2[i]);
    }
    printf("The lists: \n");
    printLinkedList(list1, printInt);
    printLinkedList(list2, printInt);
    Node *merged = mergeSortedLists(list1, list2);
    printLinkedList(merged, printInt);
    return 0;
}
