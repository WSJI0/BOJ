#include <bits/stdc++.h>
using namespace std;

int t;
string a, b, c;
int dp[201][201];

bool solve(int la, int lb){
    if(dp[la][lb]!=-1) return dp[la][lb];
    if(la==0 && lb==0) return true;

    dp[la][lb]=(c[la+lb-1]==a[la-1] && solve(la-1, lb)) || (c[la+lb-1]==b[lb-1] && solve(la, lb-1));
    return dp[la][lb];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>t;
    for(int i=1; i<=t; i++){
        memset(dp, -1, sizeof(dp));
        cin>>a>>b>>c;
        cout<<"Data set "<<i<<": "<<(solve(a.size(), b.size())? "yes":"no")<<"\n";
    }
}