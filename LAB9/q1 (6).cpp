#include <iostream>
#include <algorithm>

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
    int k, q;
    cin>>k>>q;

    int eliminator[k], persons[q];

    for(int i=0; i<k; i++){
        cin>>eliminator[i];
    }
    int minEliminator=eliminator[0];

    for(int i=0; i<q; i++){
        cin>>persons[i];
    }

    for(int i=0; i<q; i++){
        cout<<"Output: "<<min(persons[i], minEliminator-1)<<" ";
    }
    cout<<"\n";
    return 1;
}
