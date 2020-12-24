// 11505 구간 곱 구하기 (미완성)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll tree[1000001*4];
ll arr[1000001];

ll init(int s, int e, int node){
    if(s==e) return tree[node]=arr[s]; 
    int mid=(s+e)/2;
    return tree[node]=init(s, mid, node*2)*init(mid+1, e, node*2+1)%mod;
}

ll sum(int s, int e, int node, int l, int r){
    if(l>e || r<s) return 1;
    if(l<=s && e<=r) return tree[node];
    int mid=(s+e)/2;
    return sum(s, mid, node*2, l, r)*sum(mid+1, e, node*2+1, l, r)%mod;
}

void update(int s, int e, int node, int idx, int dif){
    if(idx<s || idx>e) return;
    tree[node]+=dif;
    if(s==e) return;
    int mid=(s+e)/2;
    update(s, mid, node*2, idx, dif);
    update(mid+1, e, node*2+1, idx, dif);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, m, k, a, b, c;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) cin>>arr[i];
    init(1, n, 1);

    for(int i=0; i<m+k; i++){
        cin>>a>>b>>c;
        if(a==1){
            update(1, n, 1, b, c-arr[b]);
            arr[b]=c;
        }
        else cout<<sum(1, n, 1, b, c)<<"\n";
    }
}