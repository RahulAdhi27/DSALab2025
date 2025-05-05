//Program to check if a number is a palindrome, armstrong number or a perfect number using a menu-driven program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *palindrome(int *num);
void isPalindrome(int *num);
int *countDigits(int *num);
int *armstrong(int *num);
void isArmstrong(int *num);
int *perfect(int *num);
void isPerfect(int *num);

int main(){
    int *num = (int *)malloc(sizeof(int));
    printf("Enter the number: ");
    scanf("%d", num);

    int *choice = (int *)malloc(sizeof(int));

    while(1){
        printf("1. Palindrome\n");
        printf("2. Armstrong\n");
        printf("3. Perfect\n");
        printf("4. Exit\n");

        printf("Now enter your choice: ");
        scanf("%d", choice);
        switch(*choice){
            case 1:
            isPalindrome(num);
            break;

            case 2:
            isArmstrong(num);
            break;

            case 3:
            isPerfect(num);
            break;

            case 4:
            printf("Ending...\n");
            return -1;
        }
    }
}

//function to get reverse
int *palindrome(int *num){
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;

    int *newnum = (int *)malloc(sizeof(int));

    while(*temp > 0){
        *newnum = (*newnum)*10 + *temp%10;
        *temp = *temp/10;
    }

    return newnum;
    free(temp);
    free(newnum);
}
//function to check if the number is a palindrome
void isPalindrome(int *num){
    if(*num == *palindrome(num)){
        printf("%d is a palindrome\n", *num);
    }
    else{
        printf("%d is not a palindrome\n", *num);
    }
}
//function counting number of digits in the number
int *countDigits(int *num){
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;

    int *count = (int *)malloc(sizeof(int));
    *count = 0;

    while(*temp > 0){
        (*count)++;
        *temp = *temp/10;
    }

    return count;
    free(count);
    free(temp);
}
//function obtaining the sum of cube of all the digits in the number
int *armstrong(int *num){
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;

    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;

    int *digit = (int *)malloc(sizeof(int));
    *digit = *countDigits(num);

    while(*temp > 0){
        *sum = *sum + pow((*temp%10), *digit);
        *temp = *temp / 10;
    }

    return sum;
    free(temp);
    free(sum);
    free(digit);
}
//function to check if the number is a armstrong number
void isArmstrong(int *num){
    if(*num == *armstrong(num)){
        printf("%d is an armstrong number\n", *num);
    }
    else{
        printf("%d is not an armstrong number\n", *num);
    }
}
//function to find the sum of factors of a number except the number itself
int *perfect(int *num){
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;

    int *count = (int *)malloc(sizeof(int));
    *count = 1;

    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;

    while(*count <= (*temp)/2){
        if((*temp)%(*count) == 0){
            *sum = *sum + *count;  
        }
        *count = *count + 1;
    }
    return sum;
    free(temp);
    free(sum);
    free(count);
}
//function to check if the number is a perfect number
void isPerfect(int *num){
    if(*num == *perfect(num)){
        printf("%d is a perfect number\n", *num);
    }
    else{
        printf("%d is not a perfect number\n", *num);
    }
}