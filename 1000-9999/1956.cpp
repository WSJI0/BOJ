// 1956번 운동

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int dp[401][401];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int v, e, a, b, c;
    cin>>v>>e;
    for(int i=1; i<=400; i++){
        for(int j=1; j<=400; j++){
            dp[i][j]=INF;
        }
    }
    
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        dp[a][b]=min(dp[a][b], c);
    }

    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                if(dp[i][j]>dp[i][k]+dp[k][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }

    int ans=INF;
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(dp[i][j]==INF || dp[j][i]==INF || i==j) continue;
            ans=min(ans, dp[i][j]+dp[j][i]);
        }
    }
    cout<<(ans!=INF? ans:-1)<<"\n";
}