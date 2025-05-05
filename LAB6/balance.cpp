#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int isBalancedStack(const string& str);

int main(){
    int choice;
    string input;

    while(1){
        cout<<"--------------Here are the options for the Menu-------------\n";
        cout<<"1. Check Balance\n";
        cout<<"2. Exit\n\n";
        
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"\n";
        
        switch(choice){
            case 1:
                cout<<"Enter a string of parentheses: ";
                cin>>input;
                cout<<"\n";
                
                // Validate input
                int isValid;
                isValid = 1;
                for(int i = 0; i < input.length(); i++){
                    char ch = input[i];
                    if(ch != '(' && ch != ')'){
                        isValid = 0;
                        break;
                    }
                }

                if(!isValid){
                    cout<<"Invalid input! Only '(' and ')' are allowed.\n\n";
                    break;
                }

                // Check balance
                if(isBalancedStack(input)){
                    cout<<"The parentheses are balanced.\n\n";
                } else {
                    cout<<"The parentheses are not balanced.\n\n";
                }
                break;
                
            case 2:
                cout<<"Exiting...\n";
                return -1;
                
            default:
                cout<<"Invalid choice\n";
                break;
        }
    }
}

// Function to check if parentheses are balanced using the custom stack
int isBalancedStack(const string& str){
    stack s;
    
    // Traverse the input string
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        
        if(ch == '('){
            // Push '(' onto the stack
            s.push(ch);
        } else if(ch == ')'){
            // If stack is empty or top element is not '(', parentheses are not balanced
            if(s.peek() == '\0' || s.peek() != '('){
                return 0;
            }
            // Pop the top element from the stack
            s.pop();
        }
    }
    
    // If the stack is empty, parentheses are balanced
    return (s.peek() == '\0');
}