#ifndef LISTADT_H
#define LISTADT_H

#include <iostream>
using namespace std;

class List {
private:
    struct Node {
        int data;
        Node *next;
    };

    Node *head;
    Node* gethead(); // Private helper function

public:
    List();
    void insertAscending(int value);
    void display();
    List merge(List &list2); // Merge current list with list2
};

#endif
