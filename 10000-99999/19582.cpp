//19582 200년간 폐관수련했더니 PS 최강자가 된 건에 대하여

#include <bits/stdc++.h>
using namespace std;

int n, cp[100001][2], dp[100001][2];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>cp[i][0]>>cp[i][1];
    }
    dp[0][1]=cp[0][1];
    for(int i=1; i<n; i++){
        if(cp[i][0]>=dp[i-1][1]){
            dp[i][1]=cp[i][1]+dp[i-1][1];
        }
        if(cp[i][0]>=dp[i-1][0]){
            dp[i][0]=dp[i-1][1];
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cout<<dp[j][i]<<" ";
        } cout<<"\n";
    }


    int cnt=0;
    for(int i=0; i<n; i++){
        if(dp[i][1]==0 && dp[i][0]==0) cnt++;
    }
    if(cnt>=2) cout<<"Zzz"<<"\n";
    else cout<<"Kkeo-eok"<<"\n";
}