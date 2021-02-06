// 2098번 외판원 순회

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int w[17][17], n, dp[17][1<<17];

int solve(int cur, int visited){
    int& ret=dp[cur][visited];
    if(ret!=-1) return ret;
    if(visited==(1<<n)-1){
        if(w[cur][0]) return w[cur][0];
        return INF;
    }
    
    int res=INF;
    for(int i=0; i<n; i++){
        if(visited&(1<<i) || !w[cur][i]) continue;
        res=min(res, solve(i, visited|(1<<i))+w[cur][i]);
    } ret=res;
    return ret;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>w[i][j];
    }
    memset(dp, -1, sizeof(dp));
    
    cout<<solve(0, 1)<<"\n";
}