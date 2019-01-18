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
ll k, n, p, T;
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    n = p = 0;
    REP(i, 0, T) {
        cin >> n;
        if (n <= 35) p++;
    }
    cout << p;

    return 0;
}
