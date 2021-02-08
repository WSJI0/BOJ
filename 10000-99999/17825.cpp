// 17825번 주사위 윷놀이 (미완성)

#include <bits/stdc++.h>
using namespace std;

int dice[10], piece[4], ans=0;
int P[3][6]={
    {0, 13, 16, 19, 25, 100030},
    {0, 22, 24, 25, 100030, 35},
    {0, 28, 27, 26, 25, 100030}
};

void solve(int cnt, int score){
    if(cnt==10){
        ans=max(ans, score%100000);
        return;
    }
    for(int i=0; i<4; i++){
        int& p=piece[i];
        if(p==-1) continue;
        int tmp=p;
        if(p==0)
            p=dice[cnt]*2;
        else{
            if(p%10==0 && p<40){
                p=P[p/10][dice[cnt]];
            } else if(p==25){
                if(dice[cnt]>=4) p=-1;
                else{
                    p=25+dice[cnt]*5;
                }
            } else{
                if(p>=32) 
                else p=p+dice[cnt]*2;
            }
        }
        bool ok=true;
        for(int j=0; j<4; j++){
            if(i==j) continue;
            if(piece[j]==p && p!=-1 && p!=0) ok=false;
        }
        if(ok) solve(cnt+1, score+p);
        p=tmp;
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<10; i++) cin>>dice[i];
    solve(0, 0);
    cout<<ans<<"\n";
}