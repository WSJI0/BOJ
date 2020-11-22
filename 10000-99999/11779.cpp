//11779번 최소비용 구하기 2

#include <bits/stdc++.h>
using namespace std;

int cost[1001][1001];
int dp[1001][1001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b, c;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        cost[a][b]=c;
    }
    

}