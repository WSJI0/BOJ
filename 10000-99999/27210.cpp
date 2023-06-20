#include <bits/stdc++.h>
using namespace std;

int n, a[100001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    int l=0, r=0, res=0, ans=0;
    while(r<n && l<=r){
        if(a[r]==1) res++;
        else res--;
        if(res<=0){
            res=0;
            l=r+1;
        }
        r++;
        ans=max(ans, res);
    } res=0; l=0; r=0;
    while(r<n && l<=r){
        if(a[r]==2) res++;
        else res--;
        if(res<=0){
            res=0;
            l=r+1;
        }
        r++;
        ans=max(ans, res);
    }

    cout<<ans<<"\n";
}