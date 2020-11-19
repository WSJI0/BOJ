//2887번 행성 터널 (미완성)

#include <bits/stdc++.h>
using namespace std;

struct coor{
    int x, y, z;
};

bool cmpX(coor& p1, coor& p2){
    return p1.x>p2.x;
}
bool cmpY(coor& p1, coor& p2){
    return p1.y>p2.y;
}
bool cmpZ(coor& p1, coor& p2){
    return p1.z>p2.z;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x, y, z;
    cin>>n;
    vector<coor> planet(n);
    for(int i=0; i<n; i++){
        cin>>planet[i].x>>planet[i].y>>planet[i].z;
    }
    vector<pair<int, coor>> p;
    sort(planet.begin(), planet.end(), cmpX);
    for(int i=0; i<n-1; i++)
        p.push_back(make_pair(planet[i+1].x-planet[i].x, planet[i]));
    
}