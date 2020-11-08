//2661번 좋은수열

#include <bits/stdc++.h>
using namespace std;

int res[80]={0};
int n;

void print(){
    int i=0;
    while(res[i]!=0) cout<<res[i++];
    cout<<"\n";
}

bool check(int d){
    if(d==1) return true;
    for(int i=1; i<=(d/2); i++){
        for(int j=0; j<d-i; j++){
            int cnt=0;
            for(int k=j; k<j+i; k++){
                if(k+i>=d) break;
                if(res[k]==res[k+i]) cnt++;
            }
            if(cnt==i) return false;
        } 
    }
    return true;
}

void solve(int d){
    if(d==n){
        print();
        exit(0);
    }
    for(int i=1; i<=3; i++){
        if(d!=0 && res[d-1]==i) continue;
        res[d]=i;
        if(check(d+1)) solve(d+1);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    solve(0);
}