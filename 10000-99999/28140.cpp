#include <bits/stdc++.h>
using namespace std;

int n, q, l, r;
string s;
vector<int> R;
vector<int> B;
int ans[4];

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>q>>s;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='R') R.push_back(i);
        else B.push_back(i);
    }

    while(q--){
        cin>>l>>r;

        memset(ans, -1, sizeof(ans));
        int ll=0, rr=R.size()-1;
        while(ll<=rr){
            int mid=(ll+rr)/2;
            if(R[mid]>l) rr=mid-1;
            else if(R[mid]<l){
                ans[0]=R[mid];
                ll=mid+1;
            } else{
                ans[0]=R[mid];
                break;
            }
        } if(ans[0]+1<R.size() && R[ans[0]+1]<r) ans[1]=R[ans[0]+1];
        cout<<ans[0];
        l=ans[1]; ll=0; rr=B.size()-1;
        while(ll<=rr){
            int mid=(ll+rr)/2;
            if(B[mid]>l) rr=mid-1;
            else if(B[mid]<l){
                ans[2]=B[mid];
                ll=mid+1;
            } else{
                ans[2]=B[mid];
                break;
            }
        } if(ans[2]<B.size() && B[ans[2]+1]<r) ans[3]=B[ans[2]+1];

        if(ans[0]!=-1 && ans[1]!=-1 && ans[2]!=-1 && ans[3]!=-1){
            cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<"\n";
        } else cout<<"-1"<<"\n";
    }
}