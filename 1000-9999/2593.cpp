//2593번 엘리베이터

#include <bits/stdc++.h>
using namespace std;

class elevator{
    public:
        int x, y;
        bool canGo(int f){
            if(f>=x && (f-x)%y==0) return true;
            return false;
        }
};

int n, m, a, b, visited[101];
elevator* e;

int linked(int a, int b){
    e[a].x
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    e=new elevator[m+1];
    for(int i=1; i<=m; i++){
        cin>>e[i].x>>e[i].y;
    }
    cin>>a>>b;

    bool ans=false;
    stack<pair<int, vector<int>>> q;
    for(int i=1; i<=m; i++){
        vector<int> v;
        v.push_back(i);
        if(e[i].canGo(a)){
            if(e[i].canGo(b)){
                ans=true;
                cout<<"1"<<"\n";
                cout<<i<<"\n";
            }
            q.push(make_pair(i, v));
        }
    }

    int cnt=1;
    while(!q.empty()){
        cnt++;
        for(int ii=0; ii<q.size(); ii++){
            pair<int, vector<int>> node=q.top(); q.pop();
            int ele=node.first;
            vector<int> &v=node.second;
            for(int i=1; i<=m; i++){
                if(!linked(ele, i) || i==ele || visited[i]) continue;
                if(e[i].canGo(b) && !ans){
                    ans=true;
                    cout<<cnt<<"\n";
                    for(int j=0; j<v.size(); j++)
                        cout<<v[j]<<"\n";
                    cout<<i<<"\n";
                    break;
                }
                v.push_back(i);
                q.push(make_pair(i, v));
                v.pop_back();
            }
        }
        if(ans) break;
    }
}