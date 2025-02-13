/**
 * @file main.c
 * @author Angelina Vozza
 * @date 2024-02-12
 * @note this program only sorts the 1000words.txt file. The file being sorted can be changed in the scan_array_and_store function
 *       in sort.c.
 */

#include "sort.h"

    //length is defined based on the amount of lines present in the file we are reading from and sorting. In this case 1000 for 1000words.txt.
    int length = 1000;
    clock_t time_req;

int main(){

    wordsPtr arr= (wordsPtr)malloc(length * sizeof(words));

    //Sorts using selection sort
    scan_array_and_store(arr);
    lowercase(arr, length);
    time_req = clock();
    selection_sort(arr, length);
    time_req = clock() - time_req;
    printf("Processor time taken to sort array using selection sort: %f\n", ((float)time_req / CLOCKS_PER_SEC));

    //Sorts using insertion sort
    scan_array_and_store(arr);
    lowercase(arr, length);
    time_req = clock();
    insertion_sort(arr, length);
    time_req = clock() - time_req;
    printf("Processor time taken to sort array using insertion sort: %f\n", ((float)time_req / CLOCKS_PER_SEC));

    //Sorts using shellsort
    scan_array_and_store(arr);
    lowercase(arr, length);
    time_req = clock();
    shellsort(arr, length);
    time_req = clock() - time_req;
    printf("Processor time taken to sort array using shellsort: %f\n", ((float)time_req / CLOCKS_PER_SEC));
    
    //Sorts using mergesort
    scan_array_and_store(arr);
    lowercase(arr, length);
    time_req = clock();
    mSort(arr, 0, length-1);
    time_req = clock() - time_req;
    printf("Processor time taken to sort array using mergesort: %f\n", ((float)time_req / CLOCKS_PER_SEC));
    
    //Sorts using quicksort
    scan_array_and_store(arr);
    lowercase(arr, length);
    time_req = clock();
    sort(arr, length);
    time_req = clock() - time_req;
    printf("Processor time taken to sort array using quicksort: %f\n", ((float)time_req / CLOCKS_PER_SEC));
    
    free(arr);
    return 0; 
}
