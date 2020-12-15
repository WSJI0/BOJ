#include <bits/stdc++.h>
using namespace std;

int dp[102][102][102];
string a, b, c;
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>a>>b>>c;
    a="0"+a; b="0"+b; c="0"+c;
    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            for(int k=1; k<=c.length(); k++){
                if(a[i]==b[j] && b[j]==c[k]) dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else dp[i][j][k]=max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
            }
        }
    }

    cout<<dp[a.length()][b.length()][c.length()]-1<<"\n";
}