#include <bits/stdc++.h>
using namespace std;
#define p(X, Y, Z) make_tuple(X, Y, Z)

int n, k;
string ant[16];
map<tuple<string, int, string>, vector<tuple<string, int, string>>> graph;
vector<tuple<string, int, string>> start;

void print(tuple<string, int, string> cur){
    for(auto g:graph[cur]){
        string f="";
        for(int i=0; i<get<1>(g); i++) f+="--";
        cout<<f<<get<0>(g)<<"\n";
        print(g);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k;
        for(int j=0; j<k; j++) cin>>ant[j];
        string tmp="";
        for(int j=1; j<k; j++){
            graph[p(ant[j-1], j-1, tmp)].push_back(p(ant[j], j, tmp+" "+ant[j-1]));
            tmp+=" "+ant[j-1];
        }
    }

    for(auto i:graph) sort(i.second.begin(), i.second.end());
    for(auto i:graph){
        if(get<1>(i.first)==0) start.push_back(i.first);
    }

    sort(start.begin(), start.end());
    for(auto s:start){
        cout<<get<0>(s)<<"\n";
        print(s);
    }
}