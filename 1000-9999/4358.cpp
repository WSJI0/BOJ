//4358번 생태학

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    double cnt=0.0;
    map<string, int> m;
    while(getline(cin, s)){
        m[s]++;
        cnt++;
    }
    cout<<fixed;
    cout.precision(4);
    for(auto i=m.begin(); i!=m.end(); i++){
        cout<<i->first<<" "<<(i->second)/cnt*100<<"\n";
    }
}