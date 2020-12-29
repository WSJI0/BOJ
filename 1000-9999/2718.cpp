//2718 타일 채우기

#include <bits/stdc++.h>
using namespace std;

int t, n, dp[500][5];

int solve(int l, int type){
    if(l<0) return 0;
    int& cur=dp[l][type];
    if(cur!=-1) return cur;
    if(type==0){
        cur=solve(l-1, 0)+solve(l-2, 0)+solve(l-1, 1)+solve(l-1, 2)+solve(l-1, 3);
    } else if(type==1){
        cur=solve()
    }

    return cur;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp, -1, sizeof(dp));
        cout<<solve(n, 0)<<"\n";
    }
}