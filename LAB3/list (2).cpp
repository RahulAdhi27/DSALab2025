#include <iostream>
using namespace std;

#define SIZE 5

class List{
    private:
    int arr[SIZE];
    int currentSize = 0;
    int found = 0;
    int current = 0;
    int last;

    public:
    int insertBeg(int);
    void display();
    int insertEnd(int);
    int insertPos(int, int);
    int deleteBeg();
    int deleteEnd();
    int deletePos(int);
    void search(int);
    int rotate1(int);
    int rotate2(int);
};

int main(){
    List list;
    int value, choice, position, k, choice2;
    

    cout<<"These are the options:\n";
    cout<<"1. Insert Beginning\n";
    cout<<"2. Insert End\n";
    cout<<"3. Insert Position\n";
    cout<<"4. Delete Beginning\n";
    cout<<"5. Delete End\n";
    cout<<"6. Delete Position\n";
    cout<<"7. Search\n";
    cout<<"8. Rotate\n";
    cout<<"9. Display\n";
    cout<<"10. Exit\n";

    while(1){
        cout<<"Enter your choice now: ";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter value to insert in the beginning: ";
            cin>>value;
            cout<<"\n";
            list.insertBeg(value);
            break;

            case 2:
            cout<<"Enter value to insert in the end: ";
            cin>>value;
            cout<<"\n";
            list.insertEnd(value);
            break;

            case 3:
            cout<<"Enter position to insert value: ";
            cin>>position;
            cout<<"\n";
            cout<<"Enter value to insert in the position ";
            cin>>value;
            cout<<"\n";
            list.insertPos(position, value);
            break;

            case 4:
            list.deleteBeg();
            break;

            case 5:
            list.deleteEnd();
            break;

            case 6:
            cout<<"Enter position to delete: ";
            cin>>position;
            list.deletePos(position);
            break;

            case 7:
            cout<<"Enter target to search: ";
            cin>>value;
            list.search(value);
            break;

            case 8:
            cout<<"Rotating the list. Enter how many values to be rotated at a time: ";
            cin>>k;
            cout<<"1. Method 1\n";
            cout<<"2. Method 2\n";
            cout<<"3. Not Interested";

            cout<<"Enter which method to use: ";
            cin>>choice2;
            switch(choice2){
                case 1:
                list.rotate1(k);
                break;

                case 2:
                list.rotate2(k);
                break;

                case 3:
                cout<<"Ok...\n";
                break;

                default:
                cout<<"Enter valid option\n";


            }
            break;

            case 9:
            cout<<"The elements of the array are: \n";
            list.display();
            break;

            case 10:
            cout<<"Exiting...\n";
            return -1;
            break;

            default:
            cout<<"Invalid number\n";
            break;
            
        }
    }
}

int List::insertBeg(int value){
    if(currentSize>=SIZE){
        cout<<"List is full\n";
    }
    else{
        for(int i=currentSize; i>0; i--){
            arr[i]=arr[i-1];
        }
        arr[0] = value;
        currentSize++;
        current = currentSize-1;
    }
    return 1;
}

void List::display(){
    for(int i=0; i<currentSize; i++){
        cout<<arr[i] <<" ";
    }
    cout<<"\n";
}


int List::insertEnd(int value){
    if(currentSize>=SIZE){
        cout<<"List is full\n";
    }
    else{
        arr[currentSize] = value;
        currentSize++;
        current = currentSize-1;
    }
    return 1;
}

int List::insertPos(int position, int value){
    if(currentSize>=SIZE){
        cout<<"List is full\n";
    }
    else{
        for(int i=currentSize; i>position; i--){
            arr[i]=arr[i-1];
        }
        arr[position] = value;
        currentSize++;
        current = currentSize-1;
    }
    return 1;
}

int List::deleteBeg(){
    if(currentSize==0){
        cout<<"Empty List\n";
    }
    else{
        for(int i=0; i<currentSize-1; i++){
            arr[i] = arr[i+1];
        }
        currentSize--;
        current=currentSize-1;
        return arr[0];
    }
    return 1;
}

int List::deleteEnd(){
    if(currentSize==0){
        cout<<"Empty List\n";
    }
    else{
        currentSize--;
        current=currentSize-1;
        return arr[current];
    }
    return 1;
}

int List::deletePos(int position){
    if(currentSize==0){
        cout<<"Empty List\n";
    }
    else{
        for(int i=position; i<currentSize-1; i++){
            arr[i] = arr[i+1];
        }
        currentSize--;
        current=currentSize-1;
        return arr[position];
    }
    return 1;
}

void List::search(int value){
    found=0;
    for(int i=0; i<currentSize; i++){
        if(arr[i]==value){
            cout<<"Target found, its index is: "<<i <<"\n";
            found=1;
        }
    }
    if(found==0){
        cout<<"Target not found\n";
    }
}

int List::rotate1(int k){
    if(k>=SIZE){
        cout<<"Rotation cannot be done. Enter a value less than "<<k;
    }
    else{
        current=currentSize-1;
        for(int i=0; i<k; i++){
            last=arr[current];
            for(int i=current; i>0; i--){
                arr[i]=arr[i-1];
            }
            arr[0]=last;
            
        }
    }
    return 1;
}


int List::rotate2(int k){
    if(k>=SIZE){
        cout<<"Rotation cannot be done. Enter a value less than "<<k;
    }

    for(int i=0,j=currentSize-1; i<(currentSize-1)/2, j>(currentSize-1)/2; i++, j--){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    for(int i=0,j=k-1; i<k, j>0; i++, j--){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    for(int i=k,j=currentSize-1; i<(currentSize+1)/2, j>(currentSize+1)/2; i++, j--){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    return 1;
}

