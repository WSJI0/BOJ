// 1261번 알고스팟

#include <bits/stdc++.h>
using namespace std;
#define pi(X, Y, Z) make_pair(X, make_pair(Y, Z))

int n, m, board[101][101], dist[101][101];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    memset(dist, -1, sizeof(dist));
    dist[0][0]=0;
    queue<pair<int, pair<int, int>>> q;
    q.push(pi(0, 0, 0));

    while(!q.empty()){
        int y=q.front().second.first;
        int x=q.front().second.second;
        int d=q.front().first;
        q.pop();
        
    }
}