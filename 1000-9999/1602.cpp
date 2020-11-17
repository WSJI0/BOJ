//1602번 도망자 원숭이

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, q, a, b, c;
    int t[501];
    vector<pair<int, int>> ts;
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++) cin>>t[i];
    for(int i=1; i<=n; i++) ts.push_back(make_pair(t[i], i));
    sort(ts.begin(), ts.end());

    int dp[501][501];
    int dp2[501][501];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j]=INF;
            dp2[i][j]=INF;
        }
    }

    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        dp[a][b]=dp[b][a]=min(c, dp[a][b]);
        dp2[a][b]=dp2[b][a]=min(c+max(t[a], t[b]), dp2[a][b]);
    }
    for(int k=0; k<n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dp[i][j]>dp[i][ts[k].second]+dp[ts[k].second][j])
                    dp[i][j]=dp[i][ts[k].second]+dp[ts[k].second][j];
                if(dp2[i][j]>dp[i][j]+max(t[i], max(t[ts[k].second], t[j])))
                    dp2[i][j]=dp[i][j]+max(t[i], max(t[ts[k].second], t[j]));
            }
        }
    }

    while(q--){
        cin>>a>>b;
        if(dp2[a][b]==INF) cout<<"-1"<<"\n";
        else cout<<dp2[a][b]<<"\n";
    }

}