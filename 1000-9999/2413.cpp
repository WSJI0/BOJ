// 2413번 비슷한 순열

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, a[50001];
    map<int, bool> check;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        check[a[i]]=1;
    }

    int b[3]={-1, 0, 1};
    for(int i=0; i<n; i++){
        for(auto j:b){
            if(check[a[i]+j] && (check[a[i]+j+1] || check[a[i]+j-1])){
                check[a[i]+j]=0;
                cout<<a[i]+j<<" ";
                break;
            }
        }
    } cout<<"\n";
}