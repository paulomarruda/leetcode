#ifndef SORTING_H
#define SORTING_H


/*****************
 *  QUICK SORT
 ****************
*/
#include <stdlib.h>
#include "comparison_functions.h"

void quickSort(void *arr, size_t size, ArithmeticComparisonFun lessThanfun);


#endif 
