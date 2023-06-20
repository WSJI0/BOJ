#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> g;

bool check(){
    int cur=0;
    for(int i=0; i<n; i++){
        if(s[i]=='(') cur++;
        else{
            if(--cur<0) return false;
        }
    } if(cur==0) return true;
    return false;
}

void solve(int cur){
    if(cur==g.size()){
        if(check()){
            cout<<s<<"\n";
            exit(0);
        }
        return;
    }
    s[g[cur]]='(';
    solve(cur+1);
    s[g[cur]]=')';
    solve(cur+1);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>s;
    for(int i=0; i<n; i++){
        if(s[i]=='G') g.push_back(i);
    }

    solve(0);
}