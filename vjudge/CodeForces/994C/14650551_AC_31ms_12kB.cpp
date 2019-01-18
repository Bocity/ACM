#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
using namespace std;
int a[15];
int b[15];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ansx = 0, ansy = 0;
    REP(i, 0, 8) {
        cin >> b[i];
        if (i % 2 == 0)
            ansx += b[i];
        else
            ansy += b[i];
    }
    b[8] = ansx / 4;
    b[9] = ansy / 4;
    ansx = 0, ansy = 0;
    REP(i, 0, 8) {
        cin >> a[i];
        if (i % 2 == 0)
            ansx += a[i];
        else
            ansy += a[i];
    }
    a[8] = ansx / 4;
    a[9] = ansy / 4;
    bool flag = 0;
    int tmp1, tmp2;
    for (int p = 1; p <= 2; ++p) {
        for (int i = 0; i < 10; i += 2) {
            int minx = 200, miny = 200, maxx = -200, maxy = -200;
            for (int j = 0; j < 10; j += 2) {
                minx = min(minx, b[j]);
                miny = min(miny, b[j + 1]);
                maxx = max(maxx, b[j]);
                maxy = max(maxy, b[j + 1]);
            }
            flag |= (a[i] >= minx && a[i] <= maxx && a[i + 1] <= maxy && a[i + 1] >= miny);
            if(flag){
                cout << "YES" << endl;
                return 0;
            }
            tmp1 = a[i] + a[i + 1], tmp2 = a[i] - a[i + 1];
            a[i] = tmp1, a[i + 1] = tmp2;
        }
        if (p == 2) break;
        for (int i = 0; i < 10; i += 2) {
            tmp1 = b[i] + b[i + 1], tmp2 = b[i] - b[i + 1];
            b[i] = tmp1, b[i + 1] = tmp2;
        }
        REP(i, 0, 10) {
            tmp1 = a[i];
            a[i] = b[i];
            b[i] = tmp1;
        }
    }

    cout << "NO"<< endl;
    return 0;
}
