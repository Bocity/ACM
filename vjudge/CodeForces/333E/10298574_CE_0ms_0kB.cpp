#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); (i) < (n); i++)
#define PER(i, x, n) for (int i = (n) -1; (i) >= (x); i--)
#define DE puts("---------")
#define sqr(x) ((x) * (x))
using namespace std;
typedef long long ll;
typedef bitset<4005> Bitset;

struct edge {
    double dis;
    int x, y;
} e[10000000];
int a[4000], b[4000];
Bitset temp[4005];
inline double dis(int x, int y) {
    return sqrt(1.0 * sqr(a[x] - a[y]) + 1.0 * sqr(b[x] - b[y]));
}
void stay(int n) {
    double ans = 0;
    REP(i, 0, n) {
        double x, y;
        cin >> x >> y;
        a[i] = x;
        b[i] = y;
    }
    int ec = 0;
    REP(i, 0, n) {
        REP(j, i + 1, n) {
            e[ec].dis = dis(i, j);
            e[ec].x = i;
            e[ec].y = j;
            ec++;
        }
    }
    sort(e, e + ec, [](edge x, edge y) { return x.dis > y.dis; });
    // REP(i, 0, ec) {
    //     cout << e[i].dis << endl;
    // }
    // DE;
    REP(i, 0, ec) {
        if ((temp[e[i].x] & temp[e[i].y]).any()) {
            ans = e[i].dis;
            break;
        }
        temp[e[i].y].set(e[i].x);
        temp[e[i].x].set(e[i].y);
    }
    cout << fixed << setprecision(10) << ans / 2 << endl;
    return;
}
int n;
int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    stay(n);
    return 0;
}
