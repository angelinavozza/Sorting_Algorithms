/**
 * @file sort.c
 * @author Angelina Vozza
 * @section 1
 * @date 2024-02-12
 * @assingnment 3
 */

#include "sort.h"

//sorts a file using the insertion sort algorithm
void insertion_sort(words *arr, int length){
    for(int i = 1; i < length; i++){
        for(int j = i; j >=1; j--){
            if((strcmp(arr[j].word, arr[j-1].word)) < 0){
                swap(arr[j].word, arr[j-1].word);
            } else{
                break;
            }
        }
    }
}

//swaps two elements 
void swap(char* b, char* c){
    char tmp[100];
    strcpy(tmp, b);
    strcpy(b, c);
    strcpy(c, tmp);
}

//prints the strings within the array of structures
void print(words *arr, int length){
    for(int i = 0; i < length; i++){
        printf("%s\n", arr[i].word);
    }
}

//opens a text file and stores each string inside a character array within a structure
void scan_array_and_store(words *arr){
    FILE *fp;

    fp = fopen("1000words.txt", "r");

    int i = 0;

    while(!feof(fp)){
        fscanf(fp, "%[^\n]%*c", arr[i].word);
        i++;
    }
    fclose(fp);
}

//makes all characters in the character arrays lowercase
void lowercase(words *arr, int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < strlen(arr[i].word); j++){
            arr[i].word[j] = tolower(arr[i].word[j]);
        }
    }
}

//takes the new array of structures and writes their character arrays onto a new file
void scan_array_and_write(words *arr, int length){
    FILE *fp2;

    fp2 = fopen("sorted_file.txt", "w+");

    int i = 0;

    while(!feof(fp2) && i < length){
        fprintf(fp2, "%s\n", arr[i].word);
        i++;
        
    }
    fclose(fp2);
}

//sorts a file using the selection sort algorithm
void selection_sort(words *arr, int length)
{
  int min, i, j;
  for(i=0; i<length - 1; i++)
    {
    min=i;
    for(j = i+1; j<length; j++)
	{
	  if((strcmp(arr[j].word, arr[min].word)) < 0)
	    min=j;
	}
      if(min != i){
      swap(arr[i].word, arr[min].word);
    }
    }
}

//sorts a file using the shellsort algorithm
void shellsort(words *arr, int length)
{
    int i, j, k;
    for (i = length / 2; i > 0; i = i / 2){
        for (j = i; j < length; j++){
            for(k = j - i; k >= 0; k = k - i){
                if (strcmp(arr[k+i].word, arr[k].word) > 0)
                    break;
                else{
                    swap(arr[k].word, arr[k+i].word);
                }
            }
        }
    }
}

//sorts a file using the mergesort algorithm
void mSort(words *arr, int lo, int hi){
    if(hi<=lo) return;
    int mid = lo + (hi - lo) / 2;
    mSort(arr, lo, mid);
    mSort(arr, mid+1, hi);
    merge(arr, lo, mid, hi);
}

//merges two arrays -> used in the mergesort algorithm
void merge(words *arr, int lo, int mid, int hi){
    for(int k = lo; k <= hi; k++){
        strcpy(arr[k].aux, arr[k].word);
    }

    int i = lo;
    int j = mid + 1;
    for(int k = lo; k<=hi; k++){
        if(i>mid){
            swap(arr[k].word, arr[j++].aux);
        }else if(j>hi){
            swap(arr[k].word, arr[i++].aux);
        }else if(strcmp(arr[j].aux, arr[i].aux) < 0){
            swap(arr[k].word, arr[j++].aux);
        }else{
            swap(arr[k].word, arr[i++].aux);
        }
    }   

}

//shuffles the character arrays in the array of structures randomly
void shuffle(words *arr, int length){
    srand(time(NULL)); 
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i); 
        swap(arr[i].word, arr[j].word); 
    }
}

//shuffles and sorts a file by implementing quick sort
void sort(words *arr, int length){
    shuffle(arr, length);
    quicksort(arr, 0, length - 1);
}

//sorts a file using the quick sort algorithm
void quicksort(words *arr, int lo, int hi){
    if(lo < hi){
        int j = partition(arr, lo, hi);
        quicksort(arr, lo, j-1);
        quicksort(arr, j+1, hi);
    }    
}

//creates a partition in the array of structures to proceed with the quick sort algorithm
int partition(words *arr, int lo, int hi){
    char *pivot = arr[hi].word;
    int i = lo - 1;
    for(int j = lo; j <= hi - 1; j++){
        if(strcmp(arr[j].word, pivot) < 0){
            i++;
            words temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        }
    }
    words temp = arr[i + 1];
    arr[i + 1] = arr[hi];
    arr[hi] = temp;
    return i+1;

}
