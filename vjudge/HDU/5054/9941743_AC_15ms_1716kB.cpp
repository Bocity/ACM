#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define PER(i, n) for (int i = n - 1; i >= 0; i--)
#define DE cout << '---------' << endl
using namespace std;
long long N, M, x, y;
int main() {
    ios::sync_with_stdio(0);
    while (cin >> N >> M >> x >> y) {
        if (x * 2 == N && y * 2 == M) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}