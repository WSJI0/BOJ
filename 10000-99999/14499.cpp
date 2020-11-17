//14499번 주사위 굴리기

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, x, y, k, c, mx, my, top=1, east=3;
    int dice[7]={0, 0, 0, 0, 0, 0, 0};
    cin>>n>>m>>y>>x>>k;
    int board[20][20];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    int move[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
    int roll[6][6][4]={
        {{0,0,0,0}, {5,2,3,4}, {4,3,5,2}, {3,4,2,5}, {2,5,4,3}, {0,0,0,0}},
        {{6,1,4,3}, {0,0,0,0}, {4,3,1,6}, {3,4,6,1}, {0,0,0,0}, {1,6,3,4}},
        {{6,1,2,5}, {5,2,6,1}, {0,0,0,0}, {0,0,0,0}, {2,5,1,6}, {1,6,5,2}},
        {{6,1,5,2}, {5,2,1,6}, {0,0,0,0}, {0,0,0,0}, {2,5,6,1}, {1,6,2,5}},
        {{6,1,3,4}, {0,0,0,0}, {4,3,6,1}, {3,4,1,6}, {0,0,0,0}, {1,6,4,3}},
        {{0,0,0,0}, {5,2,4,3}, {4,3,2,5}, {3,4,5,2}, {2,5,3,4}, {0,0,0,0}},
    };
    int bottom[7]={0, 6, 5, 4, 3, 2, 1};
    for(int i=0; i<k; i++){
        cin>>c; c--;
        my=move[c][0]+y;
        mx=move[c][1]+x;
        if(0<=mx && mx<m && 0<=my && my<n){
            int tmp=roll[top-1][east-1][c];
            if(c==0) east=top;
            else if(c==1) east=bottom[top];
            top=tmp;
            if(board[my][mx]==0){
                board[my][mx]=dice[bottom[top]];
            }else{
                dice[bottom[top]]=board[my][mx];
                board[my][mx]=0;
            }
            cout<<dice[top]<<"\n";
            x=mx; y=my;
        }
    }
}