// 12738번 가장 긴 증가하는 부분 수열 3

#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n; a[0]=-2000000000;
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> lis; lis.push_back(a[0]);
    for(int i=1; i<=n; i++){
        int l=lower_bound(lis.begin(), lis.end(), a[i])-lis.begin();
        if(l>=lis.size()) lis.push_back(a[i]);
        else lis[l]=a[i];
    }

    cout<<lis.size()-1<<"\n";
}