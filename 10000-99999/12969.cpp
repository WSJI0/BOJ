#include <bits/stdc++.h>
using namespace std;

int n, k;
bool dp[31][31][31][31][500];
vector<char> ans;

void solve(int cur, int a, int b, int c, int k){
    if(cur==n-1){
        if(k==0){
            for(auto c:ans) cout<<c;
            cout<<"\n";
            exit(0);
        } return;
    }
    if(dp[cur][a][b][c][k]) return;

    ans.push_back('A');
    solve(cur+1, a+1, b, c, k);
    ans.pop_back(); ans.push_back('B');
    solve(cur+1, a, b+1, c, k-(a));
    ans.pop_back(); ans.push_back('C');
    solve(cur+1, a, b, c+1, k-(a+b));
    ans.pop_back();

    dp[cur][a][b][c][k]=1;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>k;
    
    ans.push_back('A');
    solve(0, 1, 0, 0, k);
    ans.pop_back(); ans.push_back('B');
    solve(0, 0, 1, 0, k);
    ans.pop_back(); ans.push_back('C');
    solve(0, 0, 0, 1, k);
    cout<<"-1"<<"\n";
}