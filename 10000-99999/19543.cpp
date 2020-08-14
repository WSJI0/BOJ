#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<char>> block;
    vector<vector<char>> room(n);
    for(int i=0; i<k; i++){
        vector<char> b(m);
        for(int j=0; j<m; j++)
            cin>>b[j];
        block.push_back(b);
    }
    char r;
    int l=m-1, r=m-1;
    for(int i=0; i<n; i++){
        cin>>r;
        for(auto j:block[(int)r-65])
            room[i].push_back(j);
    }
}

/*
3 4 3
RURU
RRUR
UURU
CBA

7
*/