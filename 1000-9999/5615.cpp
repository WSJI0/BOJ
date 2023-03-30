#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull n, a, ans;

ull mod_pow(ull a, ull n, ull l){
    if(n==0) return 1;
    ull res=mod_pow(a*a%l, n/2, l);
    if(n&1) res=((res%l)*(a%l))%l;
    return res;
}

bool mr(ull n, ull a){
    if(a%n==0) return true;
    ull d=n-1;
    while(1){
        ull tmp=mod_pow(a, d, n);
        if(tmp==n-1) return true;
        if(d%2) return (tmp==1 || tmp==n-1);
        d/=2;
    }
}

bool is_prime(ull n){
    ull base[3]={2, 7, 61};
    for(int i=0; i<3; i++){
        if(!mr(n, base[i])) return false;
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    while(n--){
        cin>>a;
        if(is_prime(a*2+1)) ans++;
    }
    cout<<ans<<"\n";
}