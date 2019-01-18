#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
#define endl "\n"
using namespace std;
int n;
long long a[100005];
int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    REP(i, 0, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    bool flag = false;
    PER(i, 3, n) if (a[i - 3] + a[i - 2] > a[i - 1]) {
        flag = true;
    }
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}