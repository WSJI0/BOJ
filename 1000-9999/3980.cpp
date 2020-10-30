//3980 선발 명단

#include <bits/stdc++.h>
using namespace std;

int selected[11]={0,};
int team[11][11];
int ans=0;
void make(int r, int score){
    if(r==11){
        ans=max(ans, score);
        return;
    }
    for(int i=0; i<11; i++){
        if(team[r][i]!=0 && selected[i]==0){
            selected[i]=1;
            make(r+1, score+team[r][i]);
            selected[i]=0;
        } 
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        for(int i=0; i<11; i++){
            selected[i]=0;
            for(int j=0; j<11; j++) cin>>team[i][j];
        }   
        make(0, 0);
        cout<<ans<<"\n";
    }
}