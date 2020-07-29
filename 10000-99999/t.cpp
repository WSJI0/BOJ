#include <bits/stdc++.h>

using namespace std;

int len(long long int n){
	float fnum;
	int ans=0;
	for(long long int c=1; c>=0; c*=10){
		float fnum=n/c;
		if(fnum<=0) break;
		ans++;
	}
	return ans;
}

long long int a(long long int n){
	while(n>0){
		n-=len(n)+1;
		if(n==10){
			return 10;
		}  
		else if(n==8){
			return 8;
		} 
		else if(n==9){
			return 9;
		}
	}
}
int main(void){
	for(long long int i=1569; i<=1000000000; i*=10){
		cout<<i<<" : "<<a(i)<<"\n";
	}
}
