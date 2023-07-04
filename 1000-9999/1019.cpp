#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string s;
ll ans[10];

void solve(int cur){
    if(cur==s.size()) return;

    for(int i=0; i<10; i++){
        if(cur==0 && i==0) continue;
        if((s[cur]-'0')>i){
            ll p=1, tmp=0, pp=pow(10, s.size()-1);
            if(cur==0) ans[i]+=pp;
            else{
                for(int j=cur-1; j>=0; j--){
                    tmp+=p*(s[j]-'0');
                    p*=10;
                } tmp+=(i==0? 0:1); 
                while(tmp!=0 && tmp<pp) tmp*=10;
                ans[i]+=tmp/10;
            }
        } else if((s[cur]='0')==i){
            ll p=1, tmp=0;
            for(int j=s.size()-1; j>=0; j--){
                if(j==cur) continue;
                tmp+=p*(s[j]-'0');
                p*=10;
            } ans[i]+=tmp+1;
        } else{
            ll p=1, tmp=0, pp=pow(10, s.size()-1);
            for(int j=cur-1; j>=0; j--){
                tmp+=p*(s[j]-'0');
                p*=10;
            } tmp+=(i==0? 0:1); 
            while(tmp!=0 && tmp<pp) tmp*=10;
            ans[i]+=tmp/10;
        }
    } solve(cur+1);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>s;
    solve(0);

    ans[0]++;
    for(int i=0; i<10; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}