#pragma once
#ifndef LINEAR_H
#define LINEAR_H

/*
 **************
 * LINKED LISTS 
 **************
*/
/*
 * A linked list node.
 *
 * @brief provides the data type for a singly linked 
 * list node.  The interface accepts a priori any data type, 
 * storing it int a void pointer; hence, if accecess to the value 
 * stored is necessary, the user has to cast the void pointer 
 * in the appropriate type. The interface assumes the linked list 
 * to be the head node.
 * @param data a void pointer pointing to the data stored 
 * by the node.
 * @param next a Node pointer pointing to the next node of the list.
*/
typedef struct Node{
    void *data;
    struct Node *next;
} Node;

/*
 * Constructor for a linked list.
 *
 * @param data provide the data stored at the head
 * of the new list list.
 * @return A new list (NULL if none data is passed).
*/
Node *constructHead(void *data);

/*
 * Destructor function for the linked list.
 * @param phead pointer pointing to the head.
*/
void destructLinkedList(Node **phead);

/*
 * Prepend data to the linked list. 
 * @param phead pointer to the head of the list.
 * @param data pointer to the data.
 * @return true if the prepend was successeful or false 
 * if the allocation of the data failed.
*/
bool prependLinkedList(Node **phead, void *data);

Node *inverseLinkedList(Node* head);

int lengthLinkedList(Node *head);


typedef bool (*ArithComparisonFun)(void *x, void *y);

bool areEqualInt(void *x, void *y);

bool areEqualFloat(void *x, void *y);

bool inserOrderedLinkedList(Node **phead, void *data);

bool insertAfterLinkedList(Node **peahd, void *x, void *data, ArithComparisonFun areEqualFun);

/*
 * Remove all elements of matching a given other element under a 
 * comparison function.
 * @brief Given a comparison function compFun that returns true if 
 * two elements of the same type matches the desired properties (e.g.
 * are equal, one is lees than the other, etc), remove all elements of the
 * linked list that matches the desired pattern
 * @param head A pointer to the head of the linked list
 * @param data A null pointer to the data to be checked
 * @param compFun a matching comparison function
 * @see areEqualInt, areEqualFloat, lessThanInt, lessThanFloat
 */
Node* removeAllLinkedList(Node* head, void *data, ArithComparisonFun compFun);
/*
 * For vizualization porpuses, a printer type 
 * is provided.
 * @see printInt, printFloat, printChar
*/
typedef void (*PrintingFunc)(void *);

/*
 * Printer for the int type
*/
void printInt(void *data);

/*
 * Printer for the float type
*/
void printFloat(void *data);

/*
 * Printer for the char type
*/
void printChar(void *data);

/*
 * Printer for the linked list 
 *
 * @brief Printer function for the linked list. It prints 
 * at most the first 50 elements
 * @param head the linked list to be printed
 * @param printT a PrintingFunc function that casts 
 * the data into a appropriate type and print it. 
 * @see printInt, printFloat, printChar
*/
void printLinkedList(Node *head, PrintingFunc printT);
/*
 *********
 *  STACKS
 *********
*/

/*
 ******************
 * DYNAMICAL ARRAYS
 ******************
*/

typedef struct DynamicArray{
    int size;
    int capacity;
    void *arr;
} DynamicArray;

DynamicArray *createDynamicArray(int init_size);

bool insertAtDynamicArray(DynamicArray **da);

/************
 *  SETS
 ************

*/

#endif
