#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n;
struct{ int r, c; } matrix[501];
struct ret{
    ll r, c, v;
};
ret dp[501][501];

ret solve(int L, int R){
    if(L==R) return {matrix[L].r, matrix[R].c, 0};
    if(L+1==R) 
        return {matrix[L].r, matrix[R].c, matrix[L].r*matrix[L].c*matrix[R].c};
    if(dp[L][R].v) return dp[L][R];

    dp[L][R].v=LLONG_MAX;
    for(int i=L; i<R; i++){
        ret tmp_l=solve(L, i);
        ret tmp_r=solve(i+1, R);
        ll res=tmp_l.r*tmp_l.c*tmp_r.c;
        if(dp[L][R].v>tmp_l.v+tmp_r.v+res){
            dp[L][R].v=tmp_l.v+tmp_r.v+res;
            dp[L][R].r=tmp_l.r;
            dp[L][R].c=tmp_r.c;
        }
    } 
    return dp[L][R];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>matrix[i].r>>matrix[i].c;

    cout<<solve(0, n-1).v<<"\n";
}