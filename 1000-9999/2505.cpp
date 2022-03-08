// 2505번 두 번 뒤집기

#include <bits/stdc++.h>
using namespace std;

int n, a[10003], b[10003], l, r;
int ans[2][2], fin=0;

void check(){
    if(fin) return;
    for(int i=1; i<=n; i++){
        if(a[i]!=i) return;
    }
    if(ans[0][0]>ans[0][1]) cout<<"1 1"<<"\n";
    else cout<<ans[0][0]<<" "<<ans[0][1]<<"\n";
    if(ans[1][0]>ans[1][1]) cout<<"1 1"<<"\n";
    else cout<<ans[1][0]<<" "<<ans[1][1]<<"\n";
    fin=1;
}

void flip(int l, int r){
    int left=l, right=r;
    while(left<=right){
        swap(a[left], a[right]);
        left++; right--;
    }
}

pair<int, int> moveLeft(){
    int pr;
    for(int i=l; i<=r; i++){
        if(a[i]==l){
            pr=i;
            break;
        }
    }
    flip(l, pr);
    return make_pair(l, pr);
}

pair<int, int> moveRight(){
    int pl;
    for(int i=l; i<=r; i++){
        if(a[i]==r){
            pl=i;
            break;
        }
    }
    flip(pl, r);
    return make_pair(pl, r);
}

void findLR(){
    for(int i=1; i<=n; i++){
        l=i;
        if(a[i]!=i) break;
    }
    for(int i=n; i>=1; i--){
        r=i;
        if(a[i]!=i) break;
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        b[i]=a[i];
    }

    findLR();

    tie(ans[0][0], ans[0][1])=moveLeft(); findLR();
    ans[1][0]=l; ans[1][1]=r; flip(l, r); check();
    for(int i=1; i<=n; i++) a[i]=b[i]; findLR();
    tie(ans[0][0], ans[0][1])=moveRight(); findLR();
    ans[1][0]=l; ans[1][1]=r; flip(l, r); check();
}
