//2026번 소풍

#include <bits/stdc++.h>
using namespace std;

vector<int> fr[901];
int k, n, f, a, b;
int team[62];
bool ans=false;

bool isFriend(vector<int>& fr, int j){
    for(int i=0; i<fr.size(); i++){
        if(fr[i]==j) return true;
    }
    return false;
}

void print(int i){
    cout<<i<<" : ";
    for(int j=0; j<i; j++){
        cout<<team[j]<<" ";
    }cout<<"\n";
}

void solve(int i){
    if(ans) return;
    if(i==k){
        ans=true;
        for(int j=0; j<k; j++){
            cout<<team[j]<<"\n";
        }
        return;
    }
    for(int j=max(0, team[i-1]); j<=n; j++){
        bool res=true;
        for(int k=0; k<i; k++){
            if(!isFriend(fr[team[k]], j)) res=false;
        }
        if(res){
            team[i]=j;
            solve(i+1);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>k>>n>>f;
    for(int i=0; i<f; i++){
        cin>>a>>b;
        fr[a].push_back(b);
        fr[b].push_back(a);
    }

    solve(0);
    if(!ans){
        cout<<"-1"<<"\n";
    }
}