// 2629번 양팔저울

#include <bits/stdc++.h>
using namespace std;

int n, w[31], m, q;
bool dp[31][40001];

void solve(int cnt, int cur){
    if(cnt>n) return;

    if(dp[cnt][cur]) return;
    dp[cnt][cur]=1;

    solve(cnt+1, cur+w[cnt]);
    solve(cnt+1, cur);
    solve(cnt+1, abs(cur-w[cnt]));
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>w[i];

    solve(0, 0);

    cin>>m;
    for(int j=0; j<m; j++){
        cin>>q;
        if(dp[n][q] && q<=15000) cout<<"Y ";
        else cout<<"N ";
    } cout<<"\n";
}