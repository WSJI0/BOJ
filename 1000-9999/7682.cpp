#include <bits/stdc++.h>
using namespace std;

char board[4][4];

bool solve(){
    int x_cnt=0, o_cnt=0, x_line=0, y_line=0, line_o=0, line_x=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]=='X') x_cnt++;
            else if(board[i][j]=='O') o_cnt++;
        }
    }

    for(int i=0; i<3; i++){
        if(board[i][0]!='.' && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            y_line++;
            if(board[i][0]=='O') line_o++;
            else if(board[i][0]=='X') line_x++;
        }
        if(board[0][i]!='.' && board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            x_line++;
            if(board[0][i]=='O') line_o++;
            else if(board[0][i]=='X') line_x++;
        }
    }
    if(x_line>=2 || y_line>=2) return false;

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        if(board[0][0]=='O') line_o++;
        else if(board[0][0]=='X') line_x++;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        if(board[0][2]=='O') line_o++;
        else if(board[0][2]=='X') line_x++;
    }

    if(!(line_o==0 || line_x==0) && line_o>=line_x) return false;
    if(line_o==1 && x_cnt!=o_cnt) return false;
    if(line_o==0 && line_x==0 && x_cnt+o_cnt!=9) return false;
    if(x_cnt+o_cnt==9 && x_cnt!=5) return false;
    if(x_cnt-o_cnt>=2 || o_cnt>x_cnt) return false;
    if(line_x>=1 && x_cnt<=o_cnt) return false;

    return true;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while(1){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cin>>board[i][j];
                if(board[i][j]=='e') return 0;
            }
        }

        cout<<(solve()? "valid":"invalid")<<"\n";
    }
}