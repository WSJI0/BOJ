#include <bits/stdc++.h>
using namespace std;

int n, u, v;
int w[10002], dp[10002][2], ans[10002];
vector<int> graph[10002];
vector<int> arr;

int solve(int cur, int sel, int pre){
    if(dp[cur][sel]) return dp[cur][sel];

    if(sel) dp[cur][sel]+=w[cur];
    for(auto g:graph[cur]){
        if(g==pre) continue;
        if(sel){
            dp[cur][sel]+=solve(g, 0, cur);
        } else{
            int v1=solve(g, 1, cur);
            int v2=solve(g, 0, cur);
            if(v1>v2){
                dp[cur][sel]+=v1;
                ans[g]=1;
            } else{
                dp[cur][sel]+=v2;
                ans[g]=0;
            }
        }
    }
    return dp[cur][sel];
}

void print_ans(int cur, int sel, int pre){
    if(sel) arr.push_back(cur);
    for(auto g:graph[cur]){
        if(g==pre) continue;
        if(sel) print_ans(g, 0, cur);
        else print_ans(g, ans[g], cur);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>w[i];
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int v1=solve(1, 1, 0);
    int v2=solve(1, 0, 0);
    if(v1>v2){
        cout<<v1<<"\n";
        ans[1]=1;
    } else{
        cout<<v2<<"\n";
    }
    
    print_ans(1, ans[1], 0);
    sort(arr.begin(), arr.end());

    for(auto i:arr) cout<<i<<" ";
    cout<<"\n";
}