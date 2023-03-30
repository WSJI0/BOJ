#include <bits/stdc++.h>
using namespace std;

int n, tree[444444], in_order[100001], post_order[100001], mx;
bool visited[444444];
vector<int> post_res, in_res, ans;

void post(int cur){
    if(cur<=0) return;
    if(cur*2>mx || (visited[cur*2] && visited[cur*2+1])){
        visited[cur]=1;
        post_res.push_back(cur);
        post(cur/2);
        return;
    }
    if(!visited[cur*2]){
        post(cur*2);
    } else if(!visited[cur*2+1]){
        post(cur*2+1);
    }
}

void in(int cur){
    if(cur>mx || cur<=0) return;
    if(cur*2>mx){
        visited[cur]=1;
        in_res.push_back(cur);
        in(cur/2);
        return;
    }
    if(visited[cur*2]){
        if(!visited[cur]){
            visited[cur]=1;
            in_res.push_back(cur);
            in(cur*2+1);
        } else{
            in(cur/2);
        }
        return;
    }
    if(!visited[cur*2]){
        in(cur*2);
    }
}

void pre(int cur){
    if(cur>mx) return;
    ans.push_back(tree[cur]);
    pre(cur*2);
    pre(cur*2+1);
}


int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>in_order[i];
    for(int i=0; i<n; i++) cin>>post_order[i];
    
    int cur=2;
    vector<int> tmp;
    tmp.push_back(1);
    for(int i=0; i<16; i++){
        tmp.push_back(tmp.back()+cur);
        cur*=2;
    }
    for(int i=0; i<tmp.size(); i++){
        if(n<=tmp[i]){
            mx=tmp[i];
            break;
        }
    }

    post(1);
    for(int i=0; i<n; i++) cout<<post_res[i]<<" ";
    cout<<"\n";

    memset(visited, 0, sizeof(visited));
    in(1);
    for(int i=0; i<n; i++) cout<<in_res[i]<<" ";
    cout<<"\n";

    


    /*pre(1);
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    cout<<"\n";*/
}