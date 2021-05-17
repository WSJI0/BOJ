// 2618번 경찰차

#include <bits/stdc++.h>
using namespace std;

int n, w, ans=INT_MAX;
int dp[201];
pair<int, int> ev[1001];

void solve(int a, int b, int cnt, int cur){
    if(dp[cur]!=-1) return dp[cur];
    if(cnt==w+2){
        ans=min(ans, cur);
        return;
    }
    solve(cnt, b, cnt+1, cur+abs(ev[a].first-ev[cnt].first)+abs(ev[a].second-ev[cnt].second));
    solve(a, cnt, cnt+1, cur+abs(ev[b].first-ev[cnt].first)+abs(ev[b].second-ev[cnt].second));
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>w;
    for(int i=2; i<w+2; i++){
        cin>>ev[i].first>>ev[i].second;
    }

    solve(0, 1, 2, 0);
    cout<<ans<<"\n";
}