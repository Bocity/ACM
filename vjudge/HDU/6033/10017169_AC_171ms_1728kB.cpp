#include <bits/stdc++.h>
#define endl "\n"
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
#define sqr(x) ((x) * (x))
typedef long long ll;
using namespace std;
ll n;
int main() {
    ios::sync_with_stdio(0);
    int t = 0;
    while (cin >> n) {
        cout << "Case #" << ++t << ": " << ll(n * log10(2)) << endl;
    }
    return 0;
}