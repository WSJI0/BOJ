//11062번 카드 게임 (미완성)

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int card[1000];
        for(int i=0; i<n; i++) cin>>card[i];
        int dp[1000][2];
        for(int i=0; i<n; i++) dp[i][0]=dp[i][1]=0;
        dp[0][0]=dp[0][1]=card[0];
        dp[n-1][0]=dp[n-1][1]=card[n-1];
        for(int i=0; i<n; i++){
            dp[i][0]=dp[n-i-1][1];
        }
    }
}