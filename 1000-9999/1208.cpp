// 1208번 부분수열의 합 2 (미완성)

#include <bits/stdc++.h>
using namespace std;

int n, s, a[41], l, cur, tmp, ans;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>s;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int r=0; r<n; r++){
        cur+=a[r];
        if(cur==s) ans++;

        tmp=cur;
        for(int l=0; l<r; l++){
            tmp-=a[l];
            if(tmp==s) ans++;
        }
    }
    cout<<ans<<"\n";
}