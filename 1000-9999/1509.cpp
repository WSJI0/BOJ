//1509 팰린드롬 분할

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

string s;
int dp[2501], p[2501][2501];

int check(int l, int r){
    if(l==r) return p[l][r]=1;
    if(l+1==r){
        if(s[l]==s[r]) return 1;
        return 0;
    }
    if(p[l][r]!=INF) return p[l][r];
    if(check(l+1, r-1)==1 && s[l]==s[r]) return p[l][r]=1;
    return p[l][r]=0;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>s;
    for(int i=0; i<2500; i++){
        for(int j=0; j<2500; j++){
            p[i][j]=INF;
        } dp[i]=INF;
    }

    dp[0]=1;
    for(int i=1; i<s.size(); i++){
        dp[i]=dp[i-1]+1;
        if(check(0, i)){
            dp[i]=1;
            continue;
        }
        for(int j=1; j<i; j++){
            if(check(j, i)){
                dp[i]=min(dp[i], dp[j-1]+1);
            }
        }
    }
    cout<<dp[s.size()-1]<<"\n";
}