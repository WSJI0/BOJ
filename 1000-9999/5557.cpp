//5557번 1학년

#include <bits/stdc++.h>
using namespace std;

long long int dp[101][21], n;
int p[101];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++) cin>>p[i];
    dp[0][p[0]]=1;

    for(int i=1; i<n-1; i++){
        for(int j=0; j<=20; j++){
            if(j-p[i]>=0)
                dp[i][j]+=dp[i-1][j-p[i]];
            if(j+p[i]<=20)
                dp[i][j]+=dp[i-1][j+p[i]];
        }
    }
    cout<<dp[n-2][p[n-1]];
}