//17435번 합성함수와 쿼리

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m, q, n, x;
    int table[500001][19];
    cin>>n;
    for(int i=1; i<=n; i++) cin>>table[i][0];
    for(int i=1; i<19; i++){
        for(int j=1; j<=m; j++){
            table[i][j]=table[table[i][j-1]][j-1];
        }
    }
    

}