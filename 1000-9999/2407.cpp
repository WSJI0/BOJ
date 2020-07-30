//2407¹ø Á¶ÇÕ

#include <bits/stdc++.h>

using namespace std;

int main(void){
	
	long long dp[101][101];
	dp[1][0]=1; dp[1][1]=1;
	for(int i=2; i<=100; i++){
		for(int j=0; j<=i; j++){
			if(j==0||i==j) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];	
		}
	}

	int n, r;
	cin>>n>>r;
	cout<<dp[n][r]<<"\n";
} 
