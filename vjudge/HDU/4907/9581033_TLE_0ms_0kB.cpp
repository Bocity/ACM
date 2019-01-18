#include <cstring>
#include <iostream>
using namespace std;
#define endl "\n"
bool fl[1000005] = {0};
int main() {
    ios::sync_with_stdio(false);
    int T, n, m, a, q;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(fl, 0, sizeof fl);
        for (int i = 1; i <= n; i++) {
            cin >> a;
            fl[a] = true;
        }
        for (int i = 1; i <= m; i++) {
            cin >> q;
            for (int j = q; j <= 1000000; j++) {
                if (!fl[j]) {
                    cout << j << endl;
                    break;
                }
            }
        }
    }
    return 0;
}