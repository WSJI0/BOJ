// 세그먼트 트리

#include <bits/stdc++.h>
using namespace std;

int tree[12*4];
int arr[12]={1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5};

int init(int s, int e, int node){
    if(s==e) return tree[node]=arr[s]; 
    return tree[node]=init(s, (s+e)/2, node*2)+init((s+e)/2+1, e, node*2+1);
}

int sum(int s, int e, int node, int l, int r){
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
    init(0, 12, 1);
    cout<<sum(0, 12, 1, 0, 12)<<"\n";
    update(0, 12, 1, 5, -5);
    cout<<sum(0, 12, 1, 0, 12)<<"\n";
}