// 6988번 타일 밟기

#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

long long n, tile[3001], a;
bool dp[3001][3001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        tile[i]=a+INF;
    }

    long long ans=0;
    for(int i=n-1; i>=0; i--){
        for(int j=1; j<=n; j++){
            long res=0, cur=tile[i];
            if(dp[i][j]) break;
            for(int k=i; k>=0; k--){
                if(cur>tile[k]) break;
                else if(cur==tile[k]){
                    dp[k][j]=1;
                    res+=cur;
                    cur-=j;
                }
            }
            if(res%INF>ans%INF) ans=res;
        }
    }

    cout<<(ans>3*INF? ans%INF:0)<<"\n";
}