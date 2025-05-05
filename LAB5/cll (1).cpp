#include <iostream>
#include <cstdlib>

using namespace std;

class list{
    private:
    struct node{
        int data;
        node *next;
    };

    node *head;

    public:
    list(){
        head = nullptr;
    }

    int insertBeg(int);
    int insertEnd(int);
    int insertPos(int, int);
    void displayList();
    int deleteBeg();
    int deleteEnd();
    int deletePos(int);
    void searchList(int);
};

int main(){
    list list1;
    int choice, value, position;
    while(1){
        cout<<"-------------Here is the menu of the operations-------------\n\n";
        cout<<"1. Insert Beginning\n";
        cout<<"2. Insert End\n";
        cout<<"3. Insert Position\n";
        cout<<"4. Delete Beginning\n";
        cout<<"5. Delete End\n";
        cout<<"6. Delete Position\n";
        cout<<"7. Search\n";
        cout<<"8. Display\n";
        cout<<"9. Exit\n\n";

        cout<<"Enter your choice now: ";
        cin>>choice;
        cout<<"\n";

        switch(choice){
            case 1:
            cout<<"Enter value to insert: ";
            cin>>value;
            list1.insertBeg(value);
            break;

            case 2:
            cout<<"Enter value to insert: ";
            cin>>value;
            list1.insertEnd(value);
            break;

            case 3:
            cout<<"Enter position to insert value: ";
            cin>>position;
            cout<<"\n";
            cout<<"Enter value to insert: ";
            cin>>value;
            list1.insertPos(position, value);
            break;

            case 4:
            list1.deleteBeg();
            break;

            case 5:
            list1.deleteEnd();
            break;

            case 6:
            cout<<"Enter position to delete: ";
            cin>>position;
            list1.deletePos(position);
            break;

            case 7:
            cout<<"Enter value to search: ";
            cin>>value;
            list1.searchList(value);
            break;

            case 8:
            list1.displayList();
            break;

            case 9:
            cout<<"Exiting...\n";
            return 0;
            break;

            default:
            cout<<"Invalid choice\n";
            break;
        }
    }
}
//Function to insert value in the beginning
int list::insertBeg(int value){
    node *newnode = (node *)malloc(sizeof(node));
    if(!newnode){
        cout<<"Memory Allocation failed\n";
        return 1;
    }
    newnode->data = value;
    if(!head){
        head = newnode;
        head->next = head;
    } else {
        node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
    cout<<"\nSuccessfully inserted\n\n";
    return 1;
}
//Function to display the list
void list::displayList(){
    if(!head){
        cout<<"Empty List\n";
        return;
    }
    node *temp = head;
    cout<<"---------------Display----------------\n";
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    } while(temp != head);
    cout<<"\n\n";
}
//Function to insert value in the end
int list::insertEnd(int value){
    node *newnode = (node *)malloc(sizeof(node));
    if(!newnode){
        cout<<"Memory Allocation failed\n";
        return 1;
    }
    newnode->data = value;
    if(!head){
        head = newnode;
        head->next = head;
    } else {
        node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    cout<<"\nSuccessfully inserted\n\n";
    return 1;
}
//Function to delete value in the beginning
int list::deleteBeg(){
    if(!head){
        cout<<"Empty list, cannot delete\n\n";
        return 1;
    }
    node *temp = head;
    if(head->next == head){
        head = nullptr;
    } else {
        node *last = head;
        while(last->next != head){
            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
    cout<<"Deleted "<<temp->data<<"\n\n";
    free(temp);
    return 1;
}
//Function to delete value in the end
int list::deleteEnd(){
    if(!head){
        cout<<"Empty list, cannot delete\n\n";
        return 1;
    }
    node *temp = head, *prev = nullptr;
    while(temp->next != head){
        prev = temp;
        temp = temp->next;
    }
    if(temp == head){
        head = nullptr;
    } else {
        prev->next = head;
    }
    cout<<"Deleted "<<temp->data<<"\n\n";
    free(temp);
    return 1;
}
//Function to search a value
void list::searchList(int value){
    node *temp = head;
    int pos = 1;
    do{
        if(temp->data == value){
            cout<<"\nTarget Found at position "<<pos<<"\n\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while(temp != head);
    cout<<"Value not found\n\n";
}
//Function to insert value at a position
int list::insertPos(int position, int value){
    if(position < 1){
        cout<<"Enter a valid position\n\n";
        return 1;
    }
    if(position == 1){
        return insertBeg(value);
    }
    node *newnode = (node *)malloc(sizeof(node));
    node *temp = head;
    newnode->data = value;
    for(int i = 1; i < position-1; i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return 1;
}
//Function to delete value at a given position
int list::deletePos(int position){
    if(position < 1){
        cout<<"Enter a valid position\n\n";
        return 1;
    }
    if(position == 1){
        return deleteBeg();
    }
    node *temp = head;
    for(int i = 1; i < position-1; i++){
        temp = temp->next;
    }
    node *delNode = temp->next;
    temp->next = delNode->next;
    cout<<"\nDeleted "<<delNode->data<<"\n\n";
    free(delNode);
    return 1;
}
