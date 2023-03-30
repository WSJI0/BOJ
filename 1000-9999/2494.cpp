#include <bits/stdc++.h>
using namespace std;

int n, digit[10001], res[10001];
char a;
int dp[10001][10], ans[10001][10];

int solve(int cur, int d){
    if(dp[cur][d]) return dp[cur][d];
    
    int l=(digit[cur]+d)%10;
    if(cur==n-1){
        int left=(res[cur]-l+10)%10;
        int right=10-left;

        if(min(left, right)!=0){
            if(left>right) ans[cur][d]=-right;
            else ans[cur][d]=left;
        }

        return min(left, right);
    }

    int left=(res[cur]-l+10)%10;
    int right=10-left;
    int v1=solve(cur+1, (d+left)%10)+left; // left
    int v2=solve(cur+1, d)+right; // right
    
    if(v1<v2){
        dp[cur][d]=v1;
        ans[cur][d]=left;
    } else{
        dp[cur][d]=v2;
        ans[cur][d]=-right;
    }

    return dp[cur][d];
}

void print(int cur, int d){
    if(cur==n) return;
    if(ans[cur][d]!=0)
        cout<<cur+1<<" "<<ans[cur][d]<<"\n";
    if(ans[cur][d]>0) print(cur+1, (d+ans[cur][d])%10);
    else print(cur+1, d);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        digit[i]=a-'0';
    }
    for(int i=0; i<n; i++){.
        cin>>a;
        res[i]=a-'0';
    }

    cout<<solve(0, 0)<<"\n";
    print(0, 0);
}