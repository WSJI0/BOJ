#include <bits/stdc++.h>
using namespace std;

int minTree[100000*4];
int maxTree[100000*4];
int arr[100001];

int initMin(int s, int e, int node){
    if(s==e) return minTree[node]=arr[s]; 
    return minTree[node]=min(initMin(s, (s+e)/2, node*2), initMin((s+e)/2+1, e, node*2+1));
}
int initMax(int s, int e, int node){
    if(s==e) return maxTree[node]=arr[s]; 
    return maxTree[node]=max(initMax(s, (s+e)/2, node*2), initMax((s+e)/2+1, e, node*2+1));
}

int getMin(int s, int e, int node, int l, int r){
    if(l>e || r<s) return 9999999999;
    if(l<=s && e<=r) return minTree[node];
    return min(getMin(s, (s+e)/2, node*2, l, r), getMin((s+e)/2+1, e, node*2+1, l, r));
}

int getMax(int s, int e, int node, int l, int r){
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return maxTree[node];
    return max(getMax(s, (s+e)/2, node*2, l, r), getMax((s+e)/2+1, e, node*2+1, l, r));
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, a, b;
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>arr[i];

    initMin(1, n, 1);
    initMax(1, n, 1);

    for(int i=0; i<m; i++){
        cin>>a>>b;
        cout<<getMin(1, n, 1, a, b)<<" ";
        cout<<getMax(1, n, 1, a, b)<<"\n";
    }

    for(int i=1; i<=2*n+1; i++) cout<<minTree[i]<<" ";
    cout<<"\n";
}