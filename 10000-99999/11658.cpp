#include <bits/stdc++.h>
using namespace std;

int n, m, w, xa, ya, xb, yb, c;
int board[1030][1030], tree[1030][4444];

int init(int y, int s, int e, int node){
    if(s==e) return tree[y][node]=board[y][s];
    return tree[y][node]=init(y, s, (s+e)/2, node*2)+init(y, (s+e)/2+1, e, node*2+1);
}

int getSum(int y, int s, int e, int node, int l, int r){
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[y][node];
    return getSum(y, s, (s+e)/2, node*2, l, r)+getSum(y, (s+e)/2+1, e, node*2+1, l, r);
}

void update(int y, int s, int e, int node, int idx, int val){
    if(idx<s || idx>e) return;
    tree[y][node]+=val;
    if(s==e) return;
    update(y, s, (s+e)/2, node*2, idx, val);
    update(y, (s+e)/2+1, e, node*2+1, idx, val);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin>>board[i][j];
        init(i, 1, n, 1);
    }

    for(int i=0; i<m; i++){
        cin>>w;     
        if(w==0){
            cin>>ya>>xa>>c;
            update(ya, 1, n, 1, xa, (c-board[ya][xa]));
            board[ya][xa]=c;
        } else{
            cin>>ya>>xa>>yb>>xb;
            int ans=0;
            
            for(int j=ya; j<=yb; j++){
                ans+=getSum(j, 1, n, 1, xa, xb);
            }
            cout<<ans<<"\n";
        }
    }
}