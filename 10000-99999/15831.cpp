//15831번 준표의 조약돌

#include <bits/stdc++.h>
using namespace std;

int l, r, n, b, w, ans, cnt[2];
char s[300001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>b>>w;
    for(int i=0; i<n; i++) cin>>s[i];
    
    while(l<n && r<n){
        do{
            if(s[r++]=='B') cnt[0]++;
            else cnt[1]++;
        } while(r<n && cnt[1]<w);

        if(cnt[0]<=b && cnt[1]>=w){
            ans=max(ans, r-l);
        }
        
        while(cnt[0]>b){
            if(s[l++]=='B') cnt[0]--;
            else cnt[1]--;
        }
    }
    cout<<ans<<"\n";
}