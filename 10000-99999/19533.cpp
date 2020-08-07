#include <bits/stdc++.h>

using namespace std;

int negMod(int a, int b){
	if(a<0) return a%b+b;
	return a%b;
}

int modPow(long long int a, long long int n, long long int l){
	if(n==0) return 1;
	long long int res=modPow(a*a%l, n/2, l);
	if(n&1) res=res*a%l;
	return res;
}

int len(long long int n){
	double dnum;
	int ans=0;
	for(long long int c=1; c>=0; c*=10){
		dnum=n/c;
		if(dnum<=0) break;
		ans++;
	}
	return ans;
}

int main(void){
	
	string ans[22]={"1", "-2", "1-3", "-2-4", "1-3-5", "-2-4-6", "1-3-5-7", "-2-4-6-8", "1-3-5-7-9", "1-3-5-7-10", "-2-4-6-8-11", "1-3-5-7-9-12", "1-3-5-7-10-13", "-2-4-6-8-11-14", "1-3-5-7-9-12-15", "1-3-5-7-10-13-16", "-2-4-6-8-11-14-17", "1-3-5-7-9-12-15-18", "1-3-5-7-10-13-16-19", "-2-4-6-8-11-14-17-20", "1-3-5-7-9-12-15-18-21"};
	string ans2[3]={"1-3-5-7-9-12-15-1...", "1-3-5-7-10-13-16-...", "-2-4-6-8-11-14-17..."};
	
	vector<int> dp;
	dp.push_back(0);dp.push_back(0);dp.push_back(0);dp.push_back(1);
	for(int i=4; i<1000015; i++){
		int now=i; 
		int pre=dp[i-1];
    	dp.push_back(now-negMod((modPow(10,now-1,now)-modPow(10,now-2,now)-pre%now),now)+1);
	}

	int t;
	long long int a, b;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		cin>>a>>b;
		if((0<a&&a<22&&b==0)||(0<a&&a<3&&b==1)){
			int idx=a*pow(10, b);
			cout<<ans[idx-1]<<"\n";
			continue;
		}
		int l=len(a)+b+1;
		long long int A=a;
		int B=10;
		while(b>0){
			if(b&1) A=A*B%l;
			B=B*B%l;
			b=b>>1;
		}
		A=A%l;
		
		if(l==3){
			int idx=a*pow(10, b); 
			cout<<ans2[idx%3]<<"\n";
		}
		else{
			int s=dp[l-1];
			int start=negMod((modPow(10, l-2, l)+s),l);
			if(A%l==start) cout<<ans2[1]<<"\n";
			else if(A%l==(start+1)%l) cout<<ans2[2]<<"\n";
			else cout<<ans2[0]<<"\n";
		}
	}
}