#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, s, a;
ll ans[8000001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>a;
        if(a>0){
            for(int j=8000000; j>=a; j--) ans[j]+=ans[j-a];
        } else{
            for(int j=0; j-a<=8000000; j++) ans[j]+=ans[j-a];
        } ans[a+4000000]++;
    }
    cout<<ans[s+4000000]<<"\n";
}
