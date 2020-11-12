//2572번 보드게임

#include <bits/stdc++.h>
using namespace std;

int n;
char color[1001];
int road[501][501];
vector<int> graph[501];
int dp[1001][501];

int solve(int i, int c){
    if(c==n) return 0;
    if(dp[c][i]!=-1) return dp[c][i];
    dp[c][i]=0;
    for(auto g:graph[i]){
        int s=0;
        if(road[i][g]==color[c]) s=10;
        dp[c][i]=max(dp[c][i], solve(g, c+1)+s);
    }
    return dp[c][i];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m, k, a, b;
    char c;
    cin>>n;
    for(int i=0; i<n; i++) cin>>color[i];
    cin>>m>>k;
    for(int i=0; i<k; i++){
        cin>>a>>b>>c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        road[a][b]=c;
        road[b][a]=c;
    }

    for(int i=0; i<=1000; i++){
        for(int j=0; j<=500; j++){
            dp[i][j]=-1;
        }
    }

    cout<<solve(1, 0)<<"\n";
}