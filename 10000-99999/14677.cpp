//14677번 병약한 윤호

#include <bits/stdc++.h>
using namespace std;

int dp[501][3], n;
char drug[501];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<3*n; i++){
        cin>>drug[i];
        if(drug[i]=='B') dp[i][0]=1;
        else if(drug[i]=='L') dp[i][1]=1;
        else dp[i][2]=1;
    }

    for(int i=1; i<3*n; i++){
        if(i%3==0){
            dp[i][0]=dp[i-1][j];
        }
        else if(i%3==1){

        }
        else{

        }
    }

}