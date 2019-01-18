#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define PER(i, x, n) for (long long i = (n); i >= (x); i--)
#define endl "\n"
#define mems(a, x) memset(a, (x), sizeof a)
using namespace std;
typedef long long ll;
const int maxn = 10000;
typedef bitset<905> Bitset;
Bitset q[2000];
int n, m, y, t;
int x;
void stay(int n) {
    REP(i, 0, 1500) {
        q[i].reset();
    }
    REP(i, 0, n) {
        cin >> m;
        REP(j, 0, m) {
            cin >> x;
            q[x].set(i);
        }
    }
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << (((q[x] & q[y]).count() >= 1) ? "Yes" : "No") << endl;
    }
}
int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        stay(n);
    }
    return 0;
}