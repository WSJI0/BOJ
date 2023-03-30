// 1019번 책 페이지

#include <bits/stdc++.h>
using namespace std;

string n;
int ans[10];

int ppow(int num, int k){
    int ret=1;
    for(int i=0; i<k; i++) ret*=num;
    return ret;
}

int change(int e){
    if(e==-1) return 0;
    int cur=1, ret=0;
    for(int i=e; i>=0; i--){
        ret+=(n[i]-'0')*cur;
        cur*=10;
    }
    return ret;
}

int main(void){ 
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;

    int ns=n.size();
    for(int i=ns-1; i>=0; i--){
        for(int j=0; j<=(n[i]-'0'); j++){
            if(i==0 && j==0) continue;
            else if(j==0)
                ans[j]+=change(i-1)*ppow(10, ns-i-1);
            else ans[j]+=(change(i-1)+1)*ppow(10, ns-i-1);
        }
        for(int j=(n[i]-'0')+1; j<=9; j++){
            ans[j]+=change(i-1)*ppow(10, ns-i-1);
        }
    }

    for(int i=0; i<=9; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}


1234567

0, 1, 2

x1xxxxx
9*10^5 - (8*10^5) - 