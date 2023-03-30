#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int t, n, m, k;
int u, v, c, d;
int dist[101][101][2];
int dp[101][10001];

int solve(int cur, int cost){
    if(cur==0){

    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while(t--){
        for(int i=0; i<=100; i++){
            for(int j=0; j<=10000; j++) dp[i][j]=INF;
        }

        cin>>n>>m>>k;
        for(int i=0; i<k; i++){
            cin>>u>>v>>c>>d;
            dist[u][v][0]=c;
            dist[u][v][1]=d;
        }

        int ans=987654321;
        for(int i=0; i<=10000; i++){
            ans=min(ans, solve(n, i));
        }
    }
}