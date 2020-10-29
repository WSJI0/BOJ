#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        long long int c;
        priority_queue<long long int> pq;
        for(int i=0; i<n; i++){
            cin>>c;
            pq.push(-c);
        }
        
        long long int ans=1;
        while(pq.size()>1){
            long long int fir=pq.top(); pq.pop();
            long long int sec=pq.top(); pq.pop();
            ans=(ans%mod)*((fir*sec)%mod);
            pq.push(-(fir*sec));
        }
        cout<<ans%mod<<"\n";
    }
}