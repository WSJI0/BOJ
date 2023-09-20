#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n, ans;

bool check(double d){
    if(d - (int)d == 0) return true;
    return false;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(ll i=1; i*i<=sqrt(n); i++){
        if(check(sqrt(n - i*i))) ans++;
    }
    /*for(ll i=1; i*i<=1000000000000; i++){
        if(check(sqrt(i*i + n*n))) ans++;
    }*/

    cout<<ans<<"\n";
}