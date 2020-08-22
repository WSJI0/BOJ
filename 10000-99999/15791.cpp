#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007

void print(vector<int> &a){
    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int ncr[1000001][1001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    vector<vector<int>> ncr;
    vector<int> ncr2(n+1);
    cin>>n>>m;
    print(ncr2);
    for(int i=0; i<m; i++){
        ncr.push_back(ncr2);
        for(int j=1; j<=i; j++)
            ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
    }
    cout<<ncr[n][m]<<"\n";
}