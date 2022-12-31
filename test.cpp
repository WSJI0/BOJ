#include <bits/stdc++.h>
using namespace std;

int n, num;
priority_queue<int> maxQ;
priority_queue<int> minQ;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        if(minQ.size()<maxQ.size()) minQ.push(-num);
        else maxQ.push(num);
        if(!minQ.empty() && !maxQ.empty()){
            if(-minQ.top()<maxQ.top()){
                int tmp=-maxQ.top(); maxQ.pop();
                int tmp2=-minQ.top(); minQ.pop();
                minQ.push(tmp); maxQ.push(tmp2);
            } 
        } cout<<maxQ.top()<<"\n";
    }
}