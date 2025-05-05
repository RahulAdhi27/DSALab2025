#include <iostream>
#include <cstdlib>

using namespace std;

class queue{
    private:
    struct node{
        int data;
        node *next;
    };
    node *front;
    node *rear;

    public:

    int enqueue(int);
    int dequeue();
    int peek();

    queue(){
        rear = nullptr;
        front = nullptr;
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
    node *newnode = (node *)malloc(sizeof(node));
    if(!newnode){
        cout<<"Memory Allocation Failed\n";
        return 1;
    }
    newnode->data = value;
    newnode->next = nullptr;

    if(!rear){
        front = rear = newnode;
        return 1;
    }

    rear->next = newnode;
    rear = newnode;
    return 1;
}
//Function to remove element from the front
int queue::dequeue(){
    node *delNode = (node *)malloc(sizeof(node));
    if(!delNode){
        cout<<"Memory Allocation Failed\n";
        return 1;
    }
    delNode = front;
    front = front->next;
    cout<<"Removed: "<<delNode->data<<"\n";
    free(delNode);
    return 1;
}
//Function to peek element of the queue
int queue::peek(){
    cout<<"Displaying rear element: "<<rear->data<<"\n";
    return 1;
}