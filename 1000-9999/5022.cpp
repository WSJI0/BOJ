#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define p(X, Y) make_pair(X, Y)

int n, m, ans1, ans2;
int a1[2], a2[2], b1[2], b2[2];
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
int board[101][101], dist[101][101];

void dijkstra(int sy, int sx, int ey, int ex){
    pair<int, int> visited[101][101];
    dist[sy][sx]=0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(p(0, p(sy, sx)));
    visited[sy][sx]=p(-1, -1);

    while(!pq.empty()){
        pair<int, pair<int, int>> node=pq.top(); pq.pop();
        int cy=node.second.first, cx=node.second.second;
        int cost=-node.first;

        for(int i=0; i<4; i++){
            int ny=mv[i][0]+cy;
            int nx=mv[i][1]+cx;
            int nc=cost+1;
            if(0<=ny && ny<=m && 0<=nx && nx<=n){
                if(board[ny][nx]) continue;
                if(dist[ny][nx]<=nc) continue;
                dist[ny][nx]=nc;
                pq.push(p(-nc, p(ny, nx)));
                visited[ny][nx]=p(cy, cx);
            }
        }
    }

    pair<int, int> cur=p(ey, ex);
    if(dist[ey][ex]==INF) return;
    while(cur.first!=-1){
        board[cur.first][cur.second]=1;
        cur=visited[cur.first][cur.second];
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m>>a1[0]>>a1[1]>>a2[0]>>a2[1]>>b1[0]>>b1[1]>>b2[0]>>b2[1];

    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++) dist[i][j]=INF;
    }
    board[b1[1]][b1[0]]=1;
    board[b2[1]][b2[0]]=1;
    dijkstra(a1[1], a1[0], a2[1], a2[0]);
    ans1+=dist[a2[1]][a2[0]];

    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++) dist[i][j]=INF;
    }
    board[b2[1]][b2[0]]=0;
    dijkstra(b1[1], b1[0], b2[1], b2[0]);
    ans1+=dist[b2[1]][b2[0]];

    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            dist[i][j]=INF;
            board[i][j]=0;
        }
    }
    board[a1[1]][a1[0]]=1;
    board[a2[1]][a2[0]]=1;
    dijkstra(b1[1], b1[0], b2[1], b2[0]);
    ans2+=dist[b2[1]][b2[0]];

    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++) dist[i][j]=INF;
    }
    board[a2[1]][a2[0]]=0;
    dijkstra(a1[1], a1[0], a2[1], a2[0]);
    ans2+=dist[a2[1]][a2[0]];

    if(min(ans1, ans2)>=INF) cout<<"IMPOSSIBLE"<<"\n";
    else cout<<min(ans1, ans2)<<"\n";
}