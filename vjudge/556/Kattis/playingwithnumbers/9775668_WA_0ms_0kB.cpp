#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 60000;
struct node {
    int a, b;
} sma[5], lar[5];

bool cmp(node x, node y) {
    return (x.a * log(2.0) + x.b * log(3.0)) < (y.a * log(2.0) + y.b * log(3.0));
}

pii a[maxn], b[maxn];
pii aj[maxn], bj[maxn];
int aa[maxn], bb[maxn];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    REP(i, 1, n + 1) {
        cin >> aa[i] >> bb[i];
        a[i] = pii(aa[i], bb[i]);
        b[i] = pii(bb[i], aa[i]);
        aj[i] = pii(aa[i], -bb[i]);
        bj[i] = pii(bb[i], -aa[i]);
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(aj + 1, aj + n + 1);
    sort(bj + 1, bj + n + 1);

    int num_min, num_max, pos;
    REP(i, 1, n + 1) {
        pii large = pii(-1, -1), small = pii(-1, -1);
        num_min = i - 1;
        num_max = n - i;
        if (num_min > 1) {
            small.first = a[1].first;
            small.second = b[1].first;
        } else if (num_min == 0) {
            small.first = a[n].first;
            small.second = b[n].first;
        } else {
            sma[1].a = a[0].first;
            sma[1].b = a[0].second;

            sma[2].a = 0;
            sma[2].b = 0;
            pos = lower_bound(aj + 1, aj + n + 1, pii(aj[n].first - 1, 1000)) - (aj + 1) - 1;
            if (pos > 0) {
                sma[2].a = aj[pos + 1].first;
                sma[2].b = -aj[pos + 1].second;
            }

            sma[3].b = b[0].first;
            sma[3].a = b[0].second;

            sma[4].b = 0;
            sma[4].a = 0;
            pos = lower_bound(bj + 1, bj + n + 1, pii(bj[n].first - 1, 1000)) - (bj + 1) - 1;
            if (pos > 0) {
                sma[4].b = bj[pos + 1].first;
                sma[4].b = -bj[pos + 1].second;
            }

            sort(sma + 1, sma + 5, cmp);
            small.first = sma[1].a;
            small.second = sma[1].b;
        }

        if (num_max > 1) {
            large.first = a[n].first;
            large.second = b[n].first;
        } else if (num_max == 0) {
            large.first = a[1].first;
            large.second = b[1].first;
        } else {
            lar[1].a = a[n].first;
            lar[1].b = a[n].second;

            lar[2].a = 0;
            lar[2].b = 0;
            pos = upper_bound(aj + 1, aj + n + 1, pii(aj[1].first, 1000)) - (aj + 1);
            if (pos > 0) {
                lar[2].a = aj[pos + 1].first;
                lar[2].b = -aj[pos + 1].second;
            }

            lar[3].b = b[n].first;
            lar[3].a = b[n].second;

            lar[4].b = 0;
            lar[4].a = 0;
            pos = upper_bound(bj + 1, bj + n + 1, pii(bj[1].first, 1000)) - (bj + 1);
            if (pos > 0) {
                lar[4].b = bj[pos + 1].first;
                lar[4].a = -bj[pos + 1].second;
            }
            sort(lar + 1, lar + 5, cmp);
            large.first = lar[4].a;
            large.second = lar[4].b;
        }
        cout << large.first << " " << large.second << " " << small.first << " " << small.second << endl;
    }
    return 0;
}