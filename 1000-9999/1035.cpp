// 1035번 조각 움직이기 (미완성)

#include <bits/stdc++.h>
using namespace std;

int cnt, ans=987654321, mov[4][2]={{10, 0}, {0, 1}, {-10, 0}, {0, -1}}, my, mx;
char b;

bool visited[56][56][56][56][56];
vector<int> star;

void print(){
    for(int i=0; i<cnt; i++) cout<<star[i]<<" ";
    cout<<"\n";
}

bool check(){
    int res=0, c=0;
    for(int i=0; i<cnt; i++){
        for(int j=0; j<cnt; j++){
            if(i==j) continue;
            for(auto v:mov){
                my=v[0]+(star[i]/10)*10;
                mx=v[1]+star[i]%10;
                if(my>=10 && my<=50 && mx>=1 && mx<=5 && my+mx==star[j]){
                    c=1;
                    break;
                }
            } if(c){
                c=0;
                res++;
                break;
            }
        }
    }
    if(res==cnt) return true;
    return false;
}

void change(int idx, int val){
    for(int i=0; i<cnt; i++){
        if(idx==i) if(visited[i][val])
    }
}

void dfs(int res){
    print();
    if(check()) ans=min(ans, res);
    for(int i=0; i<cnt; i++){
        for(auto v:mov){
            my=v[0]+(star[i]/10)*10;
            mx=v[1]+star[i]%10;
            if(my>=10 && my<=50 && mx>=1 && mx<=5){
                for(int j=0; j<cnt; j++) if(star[j]==my+mx) continue;
                int vv=0;
                for(int j=0; j<cnt; j++){
                    if(j==i) if(visited[i][my+mx]) vv++;
                    else if(visited[j][star[j]]) vv++;
                }
                if(vv!=cnt){
                    visited[i][my+mx]=1;
                    star[i]=my+mx;
                    dfs(res+1);
                    visited[i][my+mx]=0;
                    star[i]-=(v[0]+v[1]);
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            cin>>b;
            if(b=='*'){
                star.push_back(i*10+j);
                cnt++;
            }
        }
    }
    dfs(0);
    cout<<ans<<"\n";
}