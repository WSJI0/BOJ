// 1020번 디지털 카운터

#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
int change[10][10], dp[16][16][16], n;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<=9; i++){
        for(int j=0; j<=9; j++){
            change[i][j]=cnt[j]-cnt[i];
        }
    }

    cin>>s;
    n=s.size();
    for(int i=0; i<n; i++) cur[i]=s[i]-'0';

    
}