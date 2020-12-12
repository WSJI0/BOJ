//2904번 수학은 너무쉬워 (미완성)

#include <bits/stdc++.h>
using namespace std;

long long int POW(int n, int a){
    if(a==0) return 1;
    else return n*POW(n, a-1);
}

map<int, int> cnt; 
map<int, int> c[101];
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, num[101];
    cin>>n;
    for(int i=0; i<n; i++) cin>>num[i];

    
    for(int i=0; i<n; i++){
        int N=num[i];
        for(int j=2; j*j<=N; j++){
            while(num[i]%j==0){  
                cnt[j]++;
                c[i][j]++;
                num[i]/=j;
            } if(num[i]==1) break;
        }
    }
    long long int ans=1, res=0; vector<pair<int, int>> a;
    for(auto i=cnt.begin(); i!=cnt.end(); i++){
        ans*=POW(i->first, (i->second/n));
        if(i->second>=n) a.push_back(make_pair(i->first, i->second));
    }
    for(int i=0; i<n; i++){
        for(auto j:a){
            if(c[i][j.first]>cnt[j.first]/n){
                res+=(c[i][j.first])-(cnt[j.first]/n);
            }
        }
    }

    cout<<ans<<" "<<res<<"\n";
}