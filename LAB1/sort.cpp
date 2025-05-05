//Sorting
#include <stdio.h>
#include "sort.h"

int main(){
    int size, choice;

    printf("Enter number of elements in array:\n");
    scanf("%d", &size);
    int arr[size];
    printf("\n");
    printf("Now print the elements of the array:\n");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
        printf("\n");
    }

    while(1){
        printf("\nPlease enter your choice:\n");
        printf("1. Bubble sort\n");
        printf("2. Selection sort\n");
        printf("3. Insertion sort\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
            bubbleSort(arr, size);
            display(arr, size);
            break;

            case 2:
            selectionSort(arr, size);
            display(arr, size);
            break;

            case 3:
            insertionSort(arr, size);
            display(arr, size);
            break;

            case 4:
            printf("Exiting...\n");
            return -1;
            break;

            default:
            printf("Invalid\n");
        }
    }
}