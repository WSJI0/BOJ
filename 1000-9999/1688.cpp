// 1688번 지민이의 테러

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    ll res=(a.first*b.second+b.first*c.second+c.first*a.second)-(a.second*b.first+b.second*c.first+c.second*a.first);
    if(res>0) return 1;
    else if(res<0) return -1;
    return 0;
}

bool cross(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d){
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
    pair<ll, ll> p[6], point[10001];

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>point[i].first>>point[i].second;
    }
    for(int i=0; i<3; i++) cin>>p[i].first>>p[i].second;

    for(int i=0; i<3; i++){
        pair<ll, ll> cur=p[i], curL=make_pair(1000000001, p[i].second+1);

        bool check=false; int cnt=0;
        for(int j=0; j<n; j++){
            pair<ll, ll> a=point[j], b=point[j+1];
            if(j==n-1) b=point[0];

            if(a.first==cur.first && a.second==cur.second){
                check=true; break;
            } else if(cross(cur, cur, a, b)){
                check=true; break;
            }
            if(cross(cur, curL, a, b)) cnt++;
        }
        if(check) cout<<"1"<<"\n";
        else{
            if(cnt%2==0) cout<<"0"<<"\n";
            else cout<<"1"<<"\n";
        }
    }
}