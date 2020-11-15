//2610번 회의준비

#include <bits/stdc++.h>
using namespace std;

bool team[101];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, a, b;
    cin>>n>>k;
    int dp[101][101];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) dp[i][j]=987654321;
    }

    while(k--){
        cin>>a>>b;
        dp[a][b]=1;
        dp[b][a]=1;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dp[i][j]>dp[i][k]+dp[k][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }

    vector<int> mV(n+1);
    for(int i=1; i<=n; i++){
        int res=0;
        for(int j=1; j<=n; j++)
            if(res<dp[i][j] && dp[i][j]!=987654321 && i!=j) res=dp[i][j];
        mV[i]=res;
    }

    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(team[i]) continue;
        int r=0; int rm=987654321;
        for(int j=1; j<=n; j++){
            if(dp[i][j]!=987654321){
                if(rm>mV[j]){
                    rm=mV[j];
                    r=j;
                }
                team[j]=1;
            }
        }
        if(r==0) ans.push_back(i);
        else ans.push_back(r);
    }

    cout<<ans.size()<<"\n";
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<"\n";
}