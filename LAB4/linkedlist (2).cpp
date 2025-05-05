//Menu-driven program for Linked List
#include <iostream>
#include <cstdlib>
using namespace std;

class list {
private:
    struct node {
        int data;
        node *next;
    };

    node *head;

    void displayReverseHelper(node *current) {
        if (current == nullptr) return;
        displayReverseHelper(current->next);
        cout << current->data << " ";
    }

public:
    list() {
        head = nullptr;
    }

    int insertBeg(int);
    void display();
    int insertEnd(int);
    int insertPos(int, int);
    void deleteBeg();
    void deleteEnd();
    void deletePos(int);
    int search(int);
    void displayReverse();
    void reverse();
};

int main() {
    list list1;
    int value, position, choice;

    cout << "\n=============================\n";
    cout << " Linked List Implementation\n";
    cout << "=============================\n";
    cout << "1. Insert Beginning\n";
    cout << "2. Insert End\n";
    cout << "3. Insert Position\n";
    cout << "4. Delete Beginning\n";
    cout << "5. Delete End\n";
    cout << "6. Search\n";
    cout << "7. Display Reverse\n";
    cout << "8. Display\n";
    cout << "9. Reverse List\n";
    cout <<"10. Delete Position\n";
    cout << "11. Exit\n";
    cout << "=============================\n";

    while (1) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter value to insert at beginning: ";
                cin >> value;
                list1.insertBeg(value);
                cout << "\nInserted " << value << " at the beginning.\n";
                break;

            case 2:
                cout << "\nEnter value to insert at end: ";
                cin >> value;
                list1.insertEnd(value);
                cout << "\nInserted " << value << " at the end.\n";
                break;

            case 3:
                cout << "\nEnter position to insert: ";
                cin >> position;
                cout << "Enter value to insert: ";
                cin >> value;
                list1.insertPos(position, value);
                cout << "\nInserted " << value << " at position " << position << ".\n";
                break;

            case 4:
                list1.deleteBeg();
                break;

            case 5:
                list1.deleteEnd();
                break;

            case 6:
                cout << "\nEnter value to search: ";
                cin >> value;
                list1.search(value);
                break;

            case 7:
                cout << "\n-------- Display Reverse --------\n";
                list1.displayReverse();
                cout << "\n---------------------------------\n";
                break;

            case 8:
                cout << "\n---------- Display ----------\n";
                list1.display();
                cout << "------------------------------\n";
                break;

            case 10:
                cout << "\nEnter position to delete: ";
                cin >> position;
                list1.deletePos(position);
                break;

            case 9:
                list1.reverse();
                cout << "\nList reversed successfully.\n";
                break;

            case 11:
                cout << "\nExiting...\n";
                return 0;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}
//function to insert a value in the beginning
int list::insertBeg(int num) {
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode) {
        cout << "\nMemory allocation failed.\n";
    } else {
        newnode->data = num;
        newnode->next = head;
        head = newnode;
    }
    return 1;
}
//function to display the list
void list::display() {
    if (head == NULL) {
        cout << "Empty List\n";
    } else {
        node *temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
}
//function to insert a value in the end
int list::insertEnd(int value) {
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode) {
        cout << "\nMemory allocation failed.\n";
    } else {
        newnode->data = value;
        newnode->next = nullptr;

        if (!head) {
            head = newnode;
        } else {
            node *temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    return 1;
}
//function to insert a value at a position
int list::insertPos(int position, int value) {
    if (position < 1) {
        cout << "\nEnter a valid position\n";
    } else {
        node *newnode = (node *)malloc(sizeof(node));
        if (!newnode) {
            cout << "\nMemory allocation failed.\n";
        } else {
            newnode->data = value;

            if (position == 1) {
                newnode->next = head;
                head = newnode;
            } else {
                node *temp = head;
                for (int i = 1; i < position - 1 && temp != nullptr; i++) {
                    temp = temp->next;
                }
                if (temp == nullptr) {
                    cout << "\nPosition out of range\n";
                } else {
                    newnode->next = temp->next;
                    temp->next = newnode;
                }
            }
        }
    }
    return 1;
}
//function to delete a value in the beginning
void list::deleteBeg() {
    if (!head) {
        cout << "\nList is empty.\n";
    } else {
        node *temp = head;
        head = head->next;
        cout << "\nDeleting " << temp->data << " from the beginning.\n";
        free(temp);
    }
}
//function to delete a value in the end 
void list::deleteEnd() {
    if (!head) {
        cout << "\nList is empty.\n";
    } else {
        if (!head->next) {
            cout << "\nDeleting " << head->data << " from the end.\n";
            free(head);
            head = nullptr;
        } else {
            node *temp = head;
            while (temp->next->next) {
                temp = temp->next;
            }
            cout << "\nDeleting " << temp->next->data << " from the end.\n";
            free(temp->next);
            temp->next = nullptr;
        }
    }
}
//function to delete a value at a position
void list::deletePos(int position) {
    if (position < 1) {
        cout << "\nEnter a valid position\n";
    } else if (!head) {
        cout << "\nList is empty.\n";
    } else {
        node *temp = head;

        if (position == 1) {
            head = head->next;
            cout << "\nDeleting " << temp->data << " from position " << position << ".\n";
            free(temp);
        } else {
            node *prev = nullptr;
            for (int i = 1; i < position && temp != nullptr; i++) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "\nPosition out of range\n";
            } else {
                prev->next = temp->next;
                cout << "\nDeleting " << temp->data << " from position " << position << ".\n";
                free(temp);
            }
        }
    }
}

//function to delete a value at a position
int list::search(int value) {
    int pos=1;
    node *temp = head;
    while (temp) {
        if (temp->data == value){
            return pos;
        }
        temp = temp->next;
        pos+=1;
    }
    return -1;
}
//function to display reverse
void list::displayReverse() {
    displayReverseHelper(head);
}
//function to reverse a list
void list::reverse() {
    node *prev = nullptr, *current = head, *next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

