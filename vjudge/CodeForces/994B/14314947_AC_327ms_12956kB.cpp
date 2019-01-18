#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define pii pair<ll, ll>
#define MOD 1000000007
using namespace std;
/// using namespace __gnu_pbds;
typedef long long ll;
//__gnu_pbds::cc_hash_table<string, int> hash1;
//__gnu_pbds::gp_hash_table<string, int> hash2;
//__gnu_pbds::priority_queue<int> pq;
////__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
const int maxn = 100005;
ll l, r, x, y, k, m, n;
const long long mod = 1000000007;
ll p[maxn];
ll c[maxn];
ll ans[maxn];
struct node {
    ll p, c, id, ans;
    friend bool operator<(node x, node y) {
        return x.c < y.c;
    }
};
bool cmp(node x, node y) {
    return x.p > y.p;
}
priority_queue<node> q;
vector<node> qq;
vector<node> fuck;
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    REP(i, 0, n) {
        cin >> p[i];
    }
    REP(i, 0, n) {
        cin >> c[i];
    }
    REP(i, 0, n) {
        node tmp;
        tmp.p = p[i];
        tmp.c = c[i];
        tmp.id = i;
        q.push(tmp);
        qq.push_back(tmp);
    }
    sort(qq.begin(), qq.end(), cmp);
    REP(i, 0, n) {
        ll tmp = qq[i].p;
        ans[qq[i].id] += qq[i].c;
        int pos = 1;
        while (pos <= k) {
            if (q.empty()) break;
            node tmp2 = q.top();
            // cout << tmp2.p << endl;
            if (tmp2.p <= tmp) {
                if (tmp2.p != tmp) {
                    ans[qq[i].id] += tmp2.c;
                    pos++;
                }
                q.pop();
                fuck.push_back(tmp2);
            } else {
                q.pop();
            }
        }
        // cout << endl;
        for (auto &yy : fuck) {
            q.push(yy);
        }
        fuck.clear();
    }
    REP(i, 0, n) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}