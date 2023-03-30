#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n;
int h[100003];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while(1){
        cin>>n;
        if(n==0) break;
        for(int i=1; i<=n; i++) cin>>h[i];
        h[n+1]=0;

        stack<int> s;
        s.push(0);
        int ans=0;

        for(int i=1; i<=n+1; i++){
            while(!s.empty() && s.top()>h[i]){
                int tmp=s.top(); s.pop();
                ans=max(ans, h[tmp]*(i-s.top()-1));
            } s.push(i);
        }

        cout<<ans<<"\n";
    }
}