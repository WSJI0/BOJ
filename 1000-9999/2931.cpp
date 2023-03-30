//11657 타임머신

#include <bits/stdc++.h>
using namespace std;

int r, c, cy, cx, my, mx;
char board[26][26];
int startP[2], endP[2], hole[2];
bool visited[26][26];

int block[5][2][2]={
    {{0, 0}, {0, 0}}, 
    {{1, 0}, {0, 1}},
    {{-1, 0}, {0, 1}},
    {{0, -1}, {-1, 0}},
    {{0, -1}, {1, 0}}
};
int pBlock[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
int hBlock[2][2]={
    {-1, 0}, {1, 0}
};
int vBlock[2][2]={
    {0, -1}, {0, 1}
};

void findHole(){
    queue<pair<int, int>> q;
    q.push(make_pair(startP[0], startP[1]));
    visited[startP[0]][startP[1]]=1;

    while(!q.empty()){
        tie(cy, cx)=q.front(); q.pop();
        if(board[cy][cx]=='M'){
            for(int i=0; i<4; i++){
                my=pBlock[i][0]+cy;
                mx=pBlock[i][1]+cx;
                if(0<=my && my<r && 0<=mx && mx<c){
                    if(board[my][mx]=='.') continue; 
                    else{
                        visited[my][mx]=1;
                        q.push(make_pair(my, mx));
                    }
                }
            }
        } else if(board[cy][cx]>='1' && board[cy][cx]<='4'){
            for(int i=0; i<2; i++){
                my=block[board[cy][cx]-'0'][i][0]+cy;
                mx=block[board[cy][cx]-'0'][i][1]+cx;
                if(0<=my && my<r && 0<=mx && mx<c){
                    if(visited[my][mx]==1) continue;
                    if(board[my][mx]=='.'){
                        hole[0]=my; hole[1]=mx;
                        return;
                    } else{
                        visited[my][mx]=1;
                        q.push(make_pair(my, mx));
                    }
                }
            }
        } else if(board[cy][cx]=='+'){
            for(int i=0; i<4; i++){
                my=pBlock[i][0]+cy;
                mx=pBlock[i][1]+cx;
                if(0<=my && my<r && 0<=mx && mx<c){
                    if(visited[my][mx]==1) continue;
                    if(board[my][mx]=='.'){
                        hole[0]=my; hole[1]=mx;
                        return;
                    } else{
                        visited[my][mx]=1;
                        q.push(make_pair(my, mx));
                    }
                }
            }
        } else if(board[cy][cx]=='|' || board[cy][cx]=='-'){
            for(int i=0; i<2; i++){
                if(board[cy][cx]=='|'){
                    my=hBlock[i][0]+cy;
                    mx=hBlock[i][1]+cx;
                } else{
                    my=vBlock[i][0]+cy;
                    mx=vBlock[i][1]+cx;
                }
                if(visited[my][mx]==1) continue;
                if(0<=my && my<r && 0<=mx && mx<c){
                    if(board[my][mx]=='.'){
                        hole[0]=my; hole[1]=mx;
                        return;
                    } else{
                        visited[my][mx]=1;
                        q.push(make_pair(my, mx));
                    }
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>board[i][j];
            if(board[i][j]=='M'){
                startP[0]=i; startP[1]=j;
            } else if(board[i][j]=='Z'){
                endP[0]=i; endP[1]=j;
            }
        }
    }

    findHole();

    bool connect[4]={0, 0, 0, 0};
    for(int i=0; i<4; i++){
        my=pBlock[i][0]+hole[0];
        mx=pBlock[i][1]+hole[1];
        if(0<=my && my<r && 0<=mx && mx<c){
            char b=board[my][mx];
            if(b=='+') connect[i]=1;
            else if(i==0 && (b=='3' || b=='4' || b=='-')){
                connect[i]=1;
            } else if(i==1 && (b=='1' || b=='2' || b=='-')){
                connect[i]=1;
            } else if(i==2 && (b=='2' || b=='3' || b=='|')){
                connect[i]=1;
            } else if(i==3 && (b=='1' || b=='4' || b=='|')){
                connect[i]=1;
            }
        }
    }

    cout<<hole[0]+1<<" "<<hole[1]+1<<" ";
    if(connect[0] && connect[1] && connect[2] && connect[3]){
        cout<<"+"<<"\n";
    } else if(connect[0] && connect[1]){
        cout<<"-"<<"\n";
    } else if(connect[2] && connect[3]){
        cout<<"|"<<"\n";
    } else if(connect[0] && connect[2]){
        cout<<"1"<<"\n";
    } else if(connect[0] && connect[3]){
        cout<<"2"<<"\n";
    } else if(connect[1] && connect[3]){
        cout<<"3"<<"\n";
    } else if(connect[1] && connect[2]){
        cout<<"4"<<"\n";
    }
}