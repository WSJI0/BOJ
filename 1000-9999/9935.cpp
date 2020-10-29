#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    string str, bomb;
    getline(cin, str);
    getline(cin, bomb);

    for(int i=0; i<str.size(); i++){
        s+=str[i];
        if(s.length()<bomb.size()) continue;
        bool ex=true;
        for(int j=0; j<bomb.size(); j++){
            if(s[s.length()-j-1]!=bomb[bomb.size()-j-1])
                ex=false;
        }
        if(ex) s=s.substr(0, s.length()-bomb.size());
    }
    if(s.length()==0) cout<<"FRAULA"<<"\n";
    else cout<<s<<"\n";
}