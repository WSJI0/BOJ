#include <bits/stdc++.h>
using namespace std;

int b[1048576];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while(cin>>n){
        if(!(b[n/32]&(1<<(n%32)))){
            cout<<n<<" ";
            b[n/32]|=(1<<(n%32));
        }
    }
    cout<<"\n";
}