#include <bits/stdc++.h>
using namespace std;
#define INF 1234567890

int n, m, ny, nx;
char b;
int board[1001][1001];
int btime[1001][1001];
queue<pair<int, int>> q;
int by, bx;
int mv[4][2]={
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            btime[i][j]=board[i][j]=INF;
            cin>>b;
            if(b=='A'){
                q.push({i, j}); board[i][j]=0;
            }
            else if(b=='B'){ 
                by=i; bx=j;
            }
            else if(b=='G') board[i][j]=-1;
        }
    }

    int cur=0;
    while(btime[by][bx]==INF){
        btime[by][bx]=cur++;
        if(by==1 && bx!=m) bx++;
        else if(by==n && bx!=1) bx--;
        else if(bx==1 && by!=1) by--;
        else if(bx==m && by!=n) by++;
    }

    cur=1; int ans=INF;
    while(!q.empty()){
        int qs=q.size();
        for(int i=0; i<qs; i++){
            tie(ny, nx)=q.front(); q.pop();
            for(auto v:mv){
                int my=v[0]+ny, mx=v[1]+nx;
                if(1<=my && my<=n && 1<=mx && mx<=m){
                    if(board[my][mx]==INF){
                        // if(my!=1 && my!=n && mx!=1 && mx!=m)
                            q.push({my, mx});
                        board[my][mx]=cur;
                    }
                    if(my==1 || mx==1 || my==n || mx==m){
                        if(btime[my][mx]%2==cur%2){
                            int tmp=btime[my][mx];
                            while(tmp<cur) tmp+=(2*n)+(2*(m-2));
                            ans=min(ans, tmp);
                        }
                    }
                }
            }
        } cur++;
    }

    cout<<(ans==INF? -1:ans)<<"\n";
}