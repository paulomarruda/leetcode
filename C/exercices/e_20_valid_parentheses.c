#include <stdio.h>
#include "../include/linear.h" 

bool isOpeningBracket(char b){
    if (
        b == '(' ||
        b == '{' ||
        b == '[' 
    ) { return true; }
    else { return false; }
}

bool isClosing(char b1, char b2){
    if ( !isOpeningBracket(b1) ){ return false; }
    bool is_parent = true;
    switch (b1){
        case '(':
            if ( b2 != ')' ){ is_parent = false; }
            break;
        case '[': 
            if ( b2 != ']' ){ is_parent = false; }
            break;
        case '{':
            if ( b2 != '}') { is_parent = false; }
            break;
    }
    return is_parent;
}

bool isValid(char *string){
    char *p = string;
    bool is_valid = true;
    Stack *bracket_stack = constructStack();
    void *data;
    while (*p != '\0'){
        if ( isOpeningBracket(*p) ){
            insertStack(bracket_stack, p);
        }else{
            data = peekStack(bracket_stack);
            if (!data){
                destructStack(bracket_stack);
                return false; 
            }
            char b = *(char *) data;
            if ( isClosing(b, *p) ){ (void) popStack(bracket_stack); }
            else{ 
                destructStack(bracket_stack);
                return false; 
            }
        }
        p++;
    }
    if (bracket_stack->size != 0){ is_valid = false; }
    destructStack(bracket_stack);
    return is_valid;
}

int main(){
    char *string = "()()()()()()()()()()()()()()()()()()()()()()()()()";
    bool is_valid = isValid(string);
    if (is_valid){ printf("Is valid!"); }
    else { printf("Is not valid!"); }
    return 0;
}
