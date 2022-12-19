/*
1806번
부분합
*/

#include <bits/stdc++.h>
using namespace std;

int n, s, a[100001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>s;
    for(int i=0; i<n; i++) cin>>a[i];

    int l=0, r=0, cur=a[0], ans=INT_MAX;

    while(r<n){
        if(cur<s) cur+=a[++r];
        else{
            ans=min(ans, r-l+1);
            cur-=a[l++];
        }
    }
    
    if(ans!=INT_MAX) cout<<ans<<"\n";
    else cout<<"0"<<"\n";
}
