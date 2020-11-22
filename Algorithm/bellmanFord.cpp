/*
벨만 포드
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int v, e, a, b, c;
int cost[101][101];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>v>>e;
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        cost[a][b]=c;
    }
    int dist[101];
    for(int i=1; i<v; i++) dist[i]=INF;

    for(int i=0; i<v-1; i++){
        for(int j=0; j<v; j++){
            for(int k=0; k<v; k++){
                if(cost[j][k]!=0){
                    if(dist[j]!=INF && dist[k]>dist[j]+cost[j][k])
                        dist[k]=dist[j]+cost[j][k];
                }
            }
        }
    }
    for(int i=0; i<v; i++){
        cout<<dist[i]<<" ";
    } cout<<"\n";

}