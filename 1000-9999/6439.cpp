// 6439번 교차

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define p(X, Y) make_pair(X, Y)

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
    
    int t, x1, y1, x2, y2, xl, yt, xr, yb;
    cin>>t;
    while(t--){
        cin>>x1>>y1>>x2>>y2>>xl>>yt>>xr>>yb;

        bool ans=false;
        if(cross(p(x1, y1), p(x2, y2), p(xl, yt), p(xl, yb))) ans=true;
        else if(cross(p(x1, y1), p(x2, y2), p(xl, yt), p(xr, yt))) ans=true;
        else if(cross(p(x1, y1), p(x2, y2), p(xr, yb), p(xr, yt))) ans=true;
        else if(cross(p(x1, y1), p(x2, y2), p(xr, yb), p(xl, yb))) ans=true;

        if(min(xl, xr)<=x1 && x1<=max(xl, xr) && min(yt, yb)<=y1 && y1<=max(yt, yb)) ans=true;

        cout<<(ans? "T":"F")<<"\n";
    }
}