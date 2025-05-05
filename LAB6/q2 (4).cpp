//Stack ADT using Linked List implementation
#include <iostream>
#include <cstdlib>

using namespace std;

class stack{
    private:
    struct node{
        char data;
        node *next;
    };
    node *top;

    public:
    int push(char);
    int pop();
    int peek();

    stack(){
        top = nullptr;
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
//Function to push element into the stack
int stack::push(char value){
    node *newnode = (node *)malloc(sizeof(node));
    if(!newnode){
        cout<<"Memory Allocation Failed\n";
        return 1;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    cout<<"Pushed "<<top->data<<" into the stack\n\n";
    return 1;
}
//Function to pop element from the stack
int stack::pop(){
    if(!top){
        cout<<"Stack underflow\n\n";
        return 1;
    }
    else{
        node *temp = top;
        cout<<temp->data<<" has been deleted from the stack\n\n";
        top=top->next;
        free(temp);
        return 1;
    }
}
//Function to display the top element of the stack
int stack::peek(){
    if(!top){
        cout<<"Stack underflow\n\n";
        return 1;
    }
    else{
        cout<<"Top element: "<<top->data<<"\n\n";
    }
    return 1;
}