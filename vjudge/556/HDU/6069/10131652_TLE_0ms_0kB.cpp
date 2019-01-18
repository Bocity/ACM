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
vector<long long> prime;
#define N 1000100 // range to screen
bool vis[N] = {true, true};
void screen() {
    for (long long i = 2; i < N; i++) {
        if (!vis[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < N; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
vector<int> mp[N];
int main() {
    ios::sync_with_stdio(false);
    screen();
    ll t, l, r, k, temp, cnt, s;
    cin >> t;
    while (t--) {
        cin >> l >> r >> k;
        ll ans = 0;
        REP(i, 0, r - l + 1) {
            mp[i].clear();
        }
        for (auto i : prime) {
            if (i > r) break;
            if (l % i == 0) {
                s = l;
            } else
                s = l / i * i + i;
            for (; s <= r; s += i) {
                mp[s - l].push_back(i);
            }
        }
        REP(i, 1, r - l + 1) {
            temp = 1;
            for (auto j : mp[i]) {
                cnt = 0;
                s = i + l;
                while (s % j == 0) s /= j, cnt++;
                temp *= k * cnt + 1;
            }
            if (temp == 1) temp = k + 1;
            ans = (ans + temp) % MOD;
        }
        cout << ans + 1 << endl;
    }
}