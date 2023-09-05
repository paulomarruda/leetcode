/*
 * Provides the "operator overloading" auxiliar functions 
 * for the data structure classes 
*/

#ifndef COMPARISON_FUNCTIONS_H
#define COMPARISON_FUNCTIONS_H 
#include <stdbool.h> 
typedef bool (*ArithmeticComparisonFun)(void *x, void *y);

bool areEqualInt(void *x, void *y);

bool leesThanInt(void *x, void *y);

bool greaterThanInt(void *x, void *y);

bool lessThanOrEqualToInt(void *x, void *y);

bool greaterThanOrEqualToInt(void *x, void *y);

#endif
