#include <bits/stdc++.h>
using namespace std;

int N=8;

void update1(int x, int y, int d) {
    for (int i=y; i<=N; i+=(i&-i)) {
        for (int j=x; j<=N; j+=(j&-j)) {
            cout<<i<<" / "<<j<<"\n";
        }
    }
}

void update2(int x, int y, int d) {
    for (; y<=N; y+=(y&-y)) {
        for (; x<=N; x+=(x&-x)) {
            cout<<y<<" / "<<x<<"\n";
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    update1(1, 8, 8);

    cout<<"--------------------\n";
    
    update2(1, 8, 8);
}