//11333번 4×n 타일링 (미완성)

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        long long int dp[10001];
        dp[3]=3;
        for(int i=6; i<=n; i+=3){
            long long int res1=dp[i-3]*3;
            //int res2=dp[i-3];
            dp[i]=res1%mod;//+res2;
        }
        cout<<dp[n]<<"\n";
    }
}