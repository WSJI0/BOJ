#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int

string s;
ll ans, b=1;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>s;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='O') ans=(ans+b)%MOD;
        b=(b*2)%MOD;
    }
    cout<<ans<<"\n";
}