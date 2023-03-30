#include <bits/stdc++.h>
using namespace std;

int n, m, dp[1001][1001];
char board[1001][1001];
bool visited[1001][1001];
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
int parent[1000*1000+1];
int level[1000*1000+1]={1, };

int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}

void merge(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return;
    if(level[u]>=level[v]){
        parent[v]=u;
        level[u]+=level[v];
    } else{
        parent[u]=v;
        level[v]+=level[u];
    }
}

void bfs(int cy, int cx){
    vector<pair<int, int>> adj;
    queue<pair<int, int>> q;
    q.push(make_pair(cy, cx));
    adj.push_back(make_pair(cy, cx));
    visited[cy][cx]=1;

    while(!q.empty()){
        int y=q.front().first; int x=q.front().second; q.pop();
        for(int i=0; i<4; i++){
            int my=y+mv[i][0];
            int mx=x+mv[i][1];
            if(0<=my && my<n && 0<=mx && mx<m){
                if(visited[my][mx]) continue;
                if(board[my][mx]=='1') continue;
                visited[my][mx]=1;
                q.push(make_pair(my, mx));
                adj.push_back(make_pair(my, mx));
                merge(y*m+x, my*m+mx);
            }
        } 
    }
    
    for(int i=0; i<adj.size(); i++){
        dp[adj[i].first][adj[i].second]=adj.size();
        
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(int i=0; i<=1000*1000; i++){
        parent[i]=i;
    }

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]) continue;
            if(board[i][j]=='0'){
                bfs(i, j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='0') cout<<0;
            else{
                int res=1;
                for(int k=0; k<4; k++){
                    int my=i+mv[k][0];
                    int mx=j+mv[k][1];
                    if(0<=my && my<n && 0<=mx && mx<m){
                        if(board[my][mx]=='0'){
                            bool ok=true;
                            for(int l=0; l<k; l++){
                                int my2=i+mv[l][0];
                                int mx2=j+mv[l][1];
                                if(0<=my2 && my2<n && 0<=mx2 && mx2<m){
                                    if(find(my*m+mx)==find(my2*m+mx2)) ok=false;
                                }
                            }
                            if(ok) res+=dp[my][mx];
                        }
                    }
                } cout<<res%10;
            }
        } cout<<"\n";
    }
}