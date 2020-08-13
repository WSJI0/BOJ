#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n%2==0) return false;
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0) return false;
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> prime(1000001);
    prime[2]=1;
    for(int i=3; i<=1000000; i+=2){
        if(isPrime(i)) prime[i]=1;
        else prime[i]=0;
    }
    while(1){
        int l, u, x=0, y=0;
        cin>>l>>u;
        if(l==-1&&u==-1) break;
        for(int i=l; i<=u; i++){
            if(prime[i]){
                x++;
                if((i-1)%4==0) y++;
            }
        }
        cout<<l<<" "<<u<<" "<<x<<" "<<y<<"\n";
    }
}