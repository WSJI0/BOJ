//12865번 평범한 배낭

#include <bits/stdc++.h>
using namespace std;

int n, k, dp[101][100001];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    vector<pair<int, int>> w(n);
    for(int i=0; i<n; i++){
        cin>>w[i].first>>w[i].second;
    }

    for(int i=1; i<=n; i++){
        int weight=w[i-1].first, val=w[i-1].second;
        for(int j=0; j<=k; j++){
            if(j<weight) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j], dp[i-1][j-weight]+val);
        }
    }
    cout<<dp[n][k]<<"\n";
}