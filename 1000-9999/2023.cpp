//2023 신기한 소수

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n==2) return true;
    if(n==1 || n%2==0) return false;
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0) return false;
    } return true;
}

int ans=0, n;
int number=0;

void make(int d){
    if(d==n){
        cout<<number<<"\n";
        return;
    }
    for(int i=0; i<10; i++){
        if(d==0 && i==0) continue;
        number*=10; number+=i;
        if(isPrime(number)) make(d+1);
        number/=10;
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    make(0);
}