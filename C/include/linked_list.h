/*
 * @file linked_list.h
 * @author a000040
 * @date 19 Aug 2023
 * @brief Header file for the (singly) linked list 
 *
 * Implementation of the linked list struct and basic 
 * methods.
 * \cite Algorithms
 *
 */

#pragma once
#include <stdbool.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
 * @brief the limplementation of the node carries 
 * the number of next nodes in itself so that 
 * the length function of the linked list 
 * returns in O(1) time. This change needs more space, 
 * but saves time.
 *
 * @param data Stores the data of the node.
 * @param num_nexts Stores the number of the next nodes
 * with respect to the current node.
 * @param next Pointer to the next node.
*/
typedef struct Node{
    int data;
    int num_nexts;
    struct Node* next;
} Node;

/*
 * @brief By default the constructor constructs 
 * the head with a value. For setting up a empty linked list
 * use "Node* head = NULL;".
 *
 * @param data The data to be added 
 *
 * @return The new head: NULL if the allocation of the memory 
 * failed or the head pointing to the node containing the data and 
 * pointing to NULL if allocation succeded.
 *
 * @see destructLinkedList
*/
Node* constructLinkedList(const int data);

/*
 * @brief destructor for the linked list.
 *
 * @param phead Pointer pointing to the head.
 *
 * @see constructLinkedList
*/
void destructLinkedList(Node** phead);

/*
 * @brief This printer function is set to print at most
 * 50 elements.
 *
 * @param head The head of the linked list.
*/
void printLinkedList(Node* head);

/*
 * @brief Adds a new node containing the passed data to 
 * the list as the new head.
 *
 * @param phead Pointer pointing to the head of the list
 * @param data data to be prepend.
 *
 * @return true if the prepend operation was successeful or 
 * false otherwise. The false return indicates that the 
 * memory alloction for the new head failed.
*/
bool prependLinkedList(Node** phead, const int data);

/*
 * @brief inverts the list using boundary methods.
 *
 * @param head The head of the list.
*/
Node* inverseLinkedList(Node* head);

/*
 * @brief Returns the length in O(1) time.
 *
 * @param head The head of the list.
*/
int lengthLinkedList(Node* head);

bool findLinkedList(Node* head, const int data);

void appendLinkedList(Node** phead, Node* other);

/*
 * @brief Remove the node containing the first occurrence 
 * of the data passed.
 *
 * @param phead Pointer pointing to the head of the list
 * @param data The data whose node is to be removed
 *
 * @return The new list with the desired node removed, if found, or 
 * NULL list if the node was not found
 *
 * @note: (TODO) return the modified list instead of modifying 
 * the list
*/
Node* removeLinkedList(Node* head, const int data);

Node* removeAllLinkedList(Node* head, const int data);

Node* linkedListFromArray(int arr[], int size);

#endif
