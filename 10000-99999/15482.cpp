#include <bits/stdc++.h>
using namespace std;

char a[1002], b[1002];
int dp[1002][1002];

int main(void){
    scanf("%s %s", a, b);
    for(int i=strlen(a); i>0; i--) a[i]=a[i-1];
    for(int i=strlen(b); i>0; i--) b[i]=b[i-1];


    cout<<strlen(a)<<" "<<strlen(b)<<"\n";
    int ans=0;
    for(int i=1; i<=strlen(a)-1; i++){
        for(int j=1; j<=strlen(b)-1; j++){
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            ans=max(ans, dp[i][j]);
        }
    }
    cout<<ans<<"\n";
}