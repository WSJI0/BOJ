#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[27];
int ans=0;

void solve(int cur, int last){
    if(cur==s.length()){
        ans++;
        return;
    }

    for(int i=0; i<26; i++){
        if(cnt[i] && last!=i){
            cnt[i]--;
            solve(cur+1, i);
            cnt[i]++;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>s;

    for(int i=0; i<s.length(); i++) cnt[s[i]-'a']++;
    solve(0, -1);
    cout<<ans<<"\n";
}