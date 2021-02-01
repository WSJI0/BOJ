// 2473번 세 용액

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll labs(ll n){
    return (n>0? n:-n);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    ll res=((ll)1<<62), ans[3];

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int l=i, r=j;
            while(l<=r){
                int mid=(l+r)/2;
                if(mid==i || mid==j) break;
                if(res>labs(a[i]+a[j]+a[mid])){
                    res=labs(a[i]+a[j]+a[mid]);
                    ans[0]=a[i], ans[1]=a[mid], ans[2]=a[j];
                }
                if(a[i]+a[j]+a[mid]>0) r=mid-1;
                else l=mid+1;
            }
        }
    }

    for(int i=0; i<3; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}