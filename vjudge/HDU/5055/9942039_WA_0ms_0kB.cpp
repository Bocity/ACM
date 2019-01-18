#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define PER(i, n) for (int i = (n) -1; i >= 0; i--)
#define DE cout << '---------' << endl
using namespace std;
long long N, M, x, y, n;
long long a[1000];
bool cmp(ll x, ll y) {
    return x > y;
}
int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        int p = 0;
        long long min = 100000, minn = -1;
        REP(i, n) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 && min > a[i]) {
                minn = i;
                min = a[i];
            }
        }
        if (minn == -1) {
            cout << "-1" << endl;
            continue;
        }
        swap(a[minn], a[n - 1]);
        sort(a, a + n - 1, cmp);
        REP(i, n) {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}