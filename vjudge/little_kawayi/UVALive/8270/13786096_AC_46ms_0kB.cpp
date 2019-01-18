#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f3f;

const int Times = 10;
const int N = 5500;
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

void find(ll n, int c) { //澶嶆潅搴(n^0.25)
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
    int t;
    cin >> t;
    while (t--)
	{
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
        ll ans = 0;
        for (int i = 0; i < cnt; i++)
        {
        	ll sum = num[i];
        	for (int j = 0; j < cnt; j++)
        		if (j != i)
        			sum *= num[j] + 1;
        	ans += sum;
    	}
        cout << ans << endl;
    }
    return 0;
}