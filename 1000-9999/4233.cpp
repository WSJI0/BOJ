// 4233번 가짜소수

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll p, a;

bool isPrime(ll n){
    if(n==1) return false;
    else if(n!=2 && n%2==0) return false;
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0) return false;
    }
    return true;
}

ll mpow(ll a, ll n, ll m){
    ll res=1;
    while(n){
        if(n&1) res=a*res%m;
        a=a*a%m;
        n/=2;
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while(1){
        cin>>p>>a;
        if(p==0 && a==0) break;
        if(isPrime(p)){
            cout<<"no"<<"\n";
            continue;
        }
        if(mpow(a, p, p)==a) cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
    }
}