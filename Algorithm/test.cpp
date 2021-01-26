// 14003 가장 긴 증가하는 부분 수열 5

#include <bits/stdc++.h>
using namespace std;

int n, a[1000001], b[1000001];
vector<int> lis, ans;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    lis.push_back(a[1]);

    int cur=0;
    for(int i=2; i<=n; i++){
        if(lis[cur]<a[i]){
            lis.push_back(a[i]);
            b[i]=++cur;
        } else{
            int l=lower_bound(lis.begin(), lis.end(), a[i])-lis.begin();
            b[i]=l;
            lis[l]=a[i];
        }
    }

    cout<<cur+1<<"\n";
    for(int i=n; i>=1 && cur>=0; i--){
        if(b[i]==cur){
            ans.push_back(a[i]);
            cur--;
        }
    }
    for(int i=ans.size()-1; i>=0; i--) cout<<ans[i]<<" ";
    cout<<"\n";
}