#include <bits/stdc++.h>
using namespace std;

int n, mv, mi, a[1001], dp[1001];
int ans[1001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i]>a[j]) dp[i]=max(dp[i], dp[j]+1);
        }
        if(dp[i]>mv){
            mv=dp[i];
            mi=i;
        }
    }

    int cur=0;
    for(int i=mi; i>=0; i--){
        if(dp[i]==mv){
            ans[cur++]=a[i];
            mv--;
        }
    }

    cout<<cur<<"\n";
    for(int i=cur-1; i>=0; i--){
        cout<<ans[i]<<" ";
    } cout<<"\n";
}