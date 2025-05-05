#include <iostream>
using namespace std;
//Sorting the array in ascending order from the 2nd element onwards
int sort(int arr[], int size){
    for(int i=1; i<size; i++){
        int minIdx = i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
    return 1;
}
//Find the maximum possible blocks in tower 1
int maxFirstTower(int arr[], int size){
    int tower1 = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i]>tower1){
            while(arr[i]>tower1){
                arr[i]--;
                tower1++;
            }
        }
    }
    return tower1;
}

void showOutput(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\n";
    }
}

int main(){
    cout<<"--------------------Input---------------------\n";
    int testCases;
    cin>>testCases;
    int results[testCases];
    int x=0;
    while(x!=testCases){
        int size;
        cin>>size;

        int arr[size];
        
        for(int i=0; i<size; i++){
            cin>>arr[i];
        }

        sort(arr, size);
        
        int r = maxFirstTower(arr, size);
        results[x] = r;
        x++;

    }
    cout<<"--------------------Output---------------------\n";
    showOutput(results, x);
    return 1;
}