// 15321번 이상한 토너먼트

#include <bits/stdc++.h>
using namespace std;

int n, dp[500][500], dp2[500][500], a[500];

int solve(int l, int r){
    if(dp[l][r]!=0) return dp[l][r];
    if(r-l==1){
        dp2[l][r]=max(a[l], a[r]);
        return dp[l][r]=(int)abs(a[r]-a[l]);
    } 
    else if(r<l) return INT_MAX;
    else if(r==l){
        dp2[l][r]=a[l];
        return dp[l][r]=0;
    }
    int res=INT_MAX;
    for(int i=l; i<r; i++){
        int rr=solve(l, i)+solve(i+1, r)+(int)abs(dp2[l][i]-dp2[i+1][r]);
        if(res>rr){
            res=rr;
            dp2[l][r]=max(dp2[l][i], dp2[i+1][r]);
        }
    }
    return dp[l][r]=res;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    cout<<solve(0, n-1)<<"\n";
}