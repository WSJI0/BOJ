#include <bits/stdc++.h>
using namespace std;

int prime[5000001], n, a, d=0, g=0;
bool check[5000001];
priority_queue<int> pq1;
priority_queue<int> pq2;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    prime[0]=prime[1]=1;
    for(int i=2; i<=5000000; i++){
        if(prime[i]) continue;
        for(int j=i+i; j<=5000000; j+=i) prime[j]=1;
    }

    cin>>n;
    for(int i=0; i<n*2; i++){
        cin>>a;
        if(prime[a]){
            int score;
            if(i%2==0)
                if(pq2.size()<3) score=1000;
                else{
                    int tmp1=pq2.top(); pq2.pop();
                    int tmp2=pq2.top(); pq2.pop();
                    score=pq2.top();
                    pq2.push(tmp1); pq2.push(tmp2);
                }
            else
                if(pq1.size()<3) score=1000;
                else{
                    int tmp1=pq1.top(); pq1.pop();
                    int tmp2=pq1.top(); pq1.pop();
                    score=pq1.top();
                    pq1.push(tmp1); pq1.push(tmp2);
                }
            if(i%2==0) g+=score;
            else d+=score;
        } else if(!prime[a] && check[a]){
            if(i%2==0) d-=1000;
            else g-=1000;
        } else{
            if(i%2==0){
                pq1.push(a);
                if(pq1.size()>3) pq1.pop();
            } else{
                pq2.push(a);
                if(pq2.size()>3) pq2.pop();
            }
            check[a]=1;
        }
    }

    cout<<(d==g? "우열을 가릴 수 없음":(d>g? "소수의 신 갓대웅":"소수 마스터 갓규성"))<<"\n";
}