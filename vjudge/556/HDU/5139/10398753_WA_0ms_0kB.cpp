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
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
unordered_map<int, bool> mp;
unordered_map<int, ll> mp2;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        v.push_back(n);
        mp[n] = true;
    }
    sort(all(v));
    ll ans = 1, temp = 1;
    int maxn = v.back();
    cout << maxn << endl;
    REP(i, 1, maxn + 1) {
        ans = ans * temp % MOD;
        temp = temp * (i + 1) % MOD;
        if (mp.count(i)) {
            mp2[i] = ans;
        }
    }
    for (auto i : v) {
        cout << mp2[i] << endl;
    }
    return 0;
}