#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct Stack {
    size_t size;
    Node *top;
} Stack;

static Node *_createNode(const char data){
    Node *new_node = malloc(sizeof(Node));
    if (!new_node){ return (Node *) NULL; }
    new_node->data = data;
    new_node->next = (Node *) NULL;
    return new_node;
}

static Stack *createStack(){
    Stack *new_stack = malloc(sizeof(Stack));
    if (!new_stack) { return (Stack *) NULL; }
    new_stack->size = (size_t) 0;
    new_stack->top = (Node *) NULL;
    return new_stack;
}

void destructStack(Stack *stack){
    Node *top = stack->top;
    while (top){
        stack->top = top->next;
        free(top);
        top = stack->top;
    }
    free(stack);
}

static bool insert(Stack *stack, char data){
    Node *new_top = _createNode(data);
    if (!new_top) { return false; }
    if (!stack->top){ 
        stack->top = new_top; 
        stack->size++;
    }
    else{
        new_top->next = stack->top;
        stack->top = new_top;
        stack->size++;
    }
    return true;
}

char *pop(Stack *stack){
    if (!stack->top){ return (char *) NULL; }
    Node *top = stack->top;
    stack->top = top->next;
    char *data = &top->data;
    free(top);
    return data;
}

char *peek(Stack *stack){
    if (!stack->top){ return (char *) NULL; }
    char *data = (char *) malloc(sizeof(char));
    if (!data){ return (char *) NULL; }
    memcpy(data, &stack->top->data, sizeof(char *));
    return data;
}
bool isOpening(char b){
    if (
        b == '(' ||
        b == '[' ||
        b == '{'
    ) { return true; }
    else {return false; }
}
bool isRightClosing(char b1, char b2){
    bool is_right_closing = true;
    switch (b1){
        case '(':
            if (b2!=')') { is_right_closing = false; }
            break;
        case '[':
            if (b2!=']') { is_right_closing = false; }
            break;
        case '{':
            if (b2!='}') { is_right_closing = false; }
            break;
    }
    return is_right_closing;
}
bool isValid(char * s){
    bool is_valid = true;
    Stack *stack_brackets = createStack();
    while (*s != '\0'){
        if (isOpening(*s)){ (void) insert(stack_brackets, *s); }
        else{
            char *b = peek(stack_brackets);
            if (!b){
                destructStack(stack_brackets);
                return false;
            }
            if (isRightClosing(*b, *s)){ (void) pop(stack_brackets); }
            else{
                destructStack(stack_brackets);
                return false;               
            }
        }
        s++;
    }
    if (stack_brackets->size != 0){ is_valid = false; }
    destructStack(stack_brackets);
    return is_valid;
}

int main(){

    char *s = "()(){}[]";
    bool is_valid = isValid(s);
    if (is_valid){ printf("is valid!\n"); }
    else { printf("is not valid!\n"); }
}
