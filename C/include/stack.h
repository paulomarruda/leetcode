#ifndef STACK_H
#define STACK_H 
typedef struct Stack Stack;

Stack* constructStack(const int capacity);

void destructStack(Stack** pstack);

bool insertStack(Stack* stack, const unsigned int data);

bool peekStack(Stack* stack, int* container);

bool popStack(Stack* stack, int* container);

#endif
