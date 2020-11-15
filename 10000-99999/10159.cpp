//10159 저울

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b;
    cin>>n>>m;
    int dp[101][101];
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++) dp[i][j]=0;
    }

    while(m--){
        cin>>a>>b;
        dp[a][b]=1;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dp[i][k]==1 && dp[k][j]==1)
                    dp[i][j]=1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=1; j<=n; j++){
            if(dp[i][j]==0 && dp[j][i]==0) cnt++;
        }
        cout<<cnt-1<<"\n";
    }
}