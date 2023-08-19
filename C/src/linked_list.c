#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list.h"
#include <stdio.h>

#define MAX_PRINT 50

Node* constructLinkedList(const int data){
    Node* head = malloc(sizeof(Node));
    if (head == NULL){ return NULL; }
    
    head->data = data;
    head->num_nexts = 0;
    head->next = NULL;
    return head;
}

void destructLinkedList(Node** phead){
    Node* current = *phead;
    Node* tmp;
    while(current != NULL){
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *phead = NULL;
}

void printLinkedList(Node* head){
    int i = 0;
    printf("<");
    while (head != NULL && i < MAX_PRINT){
        printf("%d,", head->data);
        head = head->next;
        i++;
    }
    if (i == MAX_PRINT){
        printf("...");
    }
    printf(">\n");
}

bool prependLinkedList(Node** phead, const int data){
    Node* new_node = constructLinkedList(data);
    if (new_node == NULL){ return false; }
    if (*phead == NULL){ 
        *phead = new_node;
        return true;
    }
    Node* head = *phead;
    new_node->next = head;
    new_node->num_nexts = head->num_nexts + 1;
    *phead = new_node;
    return true;
};

Node* inverseLinkedList(Node* head){
    if (head == NULL){ return NULL; }
    Node* begin = head;
    Node* middle = NULL;
    Node* end = NULL;
    while(begin->next != NULL){
        middle = begin->next;
        end = middle->next;
        begin->next = end;
        middle->next = head;
        head = middle;
    }
    return head;
}

int lengthLinkedList(Node* head){
    if (head == NULL){ return 0; }
    else {return head->num_nexts + 1;}
}

bool findLinkedList(Node* phead, const int data);

Node* removeLinkedList(Node* head, const int target);

Node* removeAllLinkedList(Node* head, const int data);

void appendLinkedList(Node** phead, Node *other){
    if (*phead == NULL){
        *phead = other;
        return;
    }
    Node* current = *phead;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = other;
}

Node* linkedListFromArray(int arr[], int size){
    Node* head = NULL;
    for (int i=0; i<size; i++){
        prependLinkedList(&head, arr[size-1-i]);
    }
    return head;
}
