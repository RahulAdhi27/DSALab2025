#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int precedence(char op);
string infixToPostfix(string infix);
int evaluatePostfix(string postfix);

int main(){
    string infix = "";
    string postfix = "";
    int choice;
    
    while(1){
        cout<<"--------------Here are the options for the Menu-------------\n";
        cout<<"1. Get Infix\n";
        cout<<"2. Convert Infix\n";
        cout<<"3. Evaluate Postfix\n";
        cout<<"4. Exit\n\n";
        
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"\n";
        
        switch(choice){
            case 1:
                cout<<"Enter the infix expression: ";
                cin>>infix;
                cout<<"\n";
                break;
                
            case 2:
                postfix = infixToPostfix(infix);
                cout<<"Postfix expression: "<<postfix<<"\n\n";
                break;
                
            case 3:
                if(postfix.empty()){
                    cout<<"No postfix expression available. Convert infix first.\n\n";
                } else {
                    int result = evaluatePostfix(postfix);
                    cout<<"Result of postfix evaluation: "<<result<<"\n\n";
                }
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

int precedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '=') return 0;
    return -1;
}

string infixToPostfix(string infix){
    stack s;
    string postfix = "";
    
    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];
        
        if(isalnum(c)){
            postfix += c;
        } 
        else if(c == '('){
            s.push(c);
        } 
        else if(c == ')'){
            while(s.peek() != '\0' && s.peek() != '('){
                postfix += s.pop();
            }
            if(s.peek() != '\0'){
                s.pop(); // Pop '('
            }
        } 
        else {
            while(s.peek() != '\0' && precedence(c) <= precedence(s.peek())){
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    
    while(s.peek() != '\0'){
        postfix += s.pop();
    }
    
    return postfix;
}

int evaluatePostfix(string postfix){
    stack s;
    
    for(int i = 0; i < postfix.length(); i++){
        char c = postfix[i];
        
        if(isalnum(c)){
            s.push(c - '0'); // Convert char to int
        } 
        else {
            int val1 = s.pop() - '0';
            int val2 = s.pop() - '0';
            
            switch(c){
                case '+':
                    s.push(val2 + val1 + '0'); 
                    break;
                case '-': 
                    s.push(val2 - val1 + '0');
                    break;
                case '*': 
                    s.push(val2 * val1 + '0'); 
                    break;
                case '/': 
                    s.push(val2 / val1 + '0'); 
                    break;
            }
        }
    }
    
    return s.pop() - '0';
}