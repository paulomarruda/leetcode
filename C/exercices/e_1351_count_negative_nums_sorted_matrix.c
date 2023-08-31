#include <stdio.h>


int indexChangeSign(int arr[], int arr_size, int range_max){
    if (arr_size <= 1 || arr_size < range_max){ return 0; }
    int L = 0;
    if (arr[L] < 0){ return 0; }
    int R = range_max-1;
    if (arr[R] >= 0) { return 0; }
    int middle;
    while( L < R){
        middle = (L + R)/2;
        if (arr[middle] >= 0){ L = middle + 1; }
        else { R = middle - 1; }
    }
    printf("middle: %d\n", arr[middle]);
    if (arr[L] >= 0){
        return L+1;
    } else { return L; }
}
int count_negatives();

int main(){
    int arr[] = {1,1,1,1, -1};
    int size_arr = sizeof(arr)/sizeof(int);
    int l = indexChangeSign(arr, size_arr, size_arr);
    printf("i=%d\n", l);
    return 0;
}
