// 17386번 선분 교차 1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    ll res=(x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1);
    if(res>0) return 1;
    else if(res<0) return -1;
    return 0;
}

int solve(int a, int b){
    return (a<=0 && b<=0);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll x1, x2, x3, x4, y1, y2, y3, y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    cout<<solve(ccw(x1, y1, x2, y2, x3, y3)*ccw(x1, y1, x2, y2, x4, y4), ccw(x3, y3, x4, y4, x1, y1)*ccw(x3, y3, x4, y4, x2, y2))<<"\n";
}