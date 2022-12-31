#include <bits/stdc++.h>
using namespace std;

int r, c, n, h, cy, cx;
char board[105][101];
bool visited[105][101];
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void updateBoard();
void printBoard(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cout<<board[i][j];
        cout<<"\n";
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cin>>board[i][j];
    }
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>h;
        if(i%2==0){
            for(int j=0; j<c; j++){
                if(board[r-h][j]=='x'){
                    board[r-h][j]='.';
                    break;
                }
            }
        } else{
            for(int j=c-1; j>=0; j--){
                if(board[r-h][j]=='x'){
                    board[r-h][j]='.';
                    break;
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        updateBoard();
    }

   printBoard();
}

void dfs(int y, int x){
    for(int i=0; i<4; i++){
        int my=mv[i][0]+y;
        int mx=mv[i][1]+x;
        if(0<=my && my<r && 0<=mx && mx<c){
            if(visited[my][mx] || board[my][mx]=='.') continue;
            visited[my][mx]=1;
            dfs(my, mx);
        }
    }
}

void updateBoard(){
    for(int i=0; i<c; i++){
        if(visited[r-1][i] || board[r-1][i]=='.') continue;
        visited[r-1][i]=1;
        dfs(r-1, i); 
    }

    vector<pair<int, int>> cluster;
    int bottom=-1;
    for(int i=r-1; i>=0; i--){
        for(int j=0; j<c; j++){
            if(board[i][j]=='x' && visited[i][j]==0){
                if(bottom==-1) bottom=i;
                cluster.push_back(make_pair(i, j));
            }
        }
    }

    int down=100;
    for(int i=0; i<cluster.size(); i++){
        tie(cy, cx)=cluster[i];
        for(int j=cy+1; j<=r; j++){
            if(j==r){
                down=min(down, j-cy-1);
                break;
            }
            if(visited[j][cx] && board[j][cx]=='x'){
                down=min(down, j-cy-1);
                break;
            }
        }
    }

    for(int i=0; i<cluster.size(); i++){
        tie(cy, cx)=cluster[i];
        board[cy][cx]='.';
        board[cy+down][cx]='x';
    }
}