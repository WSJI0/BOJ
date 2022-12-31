#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll fibo[6000001];
ll n;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    fibo[0]=0;
    fibo[1]=1;

    for(int i=2; i<=6000000; i++){
        fibo[i]=(fibo[i-2]+fibo[i-1])%1000000;
    }

    cin>>n;
    cout<<fibo[n%6000000]<<"\n";
}
