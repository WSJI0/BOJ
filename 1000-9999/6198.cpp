#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin>>h[i];

    stack<int> s;
    long long int ans=0;
    for(int i=0; i<n; i++){
        if(s.empty()) s.push(h[i]);
        else{
            while(!s.empty() && h[i]>=s.top()) s.pop();
            ans+=s.size();
            s.push(h[i]);
        }
    }
    cout<<ans<<"\n";
}