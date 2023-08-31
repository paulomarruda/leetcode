#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../include/linear.h"


#define MAX_PRINT 50
#define EPS 1.0E-34;

static Node *constructLinkedListNode(void *data){
    if (!data){ return NULL; }
    Node* new_head = malloc(sizeof(Node));
    // if allocation failed:
    if (!new_head){ return NULL; }
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
    Node *new_head = constructLinkedListNode(data);
    if (!new_head){ return false; }
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
    while(!head){ 
        head = head->next; 
        l++;
    }
    return l;
}

void printInt(void *data){
    int _data = *((int *) data);
    printf("%d", _data);
}

void printFloat(void *data){
    float _data = *((float *) data);
    printf("%f", _data);
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


/*
 ******************
 *      Stacks 
 ******************
*/

Stack *constructstack(const size_t capacity, void *data){
    Stack *new_stack = malloc(sizeof(Stack));
    if (!new_stack){ return NULL; }
    new_stack->capacity = capacity;
    new_stack->size = 0;
    if (data){
        new_stack->top = constructLinkedListNode(data);
    } else { new_stack->top = (Node *) NULL; }
    return new_stack;
}

void destructStack(Stack *stack){
    destructLinkedList( &( stack->top ) );
    free(stack);
}

size_t lengthStack(Stack *stack){
    return stack->size;
}

bool insertStack(Stack *stack, void *data){
    if (stack->capacity == stack->size) { return false; }
    bool op = prependLinkedList(&stack->top, data);
    return op;
}

bool popStack(Stack *stack, void *data){
    if (stack->top == 0){ return false; }
    Node *pop = stack->top;
    stack->top = (stack->top)->next;
    data = pop->data;
    free(pop);
    return true;
}


