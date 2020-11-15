//1486번 등산

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

pair<int, pair<int, int>> pa(int a, int b, int c){
    return make_pair(a, make_pair(b, c));
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, t, d;
    char c;
    int dp[25][25];
    int dp2[25][25];
    int M[25][25];
    cin>>n>>m>>t>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>c;
            if(c>='A' && c<='Z') M[i][j]=c-'A';
            else M[i][j]=c-'a'+26;
        }
    }

    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++) dp[i][j]=dp2[i][j]=INF;
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(pa(0, 0, 0));
    dp[0][0]=0;
    
    int move[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    while(!pq.empty()){
        pair<int, pair<int, int>> node=pq.top(); pq.pop();
        int nx=node.second.first, ny=node.second.second, nc=-node.first;
        for(auto v:move){
            int mx=nx+v[0], my=ny+v[1];
            if(mx>=0 && mx<m && my>=0 && my<n){

                if(M[my][mx]>M[ny][nx] && M[my][mx]-M[ny][nx]<=t){
                    if(nc+(int)pow(M[my][mx]-M[ny][nx], 2)<dp[my][mx]){
                        pq.push(pa(-(nc+(int)pow(M[my][mx]-M[ny][nx], 2)), mx, my));
                        dp[my][mx]=nc+(int)pow(M[my][mx]-M[ny][nx], 2);
                    }
                }
                else if(M[my][mx]<=M[ny][nx] && M[ny][nx]-M[my][mx]<=t){
                    if(nc+1<dp[my][mx]){
                        pq.push(pa(-(1+nc), mx, my));
                        dp[my][mx]=nc+1;
                    }
                }

            }
        }
    }

    priority_queue<pair<int, pair<int, int>>> pq2;
    pq2.push(pa(0, 0, 0));
    dp2[0][0]=0;
    while(!pq2.empty()){
        pair<int, pair<int, int>> node=pq2.top(); pq2.pop();
        int nx=node.second.first, ny=node.second.second, nc=-node.first;
        for(auto v:move){
            int mx=nx+v[0], my=ny+v[1];
            if(mx>=0 && mx<m && my>=0 && my<n){
                if(M[my][mx]>=M[ny][nx] && M[my][mx]-M[ny][nx]<=t){
                    if(nc+1<dp2[my][mx]){
                        pq2.push(pa(-(1+nc), mx, my));
                        dp2[my][mx]=nc+1;
                    }
                }
                else if(M[my][mx]<M[ny][nx] && M[ny][nx]-M[my][mx]<=t){
                    if(nc+(int)pow(M[ny][nx]-M[my][mx], 2)<dp2[my][mx]){
                        pq2.push(pa(-(nc+(int)pow(M[ny][nx]-M[my][mx], 2)), mx, my));
                        dp2[my][mx]=nc+(int)pow(M[ny][nx]-M[my][mx], 2);
                    }
                }

            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dp[i][j]+dp2[i][j]<=d && ans<M[i][j]) ans=M[i][j];
        }
    }
    cout<<ans<<"\n";
}