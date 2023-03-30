#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long int

int n, k, dp[16][100];
string st[16];
int s[16], ml[50*15+1];
int visited[1<<15];

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int getMod(string s){
    int p=0;
    for(int i=0; i<s.length(); i++){
        p=(p*10+(s[i]-'0'))%k;
    } return p;
}

int solve(int cur, int m, int l, int vis){
    if(vis==1<<15-1){
        if(m==0) return 1;
        return 0;
    }
    
    for(int i=0; i<n; i++){
        
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i=0; i<n; i++) cin>>st[i];
    cin>>k;
    for(int i=0; i<n; i++) s[i]=getMod(st[i]);

    string tmp="1";
    for(int i=0; i<=50*15; i++){
        ml[i]=getMod(tmp);
        tmp+="0";
    }

    ll f=1, ans=0;
    for(int i=2; i<=n; i++) f*=i;

    for(int i=0; i<n; i++){
        ans+=solve(i, s[i], st[i].length(), 1);
    }

    if(ans==0) cout<<"0/1"<<"\n";
    else cout<<ans/gcd(ans, f)<<"/"<<f/gcd(ans, f)<<"\n";
}

/*
1. 숫자들을 전부 k의 나머지로 바꾸는데 숫자의 길이는 저장해놔야됨
2. 완탐을 하는데 숫자 배치할때 (k나머지)*pow(10, 지금까지의 길이)의 나머지를 구해야됨 
3. 2번의 pow식은 미리 계산해서 ml에 들어감


(A*B)%C=((A%C)*(B%C))%C
*/