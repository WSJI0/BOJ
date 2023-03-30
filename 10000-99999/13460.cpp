#include <bits/stdc++.h>
using namespace std;

int n, m, ry, rx, by, bx, hy, hx;
char board[11][11], c;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>c;
            if(c=='R'){
                ry=i;
                rx=j;
            } else if(c=='B'){
                by=i;
                bx=j;
            } else if(c=='O'){
                hy=i;
                hx=j;
            }
        }
    }

}