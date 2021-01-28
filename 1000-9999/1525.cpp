// 1525번 퍼즐

#include <bits/stdc++.h>
using namespace std;

int board, ans=-1;
set<int> check;

int change[4]={1, -1, 3, -3};

int lpow(int a, int n){
    int res=a;
    for(int i=0; i<n-1; i++) res*=a;
    return res;
}

int move(int board, int l, int l2){
    l=8-l; l2=8-l2;
    int tmp=board/lpow(10, l)%10;
    int tmp2=board/lpow(10, l2)%10;

    board-=lpow(10, l)*tmp;
    board+=lpow(10, l)*tmp2;
    if(tmp2==0 && l==8) board*=10;
    board-=lpow(10, l2)*tmp2;
    board+=lpow(10, l2)*tmp;
    if(tmp==0 && l2==8) board*=10;
    return board;
}

void solve(int cnt, int board, int l){
    if(ans!=-1) return;
    if(board==123456780){
        ans=cnt;
        return;
    }
    for(int i=0; i<4; i++){
        if(l+change[i]>=0 && l+change[i]<9){
            int b=move(board, l, change[i]+l);
            cout<<change[i]<<" "<<b<<"\n";
            if(check.find(b)==check.end()){
                check.insert(board);
                //solve(cnt+1, b, change[i]+l);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int b, c;
    for(int i=0; i<9; i++){
        cin>>b;
        if(b==0) c=i;
        board*=10; board+=b;
    }

    solve(0, board, c);
    cout<<ans<<"\n";
}