// 1102번 발전소 (미완성)

#include <bits/stdc++.h>
using namespace std;

int n, dp[17][17];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>dp[i][j];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(dp[i][j]>dp[i][k])
            }
        }
    }
}