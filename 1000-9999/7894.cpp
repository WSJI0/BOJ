//7894번 큰 수

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, m;
    cin>>t;
    while(t--){
        cin>>m;
        double ans=0;
        for(int i=1; i<=m; i++){
            ans+=log10(i);
        }
        cout<<(int)(ans+1)<<"\n";
    }+
}