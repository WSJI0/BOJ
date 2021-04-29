// 3111번 검열

#include <bits/stdc++.h>
using namespace std;

string a, b, t;
bool ex;
char p;
int turn, l, r;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>a>>t;
    b=a; reverse(b.begin(), b.end()); r=t.length()-1;

    vector<char> fr, ba;

    while(l<=r){
        if(turn%2==0){
            fr.push_back(t[l++]);
            if(fr.size()>=b.length()){
                ex=true;
                for(int i=0; i<b.length(); i++){
                    if(b[i]!=fr[fr.size()-1-i]){
                        ex=false;
                        break;
                    }
                }
                if(ex){
                    for(int i=0; i<b.length(); i++) fr.pop_back();
                    turn++;
                }
            }
        } else{
            ba.push_back(t[r--]);
            if(ba.size()>=b.length()){
                ex=true;
                for(int i=0; i<a.length(); i++){
                    if(a[i]!=ba[ba.size()-1-i]){
                        ex=false;
                        break;
                    }
                }
                if(ex){
                    for(int i=0; i<a.length(); i++) ba.pop_back();
                    turn++;
                }
            }
        }
    }

    while(!fr.empty()){
        ba.push_back(fr.back()); fr.pop_back();
        if(fr.size()>=a.length()){
            ex=true;
            for(int i=0; i<a.length(); i++){
                if(a[i]!=ba[ba.size()-1-i]){
                    ex=false;
                    break;
                }
            }
            if(ex){
                for(int i=0; i<a.length(); i++) ba.pop_back();
            }
        }
    }

    for(int i=ba.size()-1; i>=0; i--) cout<<ba[i];
    cout<<"\n";
}