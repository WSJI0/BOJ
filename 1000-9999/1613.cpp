//1613번 역사

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, s, a, b;
    cin>>n>>k;

    int dp[401][401];
    for(int i=1; i<=400; i++){
        for(int j=1; j<=400; j++) dp[i][j]=0;
    }

    for(int i=0; i<k; i++){
        cin>>a>>b;
        dp[a][b]=-1;
        dp[b][a]=1;
    }
    for(int k=1; k<=400; k++){
        for(int i=1; i<=400; i++){
            for(int j=1; j<=400; j++){
                if(dp[i][k]==dp[k][j] && dp[i][k]!=0)
                    dp[i][j]=dp[i][k];
            }
        }
    }

    cin>>s;
    for(int i=0; i<s; i++){
        cin>>a>>b;
        cout<<dp[a][b]<<"\n";
    }
}