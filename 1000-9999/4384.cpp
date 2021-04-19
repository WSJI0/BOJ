// 4384번 공평하게 팀 나누기

#include <bits/stdc++.h>
using namespace std;

int n, k[101], ans[2], res=987654321;

void solve(int cur, int aVal, int bVal, int aCnt, int bCnt){
    if(cur==n){
        if(abs(aCnt-bCnt)<=1 && res>abs(aVal-bVal)){
            res=abs(aVal-bVal);
            ans[0]=min(aVal, bVal);
            ans[1]=max(aVal, bVal);
        }
        return;
    }
    solve(cur+1, aVal+k[cur], bVal, aCnt+1, bCnt);
    solve(cur+1, aVal, bVal+k[cur], aCnt, bCnt+1);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>k[i];

    solve(0, 0, 0, 0, 0);

    cout<<ans[0]<<" "<<ans[1]<<"\n";
}