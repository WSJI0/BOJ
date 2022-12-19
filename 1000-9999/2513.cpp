// 2513번 통학버스

#include <bits/stdc++.h>
using namespace std;

int n, k, s, x, a[100001], l, r;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>k>>s;
    l=n-1; r=0;
    for(int i=0; i<n; i++){
        cin>>x;
        cin>>a[x];
        if(x<l) l=x;
        if(x>r) r=x;
    }

    int ans=0;
    while(l<s){
        ans+=(s-l)*2;
        int cur=k;
        for(int i=l; i<s; i++){
            if(a[i]==0 || cur==0) continue;
            if(a[i]>=cur){
                a[i]-=cur;
                cur=0;
                break;
            } else{
                cur-=a[i];
                a[i]=0;
            }
        }
        while(a[l]==0 && l<s) l++;
    }
    while(r>s){
        ans+=(r-s)*2;
        int cur=k;
        for(int i=r; i>s; i--){
            if(a[i]==0 || cur==0) continue;
            if(a[i]>=cur){
                a[i]-=cur;
                cur=0;
                break;
            } else{
                cur-=a[i];
                a[i]=0;
            }
        }
        while(a[r]==0 && r>s) r--;
    }

    cout<<ans<<"\n";
}