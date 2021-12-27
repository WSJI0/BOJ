/*
1022번
소용돌이 예쁘게 출력하기
*/

#include <bits/stdc++.h>
using namespace std;

int r1, c1, r2, c2;
int cur=0, cnt=0, y=0, x=0;
bool visited[10001][10001];
int ans[51][51];
int d=-1;
int mv[4][2]={
    {0, 1}, {-1, 0}, {0, -1}, {1, 0}
};

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>r1>>c1>>r2>>c2;
    cnt=(r2-r1+1)*(c2-c1+1);
    while(1){
        visited[y+5000][x+5000]=1; cur++;
        if(y>=r1 && y<=r2 && x>=c1 && x<=c2){
            ans[y-r1][x-c1]=cur;
            cnt--;
        }
        if(cnt==0) break;
        int nd=(d+1)%4;
        int my=y+mv[nd][0], mx=x+mv[nd][1];
        if(visited[my+5000][mx+5000]==0) d=(d+1)%4;
        y+=mv[d][0]; x+=mv[d][1];
    }
    int maxL=0;
    for(int i=0; i<r2-r1+1; i++){
        for(int j=0; j<c2-c1+1; j++)
            maxL=max(maxL, to_string(ans[i][j]).size());
    }

    for(int i=0; i<r2-r1+1; i++){
        for(int j=0; j<c2-c1+1; j++){
            for(int k=0; k<maxL-to_string(ans[i][j]).size(); k++) cout<<" ";
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
