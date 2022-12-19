/*
3055번
탈출
*/

#include <bits/stdc++.h>
using namespace std;

int r, c, sy, sx, mv[4][2]={
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
char board[51][51];
queue<pair<int, int>> q;
int dp[51][51];
bool visited[51][51];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>board[i][j];
            if(board[i][j]=='*'){
                q.push(make_pair(i, j));
                dp[i][j]=0;
            } else if(board[i][j]=='S'){ sy=i; sx=j; }
        }
    }

    int cur=0;
    while(!q.empty()){
        cur++; int qs=q.size();
        for(int i=0; i<qs; i++){
            pair<int, int> node=q.front(); q.pop();
            for(int j=0; j<4; j++){
                int my=mv[j][0]+node.first, mx=mv[j][1]+node.second;
                if(0<=my && my<r && 0<=mx && mx<c){
                    if(dp[my][mx]!=-1 || board[my][mx]=='D' || board[my][mx]=='X') continue;
                    q.push(make_pair(my, mx));
                    dp[my][mx]=cur;
                }
            }
        }
    }

    q.push(make_pair(sy, sx)); cur=0;
    while(!q.empty()){
        cur++; int qs=q.size();
        for(int i=0; i<qs; i++){
            pair<int, int> node=q.front(); q.pop();
            for(int j=0; j<4; j++){
                int my=mv[j][0]+node.first, mx=mv[j][1]+node.second;
                if(0<=my && my<r && 0<=mx && mx<c){
                    if((dp[my][mx]<=cur && dp[my][mx]!=-1) || board[my][mx]=='X') continue;
                    if(board[my][mx]=='D'){
                        cout<<cur<<"\n";
                        exit(0);
                    }
                    q.push(make_pair(my, mx));
                    dp[my][mx]=cur;
                }
            }
        }
    }

    cout<<"KAKTUS"<<"\n";
}
