#include <bits/stdc++.h>
using namespace std;

int a[8], res[8], ans;

int ccw(int p1, int p2, int p3){
    double x1=0.0, y1=(double)p1, x2=(sqrt(2)/2.0)*p2, y2=(sqrt(2)/2.0)*p2, x3=(double)p3, y3=0.0;
    return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}

void solve(int cur){
    if(cur>=3){
        if(ccw(res[cur-3], res[cur-2], res[cur-1])>0) return;
    }
    if(cur==8){
        ans++;
        return;
    }

    for(int i=0; i<8; i++){
        if(!a[i]) continue;
        res[cur]=a[i]; a[i]=0;
        solve(cur+1);
        a[i]=res[cur];
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<8; i++) cin>>a[i];

    solve(0);
    cout<<ans<<"\n";
}