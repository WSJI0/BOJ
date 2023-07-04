#include <bits/stdc++.h>
using namespace std;

int n, m, board[501][501];
int ans;
int mv[4][2]={
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
bool vis[15][15];
pair<int, int> arr[6];
pair<int, int> arr2[6];
unordered_map<string, bool> chk;

void solve(int cur, int y, int x, int u, int l){
    if(cur==6){
        string c="";

        for(int i=0; i<6; i++) arr2[i]=arr[i];
        sort(arr2, arr2+6);

        for(int i=0; i<6; i++){
            int tmp=(arr2[i].first-u)*6+(arr2[i].second-l);
            if(tmp<10) c+="0";
            c+=to_string(tmp);
        } 
        if(chk.find(c)!=chk.end()) return;
        chk.insert({c, 1});

        for(int yy=0; yy<n; yy++){
            for(int xx=0; xx<m; xx++){
                int ret=0, ok=1;
                for(int i=0; i<6; i++){
                    int cy=yy+arr[i].first-u, cx=xx+arr[i].second-l;
                    if(0<=cy && cy<n && 0<=cx && cx<m){
                        ret+=board[cy][cx];
                    } else{
                        ok=false; break;
                    }
                } if(ok) ans=max(ans, ret);
            }
        }
        return;
    }

    for(auto vv:mv){
        int my=y+vv[0]; int mx=x+vv[1];
        if(vis[my][mx]) continue;
        vis[my][mx]=1; arr[cur]={my, mx};
        solve(cur+1, my, mx, min(u, my), min(l, mx));
        solve(cur+1, y, x, min(u, my), min(l, mx));
        vis[my][mx]=0;
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>board[i][j];
    }

    vis[7][7]=1;
    arr[0]={7, 7};
    solve(1, 7, 7, 7, 7);

    cout<<ans<<"\n";
}