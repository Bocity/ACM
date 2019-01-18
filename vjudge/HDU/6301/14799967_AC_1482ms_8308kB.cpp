#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef bitset<1005> Bitset;
inline char gc() {
    static char buf[1 << 20], *h = buf, *t = buf;
    return (h == t && (t = (h = buf) + fread(buf, 1, 1 << 20, stdin), h == t) ? -1 : *h++);
}
template <typename T> inline bool read(T &x) {
    static int f;
    static char c;
    for (c = gc(), f = 1; !isdigit(c); c = gc()) {
        if (c == -1)
            return false;
        else if (c == 45)
            f = -1;
    }
    for (x = c - 48; isdigit(c = gc()); x = x * 10 + c - 48)
        ;
    return x *= f, true;
}
template <typename A, typename B> inline bool read(A &x, B &y) {
    return read(x) && read(y);
}
template <typename A, typename B, typename C> inline bool read(A &x, B &y, C &z) {
    return read(x) && read(y) && read(z);
}
int r[100020];
int a[100020];
set<int> qq;
int q[100020];
int n, m, t, li, ri;
int main() {
    read(t);
    while (t--) {
        read(n);
        read(m);
        qq.clear();
        memset(r, 0, sizeof r);
        memset(a, 0, sizeof a);
        memset(q, 0, sizeof q);
        int poss = 0;
        REP(i, 0, m) {
            read(li);
            read(ri);
            if (!r[li]) {
                q[poss] = li;
                poss++;
            }
            if (ri > r[li]) {
                r[li] = ri;
            }
        }
        int pos = 0;
        int sz = poss;
        int maxr = 0;
        REP(i, 1, n + 1) {
            if (!r[i]) {
                qq.insert(a[i]);
                continue;
            }
            if (a[r[i]]) {
                qq.insert(a[i]);
                continue;
            }
            if (a[i] == 0) {
                int pos = 1;
                REP(j, i, r[i] + 1) {
                    a[j] = pos;
                    pos++;
                    maxr = max(maxr, j);
                }
                li = i;
                qq.clear();
            } else {
                int j;
                for (j = maxr + 1; j < r[i] + 1; ++j) {
                    if (!qq.empty()) {
                        a[j] = *qq.begin();
                        qq.erase(a[j]);
                    } else
                        break;
                }
                int maxx = j - i + 1;  //可用数不够了，从最大值开始继续填数
                REP(k, j, r[i] + 1) {
                    a[k] = maxx++;
                }
                maxr = r[i];
                li = i;
            }
            qq.insert(a[i]);
        }
        REP(i, 1, n) {
            printf("%d ", a[i] == 0 ? 1 : a[i]);
        }
        printf("%d\n", a[n] == 0 ? 1 : a[n]);
    }
    return 0;
}