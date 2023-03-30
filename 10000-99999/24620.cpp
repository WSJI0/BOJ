#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int t, n;
ll a[100001], s, m;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>t;
    while(t--){
        s=m=0;

        cin>>n;
        for(int i=0; i<n; i++){
            cin>>a[i];
            s+=a[i];
            m=max(m, a[i]);
        }

        for(int i=n; i>=1; i--){
            if(s%i!=0 || (s/i)<m) continue;
            ll cur=0;
            bool ok=true;

            for(int j=0; j<n; j++){
                cur+=a[j];
                if(cur==(s/i)) cur=0;
                else if(cur>(s/i)){
                    ok=false;
                    break;
                }
            }
            if(cur!=0) ok=false;
            if(ok){
                cout<<n-i<<"\n";
                break;
            }
        }
    }
}