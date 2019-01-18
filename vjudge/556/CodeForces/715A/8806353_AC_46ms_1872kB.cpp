#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int solve() {}
int main() {
    ios::sync_with_stdio(false);
    ll nn, rem = 2, l = 1;
    while (cin >> nn) {
        rem = 2, l = 1;
        while (nn--) {
            cout << l * (l + 1) * (l + 1) - rem / l << endl;
            rem = l * (l + 1);
            l++;
        }
    }
    return 0;
}