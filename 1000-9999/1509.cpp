//1509 팰린드롬 분할 (미완성)

#include <bits/stdc++.h>
using namespace std;

string s;
int dp[2501][2501];

int solve(int l, int r){
    if(l==r) return 1;

    int& ret=dp[l][r];
    if(ret!=-1) return ret; 
    for(int i=l; i<r; i++){
        
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>s;
    memset(dp, -1, sizeof(dp));

    cout<<solve(0, s.size()-1)<<"\n";
}