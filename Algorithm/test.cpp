#include<iostream>
 
#define ull unsigned long long int
#define FOR(i, N) for(int i = 1; i<=N; i++)
 
using namespace std;
ull miller_base[] = { 2,7, 61 };
ull power(ull x, ull y, ull mod);
bool miller(ull n, ull a);
 
int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int N; cin >> N;
    ull a;
    int ans = 0;
    FOR(j, N){
        cin >> a;
        a = a * 2 + 1;
        FOR(i, 3) {
            if (miller(a, miller_base[i - 1]) == false) {
                ans++;
                break;
            }
        }
    }
    cout << N- ans;
}
ull power(ull x, ull y, ull mod) {
    ull res = 1;
    x %= mod;
    while (y) {
        if (y % 2) res = (res*x) % mod;
        y /= 2;
        x = (x*x) % mod;
    }
    return res;
}
 
bool miller(ull n, ull a) {
    if (a % n == 0) return true;
    ull k = n - 1;
    while (1) {
        ull temp = power(a, k, n);
        if (temp == n - 1) return true; 
        if (k % 2) return (temp == 1 || temp == n-1);
        k /= 2;
    }
}