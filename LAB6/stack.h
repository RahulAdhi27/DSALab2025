#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class stack{
    private:
    struct Node {
        char data;
        struct Node* next;
    };
    Node* top;

    public:
    int push(char);
    int pop();
    int peek();

    stack(){
        top = NULL;
    }
};

//Function to Push element into the stack
int stack::push(char value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        cout<<"Memory allocation failed\n";
        return 1;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout<<value<<" has been pushed into the stack\n\n";
    return 1;
}

//Function to pop element from the stack
int stack::pop(){
    if(top == NULL){
        cout<<"Stack Underflow\n";
        return 1;
    }
    else{
        Node* temp = top;
        cout<<"Deleting "<<temp->data<<" from the stack\n\n";
        top = top->next;
        free(temp);
        return 1;
    }
}

//Function to peek last element from the stack
int stack::peek(){
    if(top == NULL){
        cout<<"Stack is empty\n";
        return 1;
    }
    else{
        cout<<"Top element: "<<top->data<<"\n\n";
        return 1;
    }
}

#endif