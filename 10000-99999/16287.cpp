// 16287번 Parcel

#include <bits/stdc++.h>
using namespace std;

int w, n, a[5001];
bool dp[800001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>w>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(w-(a[i]+a[j])<0) continue;
            if(dp[w-(a[i]+a[j])]){
                cout<<"YES"<<"\n";
                return 0;
            }
        }
        for(int j=0; j<i; j++){
            if(a[i]+a[j]<=800000) dp[a[i]+a[j]]=1;
        }
    }
    cout<<"NO"<<"\n";
}