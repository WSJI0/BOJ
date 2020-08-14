#include <bits/stdc++.h>

using namespace std;

int main(void){
	unsigned long long int n, m, N, result=1, mod=1000000007;
	cin>>n>>m;

	for(unsigned long long int i=2; i<=n; i++){
		long long int f=floor(m/i);
		N=((i%mod)*(f%mod))%mod;
		result=((result%mod)*(N%mod))%mod;
		cout<<result<<"\n";9
	}
	cout<<result<<"\n";
};