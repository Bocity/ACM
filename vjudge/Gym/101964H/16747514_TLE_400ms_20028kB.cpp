#include <bits/stdc++.h>
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
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const int maxn = 200050;
ll n, m, k;
const long long mod = 1000000007;
// int a[10000];
map<pii, int> q;
struct node {
    int num;
};
int c[maxn];
int r[maxn];
bool operator<(const node &x, const node &y) {
    return r[x.num] < r[y.num];
}

priority_queue<node> pq;
vector<int> e[maxn];
vector<int> an;
void stay() {
    q.clear();
    while (!pq.empty()) pq.pop();
    an.clear();
    memset(c, 0, sizeof c);
    memset(r, 0, sizeof r);
    cin >> n >> m;
    for (int i = 0; i < n + 1; ++i) e[i].clear();
    int x, y;
    REP(i, 0, m) {
        cin >> x >> y;
        if (!q[pii(x, y)]) {
            r[y]++;
            c[x]++;
            e[y].push_back(i + 1);
            q[pii(x, y)]++;
        }
    }
    REP(i, 1, n + 1) {
        node tmp;
        tmp.num = i;
        pq.push(tmp);
    }
    int ans = 0;
    int anss = 0;
    while (anss < n / 4 + 1 && !pq.empty()) {
        node tmp = pq.top();
        anss++;
        ans += r[tmp.num];
        an.push_back(tmp.num);
        pq.pop();
        if (ans - anss > n / 2 && anss >= n / 4 + 1) {
            break;
        }
    }
    cout << anss << endl;
    // for (auto &x : an) {
    //     cout << e[x][0] << " ";
    // }
    // cout << endl;
    int sz = an.size();
    for(int i = 0; i < sz; ++i){
        cout << e[an[i]][0] << " \n"[i == sz - 1];
    }
}
int t;
int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        stay();
    }
    return 0;
}

// 2
// 3 3
// 1 2
// 2 3
// 3 1
// 4 4
// 1 2
// 2 3
// 3 4
// 4 1 