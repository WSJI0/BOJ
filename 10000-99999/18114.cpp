#include <bits/stdc++.h>
using namespace std;

int n, c, a;
vector<int> w;

bool biSearch(int a, int b){
    int num=c-(w[a]+w[b]);
    if(num==w[a] || num==w[b]) return false;
    int l=0, r=n-1, mid;
    while(l<=r){
        mid=(l+r)/2;
        if(w[mid]>num) r=mid-1;
        else if(w[mid]<num) l=mid+1; 
        else return true;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>c;
    for(int i=0; i<n; i++){
        cin>>a;
        w.push_back(a);
    }

    sort(w.begin(), w.end());

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(w[i]==c || w[i]+w[j]==c || biSearch(i, j)){
                cout<<"1"<<"\n";
                return 0;
            }
        }
    }
    cout<<"0"<<"\n";
}
