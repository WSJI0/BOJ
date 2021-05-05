// 14517번 팰린드롬 개수 구하기 (Large)

#include <bits/stdc++.h>
using namespace std;
#define mod 10007

int dp[1001][1001], p[1001][1001];
bool visited[1001][1001];
string s;

bool check(int l, int r){
    if(p[l][r]!=-1) return p[l][r];
    if(l==r) return p[l][r]=1;
    if(l+1==r){
        if(s[l]==s[r]) return p[l][r]=1;
        return p[l][r]=0;
    } 
    return p[l][r]=(check(l+1, r-1) && s[l]==s[r]);
}
/*
int solve(int l, int r){
    if(visited[l][r]) return 0;
    if(l==r) return 1;
    if(l+1==r){
        if(check(l, r)) return 3;
        return 2;
    }
    int& ret=dp[l][r];
    if(ret!=-1) return ret;

    ret=0;
    visited[l][r]=1;
    if(check(l, r)) ret=1;

    for(int i=l; i<r; i++){
        ret=(ret+solve(l, i)+solve(i+1, r))%mod;
    }
    return ret;
}
*/
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<=1000; i++){
        for(int j=0; j<=1000; j++) p[i][j]=dp[i][j]=-1;
    }

    cin>>s;
    //cout<<solve(0, s.length()-1)<<"\n";

    int ans=0;
    for(int i=0; i<s.length(); i++){
        for(int j=i; j<s.length(); j++){
            if(check(i, j)) ans=(ans+1)%mod;
        }
    }
    cout<<ans<<"\n";
}