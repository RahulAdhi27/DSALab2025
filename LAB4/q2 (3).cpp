#include "q2.h"
#include <cstdlib>

int main() {
    List list1, list2, list3;
    int choice, value;

    cout << "\n=============================\n";
    cout << "  Linked List ADT Operations\n";
    cout << "=============================\n";
    cout << "1. Insert Ascending in List1\n";
    cout << "2. Insert Ascending in List2\n";
    cout << "3. Merge List1 and List2 into List3\n";
    cout << "4. Display Lists\n";
    cout << "5. Exit\n";
    cout << "=============================\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert in List1: ";
                cin >> value;
                list1.insertAscending(value);
                cout << "Inserted " << value << " in List1.\n";
                break;

            case 2:
                cout << "Enter value to insert in List2: ";
                cin >> value;
                list2.insertAscending(value);
                cout << "Inserted " << value << " in List2.\n";
                break;

            case 3:
                list3 = list1.merge(list2);
                cout << "Lists merged into List3 in ascending order.\n";
                break;

            case 4:
                cout << "\n-------- List 1 --------\n";
                list1.display();
                cout << "------------------------\n";

                cout << "\n-------- List 2 --------\n";
                list2.display();
                cout << "------------------------\n";

                cout << "\n-------- List 3 --------\n";
                list3.display();
                cout << "------------------------\n";
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

List::List() {
    head = nullptr;
}

List::Node* List::gethead() {
    return head;
}

void List::insertAscending(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = nullptr;

    if (!head || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void List::display() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node *current = head;
    cout << "List: ";
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

List List::merge(List &list2) {
    List mergedList;
    Node *ptr1 = gethead();
    Node *ptr2 = list2.gethead();

    while (ptr1 && ptr2) {
        if (ptr1->data < ptr2->data) {
            mergedList.insertAscending(ptr1->data);
            ptr1 = ptr1->next;
        } else {
            mergedList.insertAscending(ptr2->data);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1) {
        mergedList.insertAscending(ptr1->data);
        ptr1 = ptr1->next;
    }

    while (ptr2) {
        mergedList.insertAscending(ptr2->data);
        ptr2 = ptr2->next;
    }

    return mergedList;
}
