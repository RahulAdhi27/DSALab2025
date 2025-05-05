#include <stdio.h>
#define SIZE 5

class Queue{
    private:
        int current;
        int length;
        int head;
        int arr[SIZE];
    
    public:
        Queue(){current=0;length=0;head=0;}
        int Enqueue(int);
        int Dequeue();
        void Peek();
};

int main(){
    printf("Program for queue ADT:\n");
    
    int choice,ele,output;
    Queue Queue1;
    
    while(true){
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter the element to queue:");
            scanf("%d",&ele);
            output=Queue1.Enqueue(ele);
            if(output==0){
                printf("Queue Overflow.\n\n");
            }
            else{
                printf("Element added to the Queue.\n\n");
            }
        }

        else if(choice==2){
            output=Queue1.Dequeue();
            if(output==0){
                printf("Queue Underflow.\n\n");
            }
            else{
                printf("The dequeued value:%d\n\n",output);
            }
        }

        else if(choice==3){
            Queue1.Peek();
        }
        
        else if(choice==4){
            printf("********Program Ending********\n");
            break;            
        }
        
        else{
            printf("INVALID INPUT.\n\n");
        }
    }

    return 0;
}


/***************FUNCTION DEFINITIONS***************/

//Function to add an element to the queue
int Queue::Enqueue(int ele){
    if(length+1>SIZE){
        return 0;
    }
    arr[current]=ele;
    current=(current+1)%SIZE;
    length++;
    return 1;
}

//Function to remove the element in queue
int Queue::Dequeue(){
    if(length<=0){
        return 0;
    }
    length--;
    int value=arr[head];
    head=(head+1)%SIZE;    
    return value;
}

void Queue::Peek(){
    if(length<=0){
        printf("Queue Underflow.\n\n");
    }
    else{
        printf("First in line:%d\n\n",arr[head]);
    }
}