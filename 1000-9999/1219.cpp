//1219번 오민식의 고민

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, s, e, a, b, c;
int cost[101][101], dist[101], vil[101], visited[101];

int check(int j){
    queue<int> q;
    q.push(j);
    for(int i=0; i<100; i++) visited[i]=0;
    while(!q.empty()){
        int node=q.front(); q.pop();
        if(node==e) return true;
        visited[node]=1;
        for(int i=0; i<n; i++){
            if(cost[node][i]!=INF && !visited[i]) q.push(i);
        }
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>s>>e>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cost[i][j]=INF;
    }
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        cost[a][b]=min(cost[a][b], c);
    }
    for(int i=0; i<n; i++){
        cin>>vil[i];
        for(int j=0; j<n; j++){
            if(cost[j][i]!=INF) cost[j][i]-=vil[i];
        }
    }

    for(int i=0; i<n; i++) dist[i]=INF;
    dist[s]=-vil[s];
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            if(dist[j]==INF) continue;
            for(int k=0; k<n; k++){
                if(cost[j][k]!=INF && dist[k]>cost[j][k]+dist[j])
                    dist[k]=cost[j][k]+dist[j];
            }
        }
    }
    int tmp=dist[e];
    if(tmp==INF){
        cout<<"gg"<<"\n";
        return 0;
    }
    if(dist[e]!=INF)
        for(int i=0; i<n; i++){
            if(dist[i]==INF) continue;
            for(int j=0; j<n; j++){
                if(cost[i][j]!=INF && dist[j]>cost[i][j]+dist[i]){
                    dist[j]=cost[i][j]+dist[i];
                    if(check(j)){
                        cout<<"Gee"<<"\n";
                        return 0;
                    }
                }
            }
        } 

    cout<<-dist[e]<<"\n";
}