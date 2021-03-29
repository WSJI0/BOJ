// 2162번 선분 그룹

#include <bits/stdc++.h>
using namespace std;

int parent[3001], cnt[3001];

int find(int u){
    if(u==parent[u]) return u;
    return parent[u]=find(parent[u]);
}

void merge(int u, int v){
    u=find(u); v=find(v);
    if(u==v) return;
    if(u>v) parent[u]=v;
    else parent[v]=u;
}

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    int res=(a.first*b.second+b.first*c.second+c.first*a.second)-(a.second*b.first+b.second*c.first+c.second*a.first);
    if(res>0) return 1;
    else if(res<0) return -1;
    return 0;
}

bool cross(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d){
    int A=ccw(a, b, c)*ccw(a, b, d);
    int B=ccw(a, c, d)*ccw(b, c, d);
    if(A==0 && B==0){
        if(a>b) swap(a, b);
        if(c>d) swap(c, d);
        return (c<=b && a<=d);
    }
    return (A<=0 && B<=0);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    pair<int, int> line[3001][2];
    cin>>n;

    for(int i=0; i<n; i++) parent[i]=i;

    for(int i=0; i<n; i++){
        cin>>line[i][0].first>>line[i][0].second;
        cin>>line[i][1].first>>line[i][1].second;
        for(int j=0; j<i; j++){
            if(cross(line[i][0], line[i][1], line[j][0], line[j][1]))
                merge(i, j);
        }
    }

    int ans1=0, ans2=0;
    for(int i=0; i<n; i++) cnt[find(i)]++;
    for(int i=0; i<n; i++){
        ans2=max(ans2, cnt[i]);
        if(cnt[i]) ans1++;
    }

    cout<<ans1<<"\n"<<ans2<<"\n";
}