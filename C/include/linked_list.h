#pragma once
#include <stdbool.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node{
    int data;
    int num_nexts;
    struct Node* next;
} Node;


Node* constructLinkedList(const int data);

void destructLinkedList(Node** phead);

void printLinkedList(Node* head);

bool prependLinkedList(Node** phead, const int data);

Node* inverseLinkedList(Node* head);

int lengthLinkedList(Node* head);

Node* findNsliceLinkedList(Node* head, const int target);

void appendLinkedList(Node** phead, Node* other);

bool removeLinkedList(Node** phead, const int data);

bool removeAllLinkedList(Node* head, const int data);

#endif
