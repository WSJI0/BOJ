#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, num;
    cin>>n;
    priority_queue<int> pq;
    for(int i=0; i<n*n; i++){
        cin>>num;
        pq.push(-num);
        if(pq.size()>n) pq.pop();
    } 
    cout<<-pq.top()<<"\n";
}