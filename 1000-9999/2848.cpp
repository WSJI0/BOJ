// 2848번 알고스팟어

#include <bits/stdc++.h>
using namespace std;

int n;
string s[101];
vector<int> graph[27];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>s[i];

    for(int i=0; i<10; i++){
        for(int j=0; j<n; j++){
            if(s[j].size()<=i) continue;
            if(i==0) continue;
            if(s[j][i-1]-'a'!=s[j][i]){
                graph[s[j][i-1]-'a'].push_back(s[j][i]-'a');
            }
        }
    }

    for(int i=0; i<26; i++){
        if(graph[i].empty()) continue;
        cout<<(char)(i+'a')<<" : ";
        for(int j=0; j<graph[i].size(); j++) cout<<(char)(graph[i][j]+'a')<<" ";
        cout<<"\n";
    }
}