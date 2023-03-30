#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int T, n, m, t, s, g, h, a, b, d, x;
double cost;
int cur;
double road[2001][2001];
double dist[2001];

void dijkstra(int s){
    dist[s]=0.0;
    priority_queue<pair<double, int>> pq;

    pq.push(make_pair(0, s));
    while(!pq.empty()){
        tie(cost, cur)=pq.top(); pq.pop();
        cost*=-1;
        if(dist[cur]<cost) continue;
        for(int i=1; i<=n; i++){
            if(road[cur][i]==INF) continue;
            int nxt=cost+road[cur][i];
            if(dist[i]>nxt){
                dist[i]=nxt;
                pq.push(make_pair(-nxt, i));
            } 
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>T;
    while(T--){
        for(int i=0; i<=2000; i++){
            dist[i]=INF;
            for(int j=0; j<=2000; j++){
                road[i][j]=INF;
            }
        }

        cin>>n>>m>>t>>s>>g>>h;
        for(int i=0; i<m; i++){
            cin>>a>>b>>d;
            road[a][b]=road[b][a]=d;
            if((a==s && b==g) || (a==g && b==s)){
                road[a][b]=road[b][a]=(0.0+d);
            }
        }
        dijkstra(s);

        vector<int> ans;
        for(int i=0; i<t; i++){
            if(ceil(dist[x]-floor(dist[x]))==1) ans.push_back(x); 
        }
        sort(ans.begin(), ans.end());

        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}