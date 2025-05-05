#include "q4.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    list l1;
    string s1;
    cout << "Enter the string" << " ";
    cin >> s1;
    
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '+') {
            l1.deleteend();
        }
        else {
            l1.insertend(s1[i]);
        }
    }
    
    l1.display();
    return 0;
}