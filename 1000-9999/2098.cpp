// 2098번 외판원 순회

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, dist[17][17];
int dp[17][1<<17];

int solve(int cur, int vis){
    if(dp[cur][vis]!=-1) return dp[cur][vis];
    if(vis==(1<<n)-1){
        if(dist[cur][0]!=0) return dist[cur][0];
        return INF;
    }
    dp[cur][vis]=INF;
    for(int i=0; i<n; i++){
        if(dist[cur][i]==0 || vis&(1<<i)) continue;
        dp[cur][vis]=min(dp[cur][vis], solve(i, vis|(1<<i))+dist[cur][i]);
    }
    return dp[cur][vis];
}


int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>dist[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout<<solve(0, 1)<<"\n";
}