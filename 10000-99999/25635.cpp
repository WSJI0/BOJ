#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, a, m;
ll s;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        s+=a; m=max(m, a);
    }

    if(s/2+s%2<m) cout<<(s-m)*2+1<<"\n";
    else cout<<s<<"\n";
}