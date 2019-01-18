#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
int tot = 0;
#define N 1000100 // range to screen
ll prime[N];
bool vis[N] = {true, true};
void screen() {
    for (long long i = 2; i < N; i++) {
        if (!vis[i]) prime[tot++] = i;
        for (int j = 0; j < tot && i * prime[j] < N; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
int cnt[N];
int mp[N][100];
int main() {
    ios::sync_with_stdio(false);
    screen();
    ll t, l, r, k, temp, s;
    cin >> t;
    while (t--) {
        cin >> l >> r >> k;
        ll ans = 0;
        mems(cnt, 0);
        int sz = r - l;
        REP(ii, 0, tot) {
            int i = prime[ii];
            if ((ll) i * i > r) break;
            if (l % i == 0) {
                s = l;
            } else
                s = l / i * i + i;
            int ss = s - l;
            for (; ss <= sz; ss += i) {
                mp[ss][cnt[ss]++] = i;
            }
        }
        REP(i, 0, r - l + 1) {
            temp = 1;
            s = i + l;
            int j;
            REP(ii, 0, cnt[i]) {
                j = mp[i][ii];
                ll fuck = 0;
                while (s % j == 0) s /= j, fuck++;
                temp = temp * (k * fuck + 1) % MOD;
            }
            if (s != 1) {
                temp = temp * (k + 1) % MOD;
            }
            ans = (ans + temp) % MOD;
        }
        cout << ans << endl;
    }
}