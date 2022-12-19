// 1069번 집으로

#include <bits/stdc++.h>
using namespace std;

int x, y, d, t;
double dis, ans=1500.0;
int visited[1414];

void solve(int cur, int time);

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>x>>y>>d>>t;
    dis=sqrt(x*x+y*y);

    memset(visited, 987654321, sizeof(visited));
    solve(0, 0);

    cout<<fixed;
    cout.precision(15);
    cout<<ans<<"\n";
}

void solve(int cur, int time){
    if(time>=ans) return;
    if(cur==dis) ans=min(ans, (double)time);

    if(dis<=cur+(2*d)) ans=min(ans, (double)time+(t*2));
    if(cur<dis) solve(cur+d, time+t);
    
    ans=min(ans, abs(dis-cur)+time);
}