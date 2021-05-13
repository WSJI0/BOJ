// 17371번 이사

#include <bits/stdc++.h>
using namespace std;

int n, point[1001][2], d=INT_MAX, ans;

double dis(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>point[i][0]>>point[i][1];
    for(int i=0; i<n; i++){
        int dd=0;
        for(int j=0; j<n; j++){
            if(i==j) continue;
            int cur=dis(point[i][0], point[i][1], point[j][0], point[j][1]);
            dd=max(cur, dd);
        }
        if(dd<d){
            d=dd;
            ans=i;
        }
    }

    cout<<point[ans][0]<<" "<<point[ans][1]<<"\n";
}