//11404번 플로이드

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m, a, b, c;
int dist[101][101];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++) dist[i][j]=INF;
    }

    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b], c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<((dist[i][j]==INF || i==j)? 0:dist[i][j])<<" ";
        } cout<<"\n";
    }
}