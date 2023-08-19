#include "../include/linked_list.h"
#include <stdio.h>

Node* addTwoNumbers(Node* head1, Node* head2);

int main(){
    int arr1[] = {3,8,8,8,3,3,4};
    int arr2[] = {2,2,1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    Node* head1 = linkedistFromArray(arr1, size1);
    Node* head2 = linkedListFromArray(arr2, size2);
    Node* result = NULL;
    Node* current1 = head1;
    Node* current2 = head2;
    int vaium = 0;
    int sum;
    while (current1->next != NULL || current2->next != NULL){
        sum = current1->data+current2->data;
        if (sum >= 10) {vaium = 1;}
        printf("1: %d 2: %d S: %d vaium: %d\n", current1->data, current2->data, sum, vaium);
        if (current2->next != NULL){ current2 = current2->next; }
        else {current2->data = 0;}
        if (current1->next != NULL){ current1 = current1->next; }
        else {current1->data = 0;}
        vaium = 0;
    }

}
