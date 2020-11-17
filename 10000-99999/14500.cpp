//14500번 테트로미노

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    int board[500][500];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>board[i][j];
    }
    int s[5][8][4][2]={
        { //ㅡ
            {{0,0},{1,0},{2,0},{3,0}},
            {{0,0},{1,0},{2,0},{3,0}},
            {{0,0},{0,1},{0,2},{0,3}},
            {{0,0},{0,1},{0,2},{0,3}},
            {{0,0},{1,0},{2,0},{3,0}},
            {{0,0},{1,0},{2,0},{3,0}},
            {{0,0},{0,1},{0,2},{0,3}},
            {{0,0},{0,1},{0,2},{0,3}}
        }, 
        { //ㅁ
            {{0,0},{1,0},{1,1},{0,1}},
            {{0,0},{1,0},{1,1},{0,1}},
            {{0,0},{1,0},{1,1},{0,1}},
            {{0,0},{1,0},{1,1},{0,1}},
            {{0,0},{1,0},{1,1},{0,1}},
            {{0,0},{1,0},{1,1},{0,1}},
            {{0,0},{1,0},{1,1},{0,1}},
            {{0,0},{1,0},{1,1},{0,1}}
        },
        { //ㄴ
            {{0,0},{0,1},{0,2},{1,2}},
            {{1,0},{1,1},{1,2},{0,2}},
            {{0,0},{1,0},{2,0},{0,1}},
            {{0,0},{1,0},{2,0},{2,1}},
            {{0,0},{1,0},{1,1},{1,2}},
            {{0,0},{0,1},{0,2},{1,0}},
            {{2,0},{0,1},{1,1},{2,1}},
            {{0,0},{0,1},{1,1},{2,1}}
        },
        { //ㄱㄴ
            {{0,0},{0,1},{1,1},{1,2}},
            {{1,0},{2,0},{0,1},{1,1}},
            {{0,0},{0,1},{1,1},{1,2}},
            {{1,0},{2,0},{0,1},{1,1}},
            {{1,0},{1,1},{0,1},{0,2}},
            {{0,0},{1,0},{1,1},{2,1}},
            {{1,0},{1,1},{0,1},{0,2}},
            {{0,0},{1,0},{1,1},{2,1}}
        },
        { //ㅜ모양
            {{0,0},{1,0},{2,0},{1,1}},
            {{1,0},{0,1},{1,1},{2,1}},
            {{0,1},{1,0},{1,1},{1,2}},
            {{0,0},{0,1},{0,2},{1,1}},
            {{0,0},{1,0},{2,0},{1,1}},
            {{1,0},{0,1},{1,1},{2,1}},
            {{0,1},{1,0},{1,1},{1,2}},
            {{0,0},{0,1},{0,2},{1,1}}
        }
    };

    int ans=0;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            for(int a=0; a<5; a++){
                for(int b=0; b<8; b++){
                    int res=0;
                    for(int c=0; c<4; c++){
                        int mx=x+s[a][b][c][0];
                        int my=y+s[a][b][c][1];
                        if(0>mx || mx>=m || 0>my || my>=n) res=-99999999;
                        else{
                            if(board[my][mx]==0) res=-99999999;
                            res+=board[my][mx];
                        }
                    }
                    if(res>0) ans=max(ans, res);
                }
            }
        }
    }
    cout<<ans<<"\n";
}