/*
1132번
합
*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<char, int>& a, const pair<char, int>& b){
    return a.second>b.second;
}

int main(void){
    int n;
    cin>>n;
    string a[n];
    map<char, int> m;
    int zero[10]={0};
    for(int i=0; i<n; i++){
        cin>>a[i];
        for(int j=0; j<a[i].length(); j++){
            m[a[i][j]]+=pow(10, a[i].length()-j-1);
        }
    }
    vector<pair<char, int>> alpha;
    for(auto i=m.begin(); i!=m.end(); i++)
        alpha.push_back(pair<char, int>(i->first,i->second));
    sort(alpha.begin(), alpha.end(), cmp);
    map<char, int> change;
    int num=9;
    for(int i=0; i<alpha.size(); i++){
        change[alpha[i].first]=num;
        num--;
    }

    for(auto i=change.begin(); i!=change.end(); i++)
        cout<<i->first<<"  "<<i->second<<endl;
    
}