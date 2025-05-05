#include <iostream>
using namespace std;

int solve();

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 1;
}
//Function that solves for each test case
int solve(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int max1=0;
    int max2=0;
    for(int i=0; i<n; i++){
        if(arr[i]>max1){
            max2=max1;
            max1=arr[i];
        }
        else if(arr[i]>max2){
            max2=arr[i];
        }
    }
    cout<<"Output: ";
    for(int i=0; i<n; i++){
        cout<<arr[i] - (arr[i]==max1 ? max2 : max1)<<" ";
    }
    cout<<"\n";
    return 1;
}