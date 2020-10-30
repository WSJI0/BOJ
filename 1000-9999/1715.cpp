// 1715 카드 정렬하기

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, card;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin>>n;
    while(n--){
        cin>>card;
        pq.push(card);
    }
    int ans=0;
    while(pq.size()>1){
        int fir=pq.top(); pq.pop();
        int sec=pq.top(); pq.pop();
        ans+=(fir+sec);
        pq.push(fir+sec);
    }
    cout<<ans<<"\n";
}