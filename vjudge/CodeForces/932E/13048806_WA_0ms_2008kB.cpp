#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
// p < 1e9
ll qpow(ll a, ll b, ll p = mod) { // return a^b %p
    ll t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
inline long long pow_mod(long long a, long long n) {
    long long ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
long long getinv(long long n) {
    return pow_mod(n, mod - 2);
}
int main(){
    ll n,k;
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> k;
    if (n == 1){
        cout << qpow(n,k) << endl;
        return 0;
    }
    ll ans = 1;
    REP(i,0,k){
        ans  = ans * (n + i);
        ans %= mod;
    }
    ll ans2 = 1;
    ll tmp = getinv(2);
    if (n-k < 0){
        ans2 = qpow(tmp,k-n);
    }else{
        ans2 = qpow(2,n-k);
    }

    cout << ans2 * ans % mod << endl;
    return 0;
}