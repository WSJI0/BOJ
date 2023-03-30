#include <bits/stdc++.h>
using namespace std;

int m, q, n, x;
int table[500001][25];

int solve(int n, int x){
    if(n==0) return x;
    for(int i=24; i>=0; i--){
        if((1<<i)<=n){
            return solve(n-(1<<i), table[x][i]);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>m;
    for(int i=1; i<=m; i++) cin>>table[i][0];

    for(int i=1; i<25; i++){
        for(int j=1; j<=m; j++){
            table[j][i]=table[table[j][i-1]][i-1];
        }
    }

    cin>>q;
    while(q--){
        cin>>n>>x;
        cout<<solve(n, x)<<"\n";
    }
}