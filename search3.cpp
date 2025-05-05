// This is a code for searching

#include <stdio.h>
#include "sort.h"

//Linear search
int linearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

//Binary search
int binarySearch(int arr[], int size, int target){
    int left, right;
    left = 0;
    right = size-1;

    while(left<=right){
        int mid = (right+left)/2;
        if(arr[mid]==target){
            return mid;
            break;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}

int main(){
    int size;
    int choice;
    int target;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    printf("\n");
    printf("Enter elements of array:\n");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
        
    }
    printf("\n");

    printf("Enter target to be searched: ");
    scanf("%d", &target);

    while(1){
        printf("\nEnter choice:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("\n");
        scanf("%d", &choice);
        int resultL;
        int resultB;
        switch(choice){
            case 1:
            resultL = linearSearch(arr, size, target);
            if(resultL != -1){
                printf("The index of the target element is:\n");
                printf("%d", resultL);
            }
            else{
                printf("Target does not exist\n");
            }
            break;

            case 2:
            selectionSort(arr, size);
            resultB = binarySearch(arr, size, target);
            if(resultB != -1){
                printf("The index of the target element is:\n");
                printf("%d", resultB);
            }
            else{
                printf("Target does not exist\n");
            }
            break;

            case 3:
            printf("Exiting...\n");
            return -1;
            break;

            default:
            printf("Invalid\n");
        }
    }

}