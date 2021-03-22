// 17387번 선분 교차 2

#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll, ll> a, b, c, d;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    ll res=(a.first*b.second+b.first*c.second+c.first*a.second)-(a.second*b.first+b.second*c.first+c.second*a.first);
    if(res>0) return 1;
    else if(res<0) return -1;
    return 0;
}

int solve(int A, int B){
    if(A==0 && B==0){
        if(a>b) swap(a, b);
        if(c>d) swap(c, d);
        return (c<=b && a<=d);
    }
    return (A<=0 && B<=0);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second>>d.first>>d.second;
    cout<<solve(ccw(a, b, c)*ccw(a, b, d), ccw(a, c, d)*ccw(b, c, d))<<"\n";
}