/**
 * @file sort.h
 * @author Angelina Vozza
 * @section 1
 * @date 2024-02-12
 * @assingnment 3
 */

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct{
    char word[100];
    char aux[100];
}words, *wordsPtr;

void swap(char* b, char* c);
void print(words *arr, int length);
void insertion_sort(words *arr, int length);
void scan_array_and_store(words *arr);
void lowercase(words *arr, int length);
void scan_array_and_write(words *arr, int length);
void selection_sort(words *arr, int length);
void shellsort(words *arr, int length);
void mSort(words *arr, int lo, int hi);
void merge(words *arr, int lo, int mid, int hi);
void shuffle(words *arr, int length);
void sort(words *arr, int length);
void quicksort(words *arr, int lo, int hi);
int partition(words *arr, int lo, int hi);

