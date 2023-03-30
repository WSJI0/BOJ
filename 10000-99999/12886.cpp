#include <bits/stdc++.h>
using namespace std;

int a, b, c, na, nb, nc;
map<tuple<int, int, int>, bool> visited;

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>a>>b>>c;
    
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(a, b, c));
    visited[make_tuple(a, b, c)]=1;

    while(!q.empty()){
        tie(a, b, c)=q.front(); q.pop();
        na=a; nb=b; nc=c;
        if(a!=b){
            if(a>b){
                na=a-b;
                nb=b*2;
            } else{
                na=a*2;
                nb=b-a;
            }
            if(visited[make_tuple(na, nb, nc)]) continue;
            visited[make_tuple(na, nb, nc)]=1;
            if(na==nb && nb==nc){
                cout<<1<<"\n";
                return 0;
            }
            q.push(make_tuple(na, nb, nc));
        }
        if(b!=c){
            if(b>c){
                nb=b-c;
                nc=c*2;
            } else{
                nb=b*2;
                nc=c-b;
            }
            if(visited[make_tuple(na, nb, nc)]) continue;
            visited[make_tuple(na, nb, nc)]=1;
            if(na==nb && nb==nc){
                cout<<1<<"\n";
                return 0;
            }
            q.push(make_tuple(na, nb, nc));
        }
        if(a!=c){
            if(a>c){
                na=a-c;
                nc=c*2;
            } else{
                na=a*2;
                nc=c-a;
            }
            if(visited[make_tuple(na, nb, nc)]) continue;
            visited[make_tuple(na, nb, nc)]=1;
            if(na==nb && nb==nc){
                cout<<1<<"\n";
                return 0;
            }
            q.push(make_tuple(na, nb, nc));
        }
    } 
    if(a==b && b==c) cout<<1<<"\n";
    else cout<<0<<"\n";
}