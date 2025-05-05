#include <iostream>
#include <string>
#include <vector>

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

int solve(){
    int n;
    cin>>n;

    vector<string> p1(n), p2(n), p3(n);

    for(int i=0; i<n; i++){
        cin>>p1[i];
    }

    for(int i=0; i<n; i++){
        cin>>p2[i];
    }

    for(int i=0; i<n; i++){
        cin>>p3[i];
    }

    int score1 = 0, score2 = 0, score3 = 0;

    for(int i=0; i<n; i++){
        int count=1;
        for(int j=0; j<n; j++){
            if(p2[j]==p1[i]){
                count++;
            }
        }
        for(int j=0; j<n; j++){
            if(p3[j]==p1[i]){
                count++;
            }
        }
        if(count==1){
            score1+=3;
        }
        else if(count==2){
            score1+=1;
        }
    }

    for(int i=0; i<n; i++){
        int count=1;
        for(int j=0; j<n; j++){
            if(p1[j]==p2[i]){
                count++;
            }
        }
        for(int j=0; j<n; j++){
            if(p3[j]==p2[i]){
                count++;
            }
        }
        if(count==1){
            score2+=3;
        }
        else if(count==2){
            score2+=1;
        }
    }

    for(int i=0; i<n; i++){
        int count=1;
        for(int j=0; j<n; j++){
            if(p2[j]==p3[i]){
                count++;
            }
        }
        for(int j=0; j<n; j++){
            if(p1[j]==p3[i]){
                count++;
            }
        }
        if(count==1){
            score3+=3;
        }
        else if(count==2){
            score3+=1;
        }
    }
    cout<<score1<<" "<<score2<<" "<<score3<<"\n";
    return 1;
}