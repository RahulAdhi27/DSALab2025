#ifndef SORT_H
#define SORT_H
#include <stdio.h>


// display
void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//bubble sort
void bubbleSort(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
        display(arr, size);
    }
}
//selection sort
void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int minIdx = i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;

        display(arr, size);

    }
}
//insertion sort
void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key;
        display(arr, size);

    }
}

#endif