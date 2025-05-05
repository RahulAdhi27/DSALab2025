#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int minRemove(vector<int> arr,int n);
int solve();

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 1;
}
//Solution for a single test case
int solve(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<minRemove(arr, n)<<"\n";
    return 1;
}
//Function to find the minimum number of elements to be deleted from the left
int minRemove(vector<int> arr, int n){
    unordered_set<int> seen;
    int count=0;

    for(int i=n-1; i>=0; i--){
        if(seen.count(arr[i])){
            break;
        }
        seen.insert(arr[i]);
        count++;
    }
    return n-count;
}