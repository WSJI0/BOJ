#include <bits/stdc++.h>
using namespace std;

int n, board[101][101];
bool visited[101][101];
int maxV=0, minV=9999;
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

bool bfs(int low, int high){
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));

    q.push(make_pair(0, 0));
    if(board[0][0]<low || board[0][0]>high) return false;
    while(!q.empty()){
        pair<int, int> node=q.front(); q.pop();
        for(int i=0; i<4; i++){
            int my=node.first+mv[i][0];
            int mx=node.second+mv[i][1];
            if(0<=my && my<n && 0<=mx && mx<n){
                if(board[my][mx]>high || board[my][mx]<low) continue;
                if(visited[my][mx]) continue;
                if(my==n-1 && mx==n-1) return true;
                visited[my][mx]=1;
                q.push(make_pair(my, mx));
            }
        }
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            maxV=max(maxV, board[i][j]);
            minV=min(minV, board[i][j]);
        }
    }

    int low=minV, high=minV;
    int ans=9999;

    while(low<=high && high<=maxV){
        if(bfs(low, high)){
            ans=min(ans, high-low);
            low++;
        } else high++;
    }

    cout<<ans<<"\n";
}