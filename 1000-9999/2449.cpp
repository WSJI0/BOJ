// 2449번 전구

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, k, bb, b[202], dp[202][202];

int solve(int l, int r){
    int& ret=dp[l][r];
    if(ret!=INF) return ret;

    if(l==r) return 0;
    if(l+1==r){
        return (b[l]==b[r]? 0:1);
    }
    for(int i=l; i<r; i++){
        ret=min(ret, solve(l, i)+solve(i+1, r)+(b[l]==b[i+1]? 0:1));
    }
    return ret;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>k;
    for(int i=0; i<=200; i++){
        for(int j=0; j<=200; j++) dp[i][j]=INF;
    }

    int idx=0;
    cin>>b[0];
    for(int i=1; i<n; i++){
        cin>>bb;
        if(b[idx]!=bb) b[++idx]=bb;
    }

    cout<<solve(0, idx)<<"\n";
}