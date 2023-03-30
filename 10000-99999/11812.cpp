#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n, k, q, x, y;
vector<pair<ll, ll>> x_res, y_res;

void x_solve(ll cur, int cnt){
    if(cur<=0) return;
    x_res.push_back(make_pair(cur, cnt));
    x_solve(cur/k, cnt+1);
}
void y_solve(ll cur, int cnt){
    if(cur<=0) return;
    y_res.push_back(make_pair(cur, cnt));
    y_solve(cur/k, cnt+1);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>k>>q;
    for(int i=0; i<q; i++){
        cin>>x>>y;
        if(k==1) cout<<abs(x-y)<<"\n";
        else{
            while(!x_res.empty()) x_res.pop_back();
            while(!y_res.empty()) y_res.pop_back();
            x_solve(x, 0);
            y_solve(y, 0);

            int l=0, r=0;
            while(x_res[l].first!=y_res[r].first){
                if(x_res[l].first>y_res[r].first) l++;
                else r++;
            }
            cout<<x_res[l].second+y_res[r].second<<"\n";
        }
    }
}