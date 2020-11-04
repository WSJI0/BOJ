//2616 소형기관차

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin>>n;
    vector<int> train(n);
    for(int i=0; i<n; i++) cin>>train[i];
    cin>>k;

    vector<int> pSum(n, train[0]);
    for(int i=1; i<n; i++){
        pSum[i]=pSum[i-1]+train[i];
    }

    int dp[3][50001];
    for(int t=0; t<3; t++){
        for(int i=0; i<n; i++){
            dp[t][i]=max(dp[t][i-1]);
        }
    }
}