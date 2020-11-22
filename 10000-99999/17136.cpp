//17136번 색종이 붙이기

#include <bits/stdc++.h>
using namespace std;

bool board[10][10];
int cnt[5]={5, 5, 5, 5, 5};
int ans=987654321;

bool check(bool b[][10], int j, int k, int s, int& i){
    if(j+s>=10 || k+s>=10) return false;
    for(int y=j; y<j+s; y++){
        for(int x=k; x<k+s; x++){
            if(!b[y][x]) return false;
        }
    }
    return true;
}

void solve(int i, bool b[][10], int cnt[5]){
    int res=25;
    for(int i=0; i<5; i++) res-=cnt[i];
    if(res>=ans) return;

    if(i==0){
        ans=min(ans, res);
        return;
    }
    
    for(int j=0; j<10; j++){
        for(int k=0; k<10; k++){
            if(b[j][k]){
                bool ok=false;
                for(int s=1; s<=5; s++){
                    if(!cnt[s-1]) continue;
                    ok=true;
                    if(check(b, j, k, s, i)){
                        for(int y=j; y<j+s; y++){
                            for(int x=k; x<k+s; x++) b[y][x]=0;
                        } i-=s*s;
                        cnt[s-1]--;
                        solve(i, b, cnt);
                        cnt[s-1]++;
                        for(int y=j; y<j+s; y++){
                            for(int x=k; x<k+s; x++) b[y][x]=1;
                        } i+=s*s;
                    }
                }
                if(!ok) return;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int c=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>board[i][j];
            if(board[i][j]==1) c++;
        }
    }
    solve(c, board, cnt);
    cout<<(ans==987654321? -1:ans)<<"\n";
}