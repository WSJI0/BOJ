/*
MST - Kruskal (크루스칼)
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int v, e, a, b, c, parent[10001];

int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}

void merge(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return;
    if(u<v) parent[v]=u;
    else parent[u]=v;
}

bool check(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return true;
    else return false;
}

class Node{
    public:
        int s, e, cost;
        Node(int a, int b, int c):s(a), e(b), cost(c){}
        bool operator<(Node &node){
            return this->cost<node.cost;
        }
};

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>v>>e;

    for(int i=0; i<=v; i++){
        parent[i]=i;
    }

    vector<Node> graph;
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        graph.push_back(Node(a, b, c));
    }

    sort(graph.begin(), graph.end());

    int ans=0;
    for(int i=0; i<graph.size(); i++){
        if(!check(graph[i].s, graph[i].e)){
            ans+=graph[i].cost;
            merge(graph[i].s, graph[i].e);
        }
    }

    cout<<ans<<"\n";

}