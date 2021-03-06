#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
const int maxn = 10005;
ll n, m, k;
const long long mod = 1000000007;
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int Times = 10;
const int N = 5500;

using namespace std;
typedef long long ll;

ll ct, cnt;
ll fac[N], num[N];

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll multi(ll a, ll b, ll m) {
    ll ans = 0;
    a %= m;
    while (b) {
        if (b & 1) {
            ans = (ans + a) % m;
            b--;
        }
        b >>= 1;
        a = (a + a) % m;
    }
    return ans;
}

ll quick_mod(ll a, ll b, ll m) {
    ll ans = 1;
    a %= m;
    while (b) {
        if (b & 1) {
            ans = multi(ans, a, m);
            b--;
        }
        b >>= 1;
        a = multi(a, a, m);
    }
    return ans;
}

bool Miller_Rabin(ll n) {
    if (n == 2) return true;
    if (n < 2 || !(n & 1)) return false;
    ll m = n - 1;
    int k = 0;
    while ((m & 1) == 0) {
        k++;
        m >>= 1;
    }
    for (int i = 0; i < Times; i++) {
        ll a = rand() % (n - 1) + 1;
        ll x = quick_mod(a, m, n);
        ll y = 0;
        for (int j = 0; j < k; j++) {
            y = multi(x, x, n);
            if (y == 1 && x != 1 && x != n - 1) return false;
            x = y;
        }
        if (y != 1) return false;
    }
    return true;
}

ll pollard_rho(ll n, ll c) {
    ll i = 1, k = 2;
    ll x = rand() % (n - 1) + 1;
    ll y = x;
    while (true) {
        i++;
        x = (multi(x, x, n) + c) % n;
        ll d = gcd((y - x + n) % n, n);
        if (1 < d && d < n) return d;
        if (y == x) return n;
        if (i == k) {
            y = x;
            k <<= 1;
        }
    }
}

void find(ll n, int c) { //复杂度O(n^0.25)
    if (n == 1) return;
    if (Miller_Rabin(n)) {
        fac[ct++] = n;
        return;
    }
    ll p = n;
    ll k = c;
    while (p >= n) p = pollard_rho(p, c--);
    find(p, k);
    find(n / p, k);
}

int main() {
    ll n;
    cin >> n;
        ct = 0;
        find(n, 120);
        sort(fac, fac + ct);
        num[0] = 1;
        int k = 1;
        for (int i = 1; i < ct; i++) {
            if (fac[i] == fac[i - 1])
                ++num[k - 1];
            else {
                num[k] = 1;
                fac[k++] = fac[i];
            }
        }
        cnt = k;
    ll ans = 1;
     for (int i = 0; i < cnt; i++)
     ans *= (num[i] + 1);
     // cout << fac[i] << "^" << num[i] << " ";
     cout << ans << endl;
    return 0;
}