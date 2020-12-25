// 1275 커피숍2

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int tree[100001*4];
int arr[100001];

ll init(int s, int e, int node){
    if(s==e) return tree[node]=arr[s]; 
    return tree[node]=init(s, (s+e)/2, node*2)+init((s+e)/2+1, e, node*2+1);
}

ll sum(int s, int e, int node, int l, int r){
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[node];
    return sum(s, (s+e)/2, node*2, l, r)+sum((s+e)/2+1, e, node*2+1, l, r);
}

void update(int s, int e, int node, int idx, int val){
    if(idx<s || idx>e) return;
    tree[node]+=val;
    if(s==e) return;
    update(s, (s+e)/2, node*2, idx, val);
    update((s+e)/2+1, e, node*2+1, idx, val);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q, x, y, a, b;
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>arr[i];

    init(1, n, 1);

    for(int i=0; i<q; i++){
        cin>>x>>y>>a>>b;
        if(x>y) swap(x, y);
        cout<<sum(1, n, 1, x, y)<<"\n";
        update(1, n, 1, a, b-arr[a]);
    }
}