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
const int maxn = 101000;
const int N = 1100;
int seq[N];
int LIS(vector<int> a) {
    int pos, len = 0;
    for (auto i : a) {
        pos = lower_bound(seq, seq + len, i) - seq; // 上升
        // pos = upper_bound(seq, seq + len, i) - seq; // 不下降
        seq[pos] = i;
        len = max(len, pos + 1); // 是否成为最大的元素使 LIS 增长，如无，则保留原来的长度
    }
    return len;
}
int LIS2(vector<int> a) {
    int pos, len = 0;
    for (auto i : a) {
        // pos = lower_bound(seq, seq + len, i) - seq; // 上升
        pos = upper_bound(seq, seq + len, i) - seq; // 不下降
        seq[pos] = i;
        len = max(len, pos + 1); // 是否成为最大的元素使 LIS 增长，如无，则保留原来的长度
    }
    return len;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int n, temp;
    vector<int> v;
    while (t--) {
        ll ans = 0;
        cin >> n;
        v.clear();
        REP(i, 0, n) {
            cin >> temp;
            v.push_back(temp);
        }
        int a = LIS(v);
        int b = LIS2(v);
        if (b > a)
            cout << a << endl;
        else
            cout << a - 1 << endl;
    }
}