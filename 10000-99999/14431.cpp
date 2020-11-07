//14431번 소수마을

#include <bits/stdc++.h>
using namespace std;

bool isPrime(pair<int, int>& a, pair<int, int>& b){
    int n=sqrt(pow(abs(a.first-b.first), 2)+pow(abs(a.second-b.second), 2));
    if(n%2==0 && n!=2) return false;
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0) return false;
    } return true;
}

int distance(int x1, int y1, int x2, int y2){
    return sqrt(pow(abs(x1-x2), 2)+pow(abs(y1-y2), 2));
}
vector<pair<pair<int, int>, int>> a;
vector<pair<pair<int, int>, int>> graph[6001][6001]={a};
int dist[6001][6001]={99999999};
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x1, y1, x2, y2, n, a, b;
    vector<pair<int, int>> coor;
    cin>>x1>>y1>>x2>>y2>>n;
    coor.push_back(make_pair(x1, y1));
    coor.push_back(make_pair(x2, y2));
    for(int i=0; i<n; i++){
        cin>>a>>b;
        coor.push_back(make_pair(a, b));
    }
    //unordered_map<const pair<int, int>, vector<pair<int, int>>> graph;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(isPrime(coor[i], coor[j]))
                graph[coor[i].first+3000][coor[i].second+3000].push_back(make_pair(coor[j], 0));
        }
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    dist[x1+3000][y1+3000]=0;
    pq.push(make_pair(0, make_pair(x1, x2)));
    while(!pq.empty()){
        int cost=-pq.top().first;
        pair<int, int> cur=pq.top().second;
        pq.pop();
        if(dist[cur.first+3000][cur.second+3000]<cost) continue;
        for(int i=0; i<graph[cur.first+3000][cur.second+3000].size(); i++){
            pair<int, int> f=graph[cur.first+3000][cur.second+3000][i].first;
            int nxt=cost+distance(cur.first, graph[cur.first+3000][cur.second+3000][i].first.first, cur.second, graph[cur.first+3000][cur.second+3000][i].first.second);
            if(dist[f.first+3000][f.second+3000]>nxt){
                dist[f.first+3000][f.second+3000]=nxt;
                pq.push(make_pair(-nxt, f));
            }
        }
    }
    if(dist[x2+3000][y2+3000]!=99999999) cout<<dist[x2+3000][y2+3000]<<"\n";
    else cout<<"-1"<<"\n";
}