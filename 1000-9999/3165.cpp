// 3165번 5

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, ans=999999999999999, leng;

ll num(vector<int>& v, int len){
    ll res=0;
    for(int i=0; i<len; i++)
        res=res*10+v[i];
    return res;
}

vector<int> cur;
void solve(int len){
    ll N=num(cur, len);
    if(N>n){
        ans=min(ans, N);
        return;
    }
    if(len>=leng) return;
    for(int i=0; i<=len; i++){
        for(int j=0; j<=9; j++){
            int tmp=cur[i];
            cur[i]=j;
            solve(len+1);
            cur[i]=tmp;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>k;

    for(int i=1; i<15; i++){
        leng=i;
        ll tmp=1;
        for(int j=0; j<i; j++) tmp*=10;
        if(n/tmp==0) break;
    }

    cur.resize(15, 5);
    solve(k);
    cout<<ans<<"\n";
}