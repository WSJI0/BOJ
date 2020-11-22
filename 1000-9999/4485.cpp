//4485번 녹색 옷 입은 애가 젤다지?

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

pair<int, pair<int, int>> p(int a, int b, int c){
    return make_pair(a, make_pair(b, c));
}

int board[125][125];
int dp[125][125];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, cnt=1;
    while(1){
        cin>>n;
        if(n==0) break;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>board[i][j];
                dp[i][j]=INF;
            }
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push(p(-board[0][0], 0, 0));
        dp[0][0]=0;
        while(!pq.empty()){
            int curX=pq.top().second.first;
            int curY=pq.top().second.second;
            int cos=-pq.top().first;
            pq.pop();
            if(curX>0 && cos+board[curY][curX-1]<dp[curY][curX-1]){
                pq.push(p(-cos-board[curY][curX-1], curX-1, curY));
                dp[curY][curX-1]=cos+board[curY][curX-1];
            }
            if(curX<n-1 && cos+board[curY][curX+1]<dp[curY][curX+1]){
                pq.push(p(-cos-board[curY][curX+1], curX+1, curY));
                dp[curY][curX+1]=cos+board[curY][curX+1];
            }
            if(curY>0 && cos+board[curY-1][curX]<dp[curY-1][curX]){
                pq.push(p(-cos-board[curY-1][curX], curX, curY-1));
                dp[curY-1][curX]=cos+board[curY-1][curX];
            }
            if(curY<n-1 && cos+board[curY+1][curX]<dp[curY+1][curX]){
                pq.push(p(-cos-board[curY+1][curX], curX, curY+1));
                dp[curY+1][curX]=cos+board[curY+1][curX];
            }
        }
        cout<<"Problem "<<cnt++<<": ";
        cout<<dp[n-1][n-1]<<"\n";
    }
}