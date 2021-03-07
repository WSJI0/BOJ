//1509 팰린드롬 분할 (미완성)

#include <bits/stdc++.h>
using namespace std;

string s;
int dp[2501][2501];
bool p[2501][2501];

bool check(int l, int r){
    if(l==r) return 1;
    if(p[l][r]!=-1) return p[l][r];
    if(r-1==l && s[l]==s[r]) return p[l][r]=1;
    else p[l][r]=0;

    if(r>l) return 0;

    return p[l][r]=(check(l+1, r-1) && (s[l]==s[r]));
}

int solve(int l, int r){
    if(l==r) return 1;
    int& ret=dp[l][r];

    if(ret!=-1) return ret; 
    ret=0;
    if(p[l][r]==1) ret++;
    
    for(int i=l; i<r; i++){
        int L=solve(l, i), R=solve(i+1, r);
        if(L && R) ret++;
    }
    return ret;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>s;
    memset(dp, -1, sizeof(dp));
    memset(p, -1, sizeof(p));

    cout<<solve(0, s.size()-1)<<"\n";
}