#include <bits/stdc++.h>
using namespace std;

int n, f[200001];
int t[200001], p[200001];
vector<int> ans;
queue<int> q[10];
int d=6;

void radixSort(int* arr){
    int res[20];
    for(int i=0; i<20; i++) res[i]=arr[i];
    for(int i=0; i<d; i++){
        for(int j=0; j<20; j++){
            int tmp=res[j];
            for(int k=0; k<i; k++) tmp/=10;
            q[tmp%10].push(res[j]);
        }
        int cur=0;
        for(int j=0; j<10; j++){
            while(!q[j].empty()){
                res[cur++]=q[j].front();
                q[j].pop();
            }
        }
    } 
    for(int i=0; i<20; i++) arr[i]=res[i];
}

bool solve(){
    for(int i=0; i<n; i++){

    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>t[i];
    for(int i=0; i<n; i++) cin>>p[i];

    radixSort(t);
    radixSort(p); 

    if(solve()) cout<<"possible"<<"\n";
    else cout<<"impossible"<<"\n";
}