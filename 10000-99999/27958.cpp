#include <bits/stdc++.h>
using namespace std;

int n, k, ans=0;
int board[10][10], ss[10][10], at[7];
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
vector<int> cc;

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]>=10){
                cout<<" "<<board[i][j];
            } else{
                cout<<"  "<<board[i][j];
            }
        } cout<<"\n";
    } cout<<"\n";
}

void solve(int cur, int score){
    if(cur==k){
        ans=max(ans, score);
        return;
    }
    for(int i=0; i<n; i++){
        int j, add=0;
        for(j=0; j<n; j++){
            if(board[i][j]!=0) break;
        }
        vector<pair<int, int>> nt;
        int tmp=board[i][j], tmp2=ss[i][j];
        if(board[i][j]>=10 || board[i][j]<=at[cur+1]){
            add=ss[i][j];
            if(board[i][j]<10 && board[i][j]>=4){
                for(auto v:mv){
                    int my=i+v[0], mx=j+v[1];
                    if(0<=my && my<n && 0<=mx && mx<n){
                        if(board[my][mx]==0) nt.push_back({my, mx});
                    }
                } 
            } board[i][j]=ss[i][j]=0;
        }

        int ns=nt.size();
        for(int k=0; k<ns; k++){
            board[nt[k].first][nt[k].second]=tmp/4;
            ss[nt[k].first][nt[k].second]=tmp/4;
        }  board[i][j]=max(0, board[i][j]-at[cur+1]);
        cc.push_back(i);

        solve(cur+1, score+add);

        cc.pop_back();
        for(int k=0; k<ns; k++){
            board[nt[k].first][nt[k].second]=0;
            ss[nt[k].first][nt[k].second]=0;
        }  board[i][j]=tmp; ss[i][j]=tmp2; 
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
            ss[i][j]=board[i][j];
        }
    }
    for(int i=1; i<=k; i++) cin>>at[i];

    solve(0, 0);
    cout<<ans<<"\n";
}