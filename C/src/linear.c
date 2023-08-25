#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../include/linear.h"

#define MAX_PRINT 50
#define EPS 1.0E-34;

Node *constructHead(void *data){
    if (!data){ return NULL; }
    Node* new_head = malloc(sizeof(Node));
    // if allocation failed:
    if (new_head == NULL){ return NULL;}
    new_head->data = data;
    new_head->next = NULL;
    return new_head;
}

void destructLinkedList(Node **phead){
    Node *current = *phead;
    Node *tmp;
    while (current){
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *phead = NULL;
}

bool prependLinkedList(Node **phead, void *data){
    Node *new_head = malloc(sizeof(Node));
    if (!new_head){ return false; }
    new_head->data = data;
    new_head->next = *phead;
    *phead = new_head;
    return true;
}

Node *inverseLinkedList(Node *head){
    if (head == NULL) {return NULL;}
    Node* begin = head;
    Node *middle = NULL;
    Node *end = NULL;
    while (begin->next){
        middle = begin->next;
        end = middle->next;
        begin->next = end;
        middle->next = head;
        head = middle;
    }
    return head;
}

int lengthLinkedList(Node *head){
    int l = 0;
    while(!head){ head = head->next; }
    return l;
}

void printInt(void *data){
    int *value = (int *) data;
    printf("%d", *value);
}

void printLinkedList(Node *head, PrintingFunc printT){
    printf("<");
    int i = 0;
    while (head && i < MAX_PRINT){
        printT(head->data);
        printf(",");
        head = head->next;
        i++;
    }
    if (i == MAX_PRINT) { printf("..."); };
    printf(">\n");
}


bool areEqualInt(void *x, void *y){
    int _x = *(int *) x;
    int _y = *(int *) y;
    return _x == _y;
}

bool areEqualFloat(void *x, void *y){
    float _x = *(float *) x;
    float _y = *(float *) y;
    return fabs(_x - _y) < EPS;
}

bool lessThanInt(void *x, void *y){
    return (*(int *) x) < (*(int *) y); 
}
/*
Node* removeAlllinkedList(Node* head, void *data, ArithComparisonFun compFun){
    if (!head){ return head; }
    Node *current = head;
    Node *next = current->next;
    Node* previous = NULL;
    void *elem;
    
}
*/


/*
 ******************
 * DYNAMICAL ARRAYS
 ******************
*/

