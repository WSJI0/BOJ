//1081번 합

#include <bits/stdc++.h>
using namespace std;

int digit(int n){
    int res=0;
    while(n>0){
        res++;
        n/=10;
    }
    return res;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int l, u, d;
    long long int ans=0;
    cin>>l>>u;
    d=digit(u);
    for(int i=0; i<d; i++){
        for(int j=1; j<=u%10; j++){
            ans+=j*pow(10, i);
        }
        if(u==l) break;
    }
    cout<<ans<<"\n";
}