#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll unsigned long long int

int n, m, k, a, b, c;
ll tree[4444444]={1, }, arr[1000001];

ll init(int s, int e, int node){
    if(s==e) return tree[node]=arr[s];
    return tree[node]=(init(s, (s+e)/2, node*2)*init((s+e)/2+1, e, node*2+1))%mod;
}

ll getM(int s, int e, int node, int l, int r){
    if(l>e || r<s) return 1;
    if(l<=s && e<=r) return tree[node];
    return (getM(s, (s+e)/2, node*2, l, r)*getM((s+e)/2+1, e, node*2+1, l, r))%mod;
}

ll update(int s, int e, int node, int idx, int v){
    if(idx<s || idx>e) return tree[node];
    if(s==e) return tree[node]=v;
    return tree[node]=(update(s, (s+e)/2, node*2, idx, v)*update((s+e)/2+1, e, node*2+1, idx, v))%mod;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    init(1, n, 1);

    for(int i=0; i<m+k; i++){
        cin>>a>>b>>c;
        if(a==1){
            update(1, n, 1, b, c);
            arr[b]=c;
        } else{
            cout<<getM(1, n, 1, b, c)<<"\n";
        }
    }
}