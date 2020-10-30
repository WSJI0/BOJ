//1655 가운데를 말해요

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, num;
    priority_queue<int> maxP;
    priority_queue<int> minP;
    vector<int> a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        if(maxP.size()>minP.size()) minP.push(-num);
        else maxP.push(num);
        if((!minP.empty() && !maxP.empty()) && maxP.top()>-minP.top()){
            int fir=maxP.top(); maxP.pop();
            int sec=minP.top(); minP.pop();
            maxP.push(-sec); minP.push(-fir);
        }
        cout<<maxP.top()<<"\n";
    }
}