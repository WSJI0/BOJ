#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]>dp[i][k]+dp[k][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }
}