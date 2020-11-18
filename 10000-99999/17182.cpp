//17182 우주 탐사선

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

void backT(int);
int dp[10][10];
int n, k, b, ans=INF;
vector<int> travel;
bool visit[10];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) dp[i][j]=INF;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>b;
            dp[i][j]=b;
        }
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]>dp[i][k]+dp[k][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }
    travel.push_back(k);
    visit[k]=1;
    backT(1);
    cout<<ans<<"\n";
}

void backT(int p){
    if(p==n){
        int res=0;
        for(int i=0; i<p-1; i++){
            res+=dp[travel[i]][travel[i+1]];
        }
        ans=min(ans, res);
        return;
    }
    for(int j=0; j<n; j++){
        if(visit[j]) continue;
        travel.push_back(j);
        visit[j]=1;
        backT(p+1);
        travel.pop_back();
        visit[j]=0;
    }
}