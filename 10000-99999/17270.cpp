//17270번 연예인은 힘들어

#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int dp[101][101];
int road[101][101];
int canAns[101];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int v, m, a, b, c, A, B;
    cin>>v>>m;
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            dp[i][j]=INF;
        }
    }
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        dp[a][b]=dp[b][a]=min(dp[a][b], c);
        road[a][b]=road[b][a]=1;
    }
    cin>>A>>B;

    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                if(dp[i][j]>dp[i][k]+dp[k][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }

    int res1=INF, res2=INF, ans=INF;
    for(int i=1; i<=v; i++){
        if(i==A || i==B) continue;
        if(res1>dp[A][i]+dp[B][i]){
            res1=dp[A][i]+dp[B][i];
        }
    }
    for(int i=1; i<=v; i++){
        if(i==A || i==B) continue;
        if(dp[A][i]+dp[B][i]==res1 && dp[A][i]<=dp[B][i] && res2>dp[A][i])
            res2=dp[A][i];
    }
    for(int i=1; i<=v; i++){
        if(i==A || i==B) continue;
        if(dp[A][i]+dp[B][i]==res1 && dp[A][i]==res2)
            canAns[i]=1;
    }
    for(int i=1; i<=v; i++){
        if(i==A || i==B) continue;
        if(canAns[i]){
            ans=i;
            break;
        }
    }

    cout<<(ans!=INF? ans:-1)<<"\n";
}