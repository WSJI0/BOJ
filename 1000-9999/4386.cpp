#include <bits/stdc++.h>
using namespace std;

int n, visited[101];
pair<double, double> star[101];
double ans=0.0;

double get_dis(int s, int e){
    double v1=star[s].first-star[e].first;
    double v2=star[s].second-star[e].second;
    return sqrt(v1*v1+v2*v2);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>star[i].first>>star[i].second;

    priority_queue<pair<double, int>> pq;
    pq.push(make_pair(0.0, 0));

    while(!pq.empty()){
        pair<double, int> node=pq.top(); pq.pop();
        if(visited[node.second]) continue;
        ans-=node.first;
        visited[node.second]=1;

        for(int i=0; i<n; i++){
            if(i==node.second) continue;
            double dist=get_dis(node.second, i);
            pq.push(make_pair(-dist, i));
        }
    }

    cout<<ans<<"\n";
}