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
typedef long long ll;
typedef pair<int, vector<int>> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int a[2000], b[2000];
const int N = 1100;
vector<pii> seqs;
int n, m;
int LIS() {
    int pos, len = 0;
    seqs.clear();
    seqs.push_back(pii(0, vector<int>()));
    REP(ii, 0, n) {
        int i = a[ii], j = b[ii];
        for (int cnt = 0; cnt < seqs.size(); cnt++) {
            auto v = seqs[cnt].second, _v = seqs[cnt].second;
            auto chan = seqs[cnt].first;
            pos = lower_bound(all(v), i) - v.begin();
            // cout << pos << endl << flush;
            if (pos == v.size())
                v.push_back(i);
            else
                v[pos] = i;
            seqs[cnt].second = v;
            len = max(len, pos + 1);

            if (chan < m) {
                pos = lower_bound(all(_v), j) - _v.begin();
                // cout << pos << endl << flush;
                len = max(len, pos + 1);
                if (pos == _v.size()) {
                    if (j < i)
                        _v.push_back(j);
                    else
                        continue;
                } else if (_v[pos] != j)
                    _v[pos] = j;
                else
                    continue;
                seqs.push_back(pii(chan + 1, _v));
            }
        }
    }
    // cout << seqs.size() << endl;
    return len;
}
int main() {
    ios::sync_with_stdio(false);
    int t, temp;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        REP(i, 0, n) {
            cin >> a[i] >> b[i];
        }
        cout << LIS() << endl;
    }
    return 0;
}