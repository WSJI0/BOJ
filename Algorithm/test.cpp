#include <bits/stdc++.h> 
#define ll long long 
#define all(x) ((x).begin()),((x).end()) 
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using namespace std; 
#define int ll 
int firstvals[1010100]; 
int cycle, stp; 
int32_t main() { 
    firstvals[1] = 6; 
    firstvals[2] = 28; 
    for (int i = 3; i<=1005000; i++) { 
        firstvals[i] = (firstvals[i-1]*6 - firstvals[i-2]*4)+10000; 
        firstvals[i] %= 1000; 
    } int t; 
    scanf("%lld",&t); 
    int ct = 0; 
    while(t--) { 
        ct++; 
        int x; 
        scanf("%lld",&x); 
        int aa; 
        if (x > 104) 
        aa = firstvals[(x-4)%100+4]; 
        else 
        aa = firstvals[x]; 
        printf("Case #%lld: %03lld\n",ct,(aa+999)%1000); 
    } 
}