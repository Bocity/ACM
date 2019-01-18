#include <bits/stdc++.h>
#define endl "\n"
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
#define sqr(x) ((x) * (x))
#define pii pair<char, int>
#define PI acos(-1.0)
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll k, n, T, m, ans;
ll p[1000005];
bool pan(ll x) {
    vector<int> q;
    while (x > 0) {
        q.push_back(x % 10);
        x /= 10;
    }
    if ((q.size()) & 1) {
        REP(i, 0, (q.size() - 1) / 2) {
            if (q[i] != q[q.size() - 1 - i] || (i > 0 && q[i] <= q[i - 1])) {
                // cout << "fuck";
                return false;
            }
        }
        if (q[(q.size() - 1) / 2] <= q[(q.size() - 1) / 2 + 1]) {
            return false;
        }
    } else {
        REP(i, 0, (q.size() - 1) / 2 + 1) {
            if (q[i] != q[q.size() - 1 - i] || (i > 0 && q[i] <= q[i - 1])) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    p[0] = 0;
    // cout << pan(12321);
    // cout << pan(1221);
    REP(i, 1, 1000001) {
        if (pan(i)) {
            p[i] = p[i - 1] + 1;
        } else {
            p[i] = p[i - 1];
        }
    }
    cin >> T;
    while (T--) {
        cin >> n;
        cout << p[(int) (pow(10, n) + 0.5)];
    }
    return 0;
}