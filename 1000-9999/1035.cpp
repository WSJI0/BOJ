// 1035번 조각 움직이기 (미완성)

#include <bits/stdc++.h>
using namespace std;

vector<int> star;
int cnt, ans=987654321, board=(1<<25)-1;
int mov[4][2]={
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};
char b;
bool visited[1<<25], c[6][6];

bool getBit(int b, int i){
    return b&(1<<i);
}
int changeBit(int b, int i, bool a){
    if(a) return b|(1<<i);
    else return b&~(1<<i);
}

void print(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(getBit(board, i*5+j)) cout<<".";
            else cout<<"*";
        } cout<<"\n";
    }
    cout<<"---------------\n";
}

bool check(){
    int res=1;
    memset(c, 0, sizeof(c));

    queue<int> q;
    q.push(star[0]);
    c[star[0]/5][star[0]%5]=1;

    while(!q.empty()){
        int node=q.front(); q.pop();
        for(auto v:mov){
            int my=(node/5)+v[0];
            int mx=(node%5)+v[1];
            if(0<=mx && mx<5 && 0<=my && my<5){
                if(c[my][mx]) continue;
                if(getBit(board, my*5+mx)) continue;
                c[my][mx]=1;
                q.push(my*5+mx);
                res++;
            }
        }
    }
    if(res==cnt) print();
    if(res==cnt) return true;
    return false;
}

void solve(int res){
    if(check()) ans=min(ans, res);

    for(int i=0; i<cnt; i++){
        int y=star[i]/5, x=star[i]%5;
        for(auto v:mov){
            int my=y+v[0];
            int mx=x+v[1];
            if(0<=mx && mx<5 && 0<=my && my<5){
                if(!getBit(board, my*5+mx)) continue;
                board=changeBit(board, my*5+mx, 0);
                board=changeBit(board, y*5+x, 1);
                if(!visited[board]){
                    star[i]=my*5+mx;
                    visited[board]=1;
                    solve(res+1);
                    star[i]=y*5+x;
                    visited[board]=0;
                }
                board=changeBit(board, my*5+mx, 1);
                board=changeBit(board, y*5+x, 0);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>b;
            if(b=='*'){
                star.push_back(i*5+j);
                board=changeBit(board, i*5+j, 0);
                cnt++;
            }
        }
    }
    solve(0);
    cout<<ans<<"\n";
}