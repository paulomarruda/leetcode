#include <stdbool.h>
#incude "../include/comparison_functions.h"

/*
 * @brief 
 * @param
 * @returns
 *
*/
bool areEqualInt(void *x, void *y){
    int _x = *((int *) x);
    int _y = *((int *) y);
    return _x == _y;
}

/*
 * @brief 
 * @param
 * @returns
 *
*/
bool lessThanInt(void *x, void *y){
    int _x = *((int *) x);
    int _y = *((int *) y);
    return _x < _y;
}

bool greaterThanInt(void *x, void *y){
    int _x = *((int *) x);
    int _y = *((int *) y);
    return _x > _y;
}
/*
 * @brief 
 * @param
 * @returns
 *
*/
bool lessThanOrEqualToInt(void *x, void *y){ 
    int _x = *((int *) x);
    int _y = *((int *) y);
    return _x <= _y;
}

/*
 * @brief 
 * @param
 * @returns
 *
*/
bool greaterThanOrEqualToInt(void *x, void *y){
    int _x = *((int *) x);
    int _y = *((int *) y);
    return _x >= _y;
}
