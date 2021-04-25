// 17071번 숨바꼭질 5

#include <bits/stdc++.h>
using namespace std;

int n, k;
bool visited[500001][2];

int getSis(int c){
    return c*(c+1)/2+k;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>k;
    if(n==k){
        cout<<"0"<<"\n";
        exit(0);
    }
    
    queue<int> q;
    q.push(n);

    int cnt=0;
    while(!q.empty()){
        int sis=getSis(++cnt);
        if(sis>500000) break;
        if(visited[sis][cnt%2]){
            cout<<cnt<<"\n";
            exit(0);
        }

        int qs=q.size();
        while(qs--){
            int node=q.front(); q.pop();
            if(node-1==sis || node+1==sis || node*2==sis){
                cout<<cnt<<"\n";
                exit(0);
            }
            if(node-1>=0 && !visited[node-1][cnt%2]){
                visited[node-1][cnt%2]=1;
                q.push(node-1);
            }
            if(node+1<=500000 && !visited[node+1][cnt%2]){
                visited[node+1][cnt%2]=1;
                q.push(node+1);
            }
            if(node*2<=500000 && !visited[node*2][cnt%2]){
                visited[node*2][cnt%2]=1;
                q.push(node*2);
            }
        }
    }

    cout<<"-1"<<"\n";
}