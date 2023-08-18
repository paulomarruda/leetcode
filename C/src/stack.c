#include <stdbool.h>
#include <stdlib.h>
#include "../include/linked_list.h"

#define MAX_CAPACITY 1000

typedef struct Stack{
    int capacity;
    int size;
    Node* top;
} Stack;

Stack* constructStack(const unsigned int capacity){
    Stack* new_stack = malloc(sizeof(Stack));
    if (new_stack == NULL || capacity == 0){ return NULL; }
    new_stack->capacity = capacity;
    new_stack->size = 0;
    new_stack->top = NULL;
    return new_stack;
}

void destructStack(Stack** pstack){
    destructLinkedList(&((*pstack)->top));
    *pstack = NULL;
}

bool insertStack(Stack* stack, const int data){
    if (stack->capacity <= stack->size){
        return false;
    }
    if (prependLinkedList(&stack->top, data)){
        return true;
    } else{
        return false;
    }
}

bool peekStack(Stack* stack, int* container){
    if (stack == NULL){ return false; } 
    else if (stack->size == 0){ return false; }
    *container = stack->top->data;
    return true;
}

bool popStack(Stack* stack, int* container){
    return false;
}
