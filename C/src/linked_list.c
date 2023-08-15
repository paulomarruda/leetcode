#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list.h"
#include <stdio.h>

#define MAX_PRINT 100

Node* constructLinkedList(const int data){
    Node* head = malloc(sizeof(Node));
    if (head == NULL){ return NULL; }
    
    head->data = data;
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
    while (head != NULL && i < 100){
        printf("%d,", head->data);
        head = head->next;
        i++;
    }
    if (i == MAX_PRINT){
        printf("...");
    }
    printf(">\n");
}

bool insertLinkedList(Node** phead, const int data){
    Node* new_node = constructLinkedList(data);
    if (new_node == NULL){ return false; }
    if (*phead == NULL){ 
        *phead = new_node; 
        return true;
    }
    Node* current = *phead;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
    return true;
}

Node* findNsliceLinkedList(Node* head, const int target){
    while (head != NULL){
        if (head->data == target)
            { return head; }
        head = head->next;
    }
    return NULL;
}

bool removeLinkedList(Node** phead, const int target);

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
