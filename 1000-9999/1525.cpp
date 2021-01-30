// 1525번 퍼즐

#include <bits/stdc++.h>
using namespace std;

int board, ans=-1;
unordered_map<int, bool> check;

int change[4]={1, -1, 3, -3};

int lpow(int a, int n){
    int res=1;
    for(int i=0; i<n; i++) res*=a;
    return res;
}

int move(int board, int l, int l2){
    l=8-l; l2=8-l2;
    int tmp=board/lpow(10, l)%10;
    int tmp2=board/lpow(10, l2)%10;

    board-=lpow(10, l)*tmp;
    board+=lpow(10, l)*tmp2;
    board-=lpow(10, l2)*tmp2;
    board+=lpow(10, l2)*tmp;

    return board;
}

void solve(int cnt, int board, int l){
    if(cnt==2){
        cout<<board<<"\n";
    }
    if(ans!=-1) return;
    if(board==123405786){
        ans=cnt;
        return;
    }
    for(int i=0; i<4; i++){
        int L=l+change[i];
        if(L>=0 && L<9){
            if((l%3==2 && i==0) || (l%3==0 && i==1)) continue; 
            int b=move(board, l, L);
            if(!check[b]){
                check[b]=true;
                solve(cnt+1, b, L);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int b, c;
    for(int i=0; i<9; i++){
        cin>>b;
        if(b==0){
            c=i; b=9;
        }
        board*=10; board+=b;
    }

    solve(0, board, c);
    cout<<ans<<"\n";
}