//17136번 색종이 붙이기

#include <bits/stdc++.h>
using namespace std;

bool board[10][10];
int lef[5]={5, 5, 5, 5, 5};
int ans=987654321;

bool check(int Y, int X, int s){
    if(Y+s>=10 || X+s>=10) return false;
    for(int y=Y; y<=Y+s; y++){
        for(int x=X; x<=X+s; x++){
            if(!board[y][x]) return false;
        }
    } return true;
}

void attBoard(int Y, int X, int s, bool N){
    for(int y=Y; y<=Y+s; y++){
        for(int x=X; x<=X+s; x++){
            board[y][x]=N;
        }
    }
}

void solve(int cnt){
    if(cnt>=ans) return;
    int att[2]={-1, -1};
    for(int y=0; y<10; y++){
        for(int x=0; x<10; x++){
            if(board[y][x]){
                att[0]=y;
                att[1]=x;
                break;
            }
        }
        if(att[0]!=-1) break;
    }
    if(att[0]==-1){
        ans=min(ans, cnt);
        return;
    }

    for(int s=4; s>=0; s--){
        if(!check(att[0], att[1], s) || lef[s]==0) continue;
        lef[s]--;
        attBoard(att[0], att[1], s, 0);
        solve(cnt+1);
        lef[s]++;
        attBoard(att[0], att[1], s, 1);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>board[i][j];
        }
    }

    solve(0);
    cout<<(ans==987654321? -1:ans)<<"\n";
}