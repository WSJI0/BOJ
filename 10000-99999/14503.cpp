//14503번 로봇 청소기 (미완성)

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, r, c, d, board[51][51];
    int rotate[4][2]={
        {0, -1}, {-1, 0}, {0, 1}, {1, 0}
    };
    cin>>n>>m>>r>>c>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    int ans=0;
    while(1){
        if(board[r][c]==0){
            board[r][c]=2;
            ans++;
        }
        int my=r+rotate[d][0], mx=c+rotate[d][1];
        int cnt=0;
        while(!(0<=mx && mx<m && 0<=my && my<n)){
            d++; cnt++;
            if(d==4) d=0;
            if(cnt==5) break;
        }
        if(cnt!=5){
            
        } else break;
    }

    cout<<ans<<"\n";
}