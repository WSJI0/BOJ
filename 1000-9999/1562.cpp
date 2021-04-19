// 1562번 계단 수 (미완성)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000

int n;
int dp[101][10][1024];

int solve(int l, int d, int visited){
    if(l==n){
        if(visited==0) return 1;
        return 0;
    }
    if(dp[l][d][visited]!=-1) return dp[l][d][visited];

    ll res=0;
    if(d-1>=0){
        res+=solve(l+1, d-1, visited&~(1<<(d-1)));
    }
    if(d+1<=9){
        res+=solve(l+1, d+1, visited&~(1<<(d+1)));
    }
    return dp[l][d][visited]=res%mod;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    if(n<10) cout<<"0"<<"\n";
    else{
        ll ans=0;
        for(int i=1; i<=9; i++){
            memset(dp, -1, sizeof(dp));
            int visited=(1<<10)-1;
            ans=(ans+solve(1, i, visited&~(1<<i)))%mod;
        }

        cout<<ans<<"\n";
    }
}