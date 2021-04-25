// 14574번 헤븐스 키친

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ans1;
pair<int, int> ans2[1001], tmp[1001];
int n, p[1001], c[1001];
bool visited[1001];

int vs(int a, int b){
    return (c[a]+c[b])/abs(p[a]-p[b]);
}

void solve(int win, ll cur, int cnt){
    if(cnt==n){
        if(cur>ans1){
            ans1=cur;
            for(int i=0; i<n; i++) ans2[i]=tmp[i];
        }
        return;
    }
    for(int i=win+1; i<n; i++){
        if(visited[i]) continue;
        tmp[cnt-1]=make_pair(win, i);
        visited[i]=1;
        solve(win, cur+vs(win, i), cnt+1);
        solve(i, cur+vs(win, i), cnt+1);
        visited[i]=0;
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>p[i]>>c[i];

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            visited[i]=visited[j]=1;
            tmp[0]=make_pair(i, j);
            solve(i, vs(i, j), 2);
            solve(j, vs(i, j), 2);
            visited[i]=visited[j]=0;
        }
    }

    cout<<ans1<<"\n";
    for(int i=0; i<n-1; i++){
        cout<<ans2[i].first+1<<" "<<ans2[i].second+1<<"\n";
    }
}