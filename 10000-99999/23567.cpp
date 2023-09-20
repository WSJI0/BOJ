#include <bits/stdc++.h>
using namespace std;

int n, k, c[10002];
int cnt[10002], cnt2[10002], c1, c2=1;
int ans=99999;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>c[i];
        cnt[c[i]]++;
    } c1=k;

    int l=0, r=0;
    cnt2[c[l]]++; cnt[c[l]]--;
    if(cnt[c[l]]==0) c1--;
    if(c1==k && c2==k) ans=min(ans, r-l+1); 

    while(l<=r && r<n){
        if(c2!=k){
            r++;
            if(r<n){
                if(cnt2[c[r]]==0) c2++;
                cnt2[c[r]]++;
                cnt[c[r]]--;
                if(cnt[c[r]]==0) c1--;
            }
        } else{
            if(cnt2[c[l]]==1) c2--;
            if(cnt[c[l]]==0) c1++;
            cnt2[c[l]]--;
            cnt[c[l]]++;
            l++;
        }
        if(c1==k && c2==k) ans=min(ans, r-l+1); 
    }

    cout<<(ans!=99999? ans:0)<<"\n";
}