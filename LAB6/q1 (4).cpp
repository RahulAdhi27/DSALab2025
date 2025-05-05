//Stack ADT using Array Implementation
#include <iostream>
using namespace std;

#define SIZE 5

class stack{
    private:
    char arr[SIZE];
    int top;

    public:
    int push(char);
    int pop();
    int peek();

    stack(){
        top = -1;
    }
};

int main(){
    stack s;
    int choice;
    char value;

    while(1){
        cout<<"--------------Here are the options for the Menu-------------\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Exit\n\n";

        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"\n";
        switch(choice){
            case 1:
            cout<<"Enter value to push: ";
            cin>>value;
            s.push(value);
            break;

            case 2:
            s.pop();
            break;

            case 3:
            s.peek();
            break;

            case 4:
            cout<<"Exiting...\n";
            return -1;
            break;

            default:
            cout<<"Invalid choice\n";
            break;
        }
    }
}
//Function to Push element into the stack
int stack::push(char value){
    if(top >= SIZE){
        cout<<"Stack overflow\n";
        return 1;
    }
    else{
        top = top+1;
        arr[top] = value;
        cout<<value<<" has been pushed into the stack\n\n";
        return 1;
    }
}
//Function to pop element from the stack
int stack::pop(){
    if(top == -1){
        cout<<"Stack Underflow\n";
        return 1;
    }
    else{
        cout<<"Deleting "<<arr[top]<<" from the stack\n\n";
        top--;
        return 1;
    }
}
//Function to peek last element from the stack
int stack::peek(){
    if(top==-1){
        cout<<"Stack is empty\n";
        return 1;
    }
    else{
        cout<<"Top element: "<<arr[top]<<"\n\n";
        return 1;
    }
}