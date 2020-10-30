//9663 N-Queen

#include <bits/stdc++.h>
using namespace std;

int ans=0, n;
bool board[14][14];

void nQueen(int l){
    if(l==n){
        ans++;
        return;
    }
    for(int x=0; x<n; x++){
        bool ok=true;
        if(l!=0 && board[l-1][x]) continue;
        for(int y=0; y<l; y++){
            if(board[y][x]){
                ok=false; break;
            }
            else if(x-(l-y)>=0 && board[y][x-(l-y)]){
                ok=false; break;
            }
            else if(x+(l-y)<n && board[y][x+(l-y)]){
                ok=false; break;
            }
        }
        if(ok){
            board[l][x]=true;
            nQueen(l+1);
            board[l][x]=false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) board[i][j]=false;
    }
    nQueen(0);
    cout<<ans<<"\n";
}