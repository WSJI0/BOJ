#include <bits/stdc++.h>
using namespace std;

int n, f[1000001];
string s;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>s;
    n=s.size();

    int ans=0;
    for(int i=0; i<n; i++){
        int l=0, r=1;
        while(r<n){
            if(s[l+i]==s[r]){
                f[r]=l+1;
                l++; r++;
            } else if(l>0){
                l=f[l-1];
            } else{
                f[l]=0;
                r++;
            }
        }
        for(int i=0; i<n; i++) cout<<f[i]<<" ";
        for(int i=0; i<n; i++) f[i]=0;
        cout<<"\n";
    }
    cout<<ans<<"\n";
}