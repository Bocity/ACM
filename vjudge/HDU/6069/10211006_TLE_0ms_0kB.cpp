#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define endl "\n"
#define maxn 2000000
#define N 1500015
#define MOD 998244353
#define mems(a, x) memset(a, (x), sizeof a)
typedef long long ll;
using namespace std;
bool vis[maxn];
ll prime[maxn];
ll len = 0;
ll num[maxn];
ll pp[maxn][20];
bool v[maxn];
ll T, L, R, k, ans;
bool flag[maxn];
void screen() {
    for (long long i = 2; i < N; i++) {
        if (!vis[i]) prime[len++] = i;
        for (int j = 0; j < len && i * prime[j] < N; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    screen();
    while (T--) {
        memset(num, 0, sizeof num);
        memset(pp, 0, sizeof pp);
        memset(v, 0, sizeof v);
        memset(flag, 0, sizeof flag);
        ans = 0;
        k = 0;
        cin >> L >> R >> k;
        for (ll i = 0; prime[i] * prime[i] <= R; i++) {
            ll pos = L - L % prime[i] + prime[i];
            if ((L % prime[i]) == 0) pos = L;
            if (L < prime[i]) pos = prime[i];
            for (ll j = pos; j <= R; j += prime[i]) {
                pp[j - L][num[j - L]++] = prime[i];
                v[j - L] = true;
            }
        }
        cout << num[10] << endl;
        for (ll i = L; i <= R; i++) {
            ll anss = 1;
            if (i == 1) {
                ans++;
                continue;
            }
            if (v[i - L]) {
                ll x = i;
                for (ll j = 0; j < num[i - L]; j++) {
                    ll p = 0;
                    while (x % pp[i - L][j] == 0) {
                        p++;
                        x /= pp[i - L][j];
                    }
                    anss = anss * (k * p + 1) % MOD;
                }
                if (x != 1) {
                    anss = anss * (k + 1) % MOD;
                }
                // cout << i << " " << anss << endl;
                ans += anss % MOD;
            } else {
                ans += k + 1 % MOD;
                //  cout << i << " " << k + 1 << endl;
            }
        }
        cout << ans % MOD << endl;
    }
    return 0;
}
// 999999000000 1000000000000 10000000