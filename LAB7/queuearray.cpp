#include <iostream>
#include <cstdlib>

using namespace std;

class queue{
    private:
    int *arr;
    int front;
    int rear;
    int capacity;

    public:

    int enqueue(int);
    int dequeue();
    int peek();

    queue(){
        capacity = 100; // Setting a default capacity
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~queue(){
        delete[] arr; // Destructor to free memory
    }
};

int main(){
    queue q;

    while(1){
        cout<<"Here are the options for the menu: \n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Peek\n";
        cout<<"4. Exit\n";

        int ch, value;
        cout<<"Choose your option: ";
        cin>>ch;

        switch(ch){
            case 1:
            cout<<"Enter value to enqueue: ";
            cin>>value;
            q.enqueue(value);
            break;

            case 2:
            q.dequeue();
            break;

            case 3:
            q.peek();
            break;

            case 4:
            cout<<"Exiting...\n";
            return 0;
            break;

            default:
            cout<<"Give valid input\n";
            break;
        }
    }
}
//Function to add element to queue from the rear
int queue::enqueue(int value){
    if(rear == capacity - 1){
        cout<<"Queue Overflow\n";
        return 1;
    }
    
    if(front == -1){
        front = 0;
    }
    
    rear++;
    arr[rear] = value;
    cout<<"Enqueued: "<<value<<"\n";
    return 1;
}
//Function to remove element from the front
int queue::dequeue(){
    if(front == -1 || front > rear){
        cout<<"Queue Underflow\n";
        return 1;
    }
    
    cout<<"Removed: "<<arr[front]<<"\n";
    front++;
    
    // Reset the queue when it becomes empty
    if(front > rear){
        front = -1;
        rear = -1;
    }
    
    return 1;
}
//Function to peek element of the queue
int queue::peek(){
    if(front == -1 || front > rear){
        cout<<"Queue is empty\n";
        return 1;
    }
    
    cout<<"Displaying rear element: "<<arr[rear]<<"\n";
    return 1;
}