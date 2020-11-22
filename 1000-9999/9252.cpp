//9252번 LCS2

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string a, b;
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>a>>b;
    a="0"+a; b="0"+b;

    for(int i=1; i<b.length(); i++){
        for(int j=1; j<a.length(); j++){
            if(b[i]==a[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    int idx=a.length()-1;
    int tmp1=dp[b.length()-1][a.length()-1];
    int tmp0=tmp1-1;
    string ans="";

    for(int i=b.length()-1; i>0; i--){
        for(int j=idx; j>0; j--){
            if(dp[i][j]==tmp1 && dp[i][j-1]==tmp0 && dp[i-1][j-1]==tmp0 && dp[i-1][j]==tmp0){
                tmp0--; 
                tmp1--;
                ans=b[i]+ans;
                idx=j;
                break;
            }
        }
    }
    cout<<dp[b.length()-1][a.length()-1]<<"\n";
    cout<<ans<<"\n";
}