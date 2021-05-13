// 2266번 금고 테스트

#include <bits/stdc++.h>
using namespace std;

int n, k, dp[501][501];

int solve(int f, int l){
    if(l==1){
        return (n-f+1);
    }
    return 1+()
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>k;
    cout<<solve((n-1)/2, k)<<"\n";
}