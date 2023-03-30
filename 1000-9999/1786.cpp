#include <bits/stdc++.h>
using namespace std;

int n, m, f[1000001];
string t, p;
vector<int> ans;

void kmp(){
    int i=0, j=0;
    while(i<n){
        if(t[i]==p[j]){
            if(j==m-1){
                ans.push_back(i-j+1);
                i++;
                j=f[j];
            } else{
                i++;
                j++;
            }
        } else{
            if(j>0) j=f[j-1];
            else i++;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    getline(cin, t);
    getline(cin, p);
    n=t.size(); m=p.size();

    int r=1, l=0;
    while(r<m){
        if(p[l]==p[r]){
            f[r]=l+1;
            l++; r++;
        } else if(l>0){
            l=f[l-1];
        } else{
            f[l]=0;
            r++;
        }
    }

    kmp();
    cout<<ans.size()<<"\n";
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<"\n";
}