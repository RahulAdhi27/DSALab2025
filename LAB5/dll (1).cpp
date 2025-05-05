//List ADT - Implmentation using Doubly Linked List
#include <iostream>
#include <cstdlib>

using namespace std;

class list{
    private:
    struct node{
        int data;
        node *next;
        node *prev;
    };

    node *head, *tail;

    public:
    list(){
        head = nullptr;
        tail = nullptr;
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
    else{
        newnode->data=value;
        newnode->next=head;
        newnode->prev=nullptr;

        if(head!=nullptr){
            head->prev=newnode;
        }
        head = newnode;
        if(tail==nullptr){
            tail = head;
        }
    }
    cout<<"\nSuccessfully inserted\n\n";
    return 1;
}
//Function to display the list in both forward and reverse direction
void list::displayList(){
    if(!head){
        cout<<"Empty List\n";
        return;
    }
    else{
        cout<<"---------------Display----------------\n";
        node *temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n\n";

        cout<<"------------Reverse Display-----------\n";
        node *temp2 = tail;
        while(temp2){
            cout<<temp2->data<<" ";
            temp2=temp2->prev;
        }
        cout<<"\n\n";
    }
}
//Function to insert value in the end
int list::insertEnd(int value){
    node *newnode = (node *)malloc(sizeof(node));
    if(!newnode){
        cout<<"Memory Allocation failed\n";
        return 1;
    }
    else{
        newnode->data=value;
        newnode->prev=tail;
        newnode->next=nullptr;

        if(tail!=nullptr){
            tail->next=newnode;
        }
        tail = newnode;
        if(head==nullptr){
            head = tail;;
        }
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
    else{
        node *temp = head;
        if(head==tail){
            free(head);
            head = nullptr;
            tail = nullptr;
            cout<<"Deleted "<<temp->data<<"\n\n";
        }
        else{
            node *temp2 = tail;
            head = head->next;
            while(temp2->prev->prev){
                temp2=temp2->prev;
            }
            temp2->prev=nullptr;
            cout<<"Deleted "<<temp->data<<"\n\n";
            free(temp);
        }
        return 1;
    }
}
//Function to delete value in the end
int list::deleteEnd(){
    if(!tail){
        cout<<"Empty list, cannot delete\n\n";
        return 1;
    }
    else{
        node *temp = tail;
        if(tail==head){
            free(tail);
            head = nullptr;
            tail = nullptr;
            cout<<"Deleted "<<temp->data<<"\n\n";
        }
        else{
            node *temp2 = head;
            tail = tail->prev;
            while(temp2->next->next){
                temp2=temp2->next;
            }
            temp2->next=nullptr;
            cout<<"Deleted "<<temp->data<<"\n\n";
            free(temp);
        }
        return 1;
    }
}
//Function to search a value and return its position
void list::searchList(int value){
    node *temp = head;
    int pos = 1;
    int found=0;
    while(temp){
        if(temp->data==value){
            found = 1;
            cout<<"\nTarget Found at position "<<pos<<"\n\n";
            return;
        }
        temp=temp->next;
        pos++;
    }
    if(found==0){
        cout<<"Value not found\n\n";
    }
    return;
}

//Function to insert value at a position
int list::insertPos(int position, int value){
    if(position<1){
        cout<<"Enter a valid position\n\n";
        return 1;
    }
    else{
        if(position == 1){
            insertBeg(value);
            return 1;
        }
        else{
            node *newnode = (node *)malloc(sizeof(node));
            node *temp = head;
            newnode->data = value;
            for(int i=1; i<position-1; i++){
                temp = temp->next;
            }
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next->prev = newnode;
            temp->next = newnode;
        }
    }
    return 1;
}

//Function to delete value at a given position
int list::deletePos(int position){
    if(position<1){
        cout<<"Enter a valid position\n\n";
        return 1;
    }
    else{
        if(position==1){
            deleteBeg();
            return 1;
        }
        else{
            node *temp = head;
            for(int i = 1; i<position-1; i++){
                temp = temp->next;
            }
            node *delNode = temp->next;
            temp->next = delNode->next;
            delNode->next->prev = temp;
            cout<<"\nDeleted "<<delNode->data<<"\n\n";
            free(delNode);
        }
    }
    return 1;
}