#include <bits/stdc++.h>
using namespace std;

int n, k, l, ans=-1;
bool visited[9999999][11];

int get_len(){
    int len=0;
    int tmp=n;
    while(tmp){
        len++;
        tmp/=10;
    } return len;
}

int change(int n, int a, int b){
    int A, B, num[10];
    int tmp=n;
    for(int i=0; tmp>0; i++){
        num[i]=tmp%10;
        tmp/=10;
    } A=num[l-a-1], B=num[l-b-1];

    num[l-b-1]=A; num[l-a-1]=B;

    int ret=0;
    for(int i=0; i<l; i++){
        ret+=num[i]*(int)pow(10, i);
    } return ret;
}

int get(int n, int p){
    int num[10];
    int tmp=n;
    for(int i=0; tmp>0; i++){
        num[i]=tmp%10;
        tmp/=10;
    } return num[l-p-1];
}

void solve(int num, int cur){
    if(cur==0){
        ans=max(ans, num);
        return;
    }

    for(int i=0; i<l; i++){
        for(int j=i+1; j<l; j++){
            if(i==0 && get(num, j)==0) continue;

            int c=change(num, i, j);
            if(visited[c][cur-1]) continue;
            visited[c][cur-1]=1;
            solve(c, cur-1);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    l=get_len();

    solve(n, k);

    cout<<ans<<"\n";
}