#include <bits/stdc++.h>

using namespace std;

int main(void){
	long long int n, r, mod=1000000007;
	cin>>n>>r;
	long long int dp[n+1];
	dp[0]=1;
	for(int i=1; i<=n; i++){
		dp[i]=(dp[i-1]*(i%mod))%mod;
	}
	for(int i=1; i<=n; i++){
		cout<<i<<" "<<dp[i]<<"\n";
	}
	cout<<dp[n]/((dp[r]*dp[n-r])%mod)<<"\n";
}
