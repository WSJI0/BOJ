#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, num;
    cin>>t;
    while(t--){
        priority_queue<int> pq;
        vector<int> a;
        cin>>n;
        cout<<n/2+1<<"\n";
        for(int i=0; i<n; i++){
            cin>>num;
            pq.push(num);
            if(i%2==0){
                for(int j=0; j<i/2; j++){
                    a.push_back(pq.top());
                    pq.pop();
                }
                cout<<pq.top()<<" ";
                for(int j=0; j<i/2; j++){
                    pq.push(a.back());
                    a.pop_back();
                }
            }
        }
        cout<<"\n";
    }
}