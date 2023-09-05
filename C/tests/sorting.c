#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size){
    printf("[");
    for (int i=0; i<size; i++){ printf("%d,", arr[i]); }
    printf("]\n");
}

/*****************
* INSERTION SORT
*****************/ 

void insertionSort(int arr[], int size){
    int i = 1;
    int j;
    int tmp;
    while (i < size){
        j = i;
        while (j > 0 && arr[j-1] > arr[j]){
            tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = tmp;
            j--;
        }
        i++;
    }
}

int main(){
    int test[] = {5,8,9,6,5,8,7};
    int size = sizeof(test)/sizeof(int);
    printf("Original: \n");
    printArray(test,size);
    insertionSort(test, size);
    printf("Sorted: \n");
    printArray(test,size);
    return 0;
}
