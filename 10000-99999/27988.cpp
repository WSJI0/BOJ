#include <bits/stdc++.h>
using namespace std;

int n, l;

struct rib{
    int x;
    int s;
    int e;
    char c;
    int num;
};

bool compare(const rib& r1, const rib& r2){
    if(r1.s==r2.s){
        return 1;
    }
    return r1.s<r2.s;
}

rib r[1000001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>r[i].x;
    for(int i=0; i<n; i++){
        cin>>l;
        r[i].s=r[i].x-l;
        r[i].e=r[i].x+l;
        r[i].num=i+1;
    }
    for(int i=0; i<n; i++) cin>>r[i].c;
    sort(r, r+n, compare);

    int cur=0;
    char co;
    while(cur<n){
        co=cur.
    }
    cout<<"NO"<<"\n";
}