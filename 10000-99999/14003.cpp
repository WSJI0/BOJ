// 14003 가장 긴 증가하는 부분 수열 5

#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];
vector<int> lis;

int lb(int s, int e, int k){
    int l=s, r=e, mid, ans=INT_MAX;
    while(l<=r){
        mid=(l+r)/2;
        if(k<=a[lis[mid]]){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n; a[0]=-2000000000;
    for(int i=1; i<=n; i++) cin>>a[i];
    lis.push_back(0);

    for(int i=1; i<=n; i++){
        int l=lb(0, lis.size(), a[i]);
        if(l==INT_MAX) lis.push_back(i);
        else lis[l]=i;
    }

    for(int i=0; i<lis.size(); i++) cout<<a[lis[i]]<<" ";
    cout<<"\n";
}