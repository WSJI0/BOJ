//9251번 LCS

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string a, b;
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>a>>b;
    for(int i=1; i<=b.length(); i++){
        for(int j=1; j<=a.length(); j++){
            if(b[i-1]==a[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout<<dp[b.length()][a.length()]<<"\n";
}