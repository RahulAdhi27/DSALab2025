#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class list {
private:
    struct node {
        char data;
        struct node* nextptr;
    };
    struct node* head;
    int count;

public:
    // Constructor
    list() {
        head = nullptr;
        count = 0;
    }

    // Function to insert a new node in the beginning of the list
    int insertbeg(char val) {
        struct node* newnode = new struct node();
        newnode->data = val;
        newnode->nextptr = head;
        head = newnode;
        count++;
        return 0;
    }

    // Function to insert a new node in the end of the list
    int insertend(char val) {
        if (head == nullptr) {
            return insertbeg(val);
        }
        struct node* newnode = new struct node();
        newnode->data = val;
        newnode->nextptr = nullptr;
        struct node* temp = head;
        while (temp->nextptr != nullptr) {
            temp = temp->nextptr;
        }
        temp->nextptr = newnode;
        count++;
        return 0;
    }

    // Function to delete the end of the list
    int deleteend() {
        struct node* temp = head;
        struct node* t1 = nullptr;
        if (temp == nullptr) {
            cout << "Empty list" << endl;
            return -1;
        }
        
        // Special case: only one node in the list
        if (temp->nextptr == nullptr) {
            t1 = temp;
            head = nullptr;
            count--;
            char value = t1->data;
            delete t1;
            return value;
        }
        
        while (temp->nextptr->nextptr != nullptr) {
            temp = temp->nextptr;
        }
        t1 = temp->nextptr;
        char value = t1->data;
        temp->nextptr = nullptr;
        delete t1;
        count--;
        return value;
    }

    // Function to display the list
    int display() {
        struct node* temp = head;
        if (temp == nullptr) {
            cout << "The list is empty";
            return -1;
        }
        else {
            while (temp != nullptr) {
                cout << temp->data << "";
                temp = temp->nextptr;
            }
            cout << endl;
        }
        return 0;
    }
};

#endif // LIST_H