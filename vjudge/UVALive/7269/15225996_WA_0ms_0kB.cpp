#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
const int maxn = 10005;
ll n, m, k;
const long long mod = 1000000007;
vector<pii> vis1, vis2, vis3;
int main() {
    ios::sync_with_stdio(0);
    int nn;
    while (cin >> nn) {
        if (nn == 1) {
            cout << "1 1" << endl;
            cout << "1 1" << endl;
            continue;
        } else if (nn == 2) {
            cout << "1 3" << endl;
            cout << "1 1" << endl;
            cout << "1 2 1 3" << endl;
            continue;
        } else {
            vis1.clear();
            vis2.clear();
            nn++;
            if (nn % 2) {
                cout << (nn - 1) / 2 << " " << nn << endl;
            } else {
                cout << nn / 2 << " " << nn - 1 << endl;
            }
            int n = 1, m = 3;
            vis1.push_back(pii(1, 1)); //上两个
            vis2.push_back(pii(1, 1));
            vis2.push_back(pii(1, 2)); //上一个
            vis2.push_back(pii(1, 3));
            for (int i = 3; i <= nn - 1; ++i) {
                if (i % 2) {
                    n++;
                    swap(vis1, vis2);
                    for (int k = 1; k <= m - 1; ++k) {
                        vis2.push_back(pii(n, k));
                    }
                    vis2.push_back(pii(n, m));
                    vis2.push_back(pii(n - 1, m));
                    vis2.push_back(pii(n - 1, m - 1));
                    for (int k = n - 2; k >= 1; --k) {
                        vis2.push_back(pii(k, m - 1));
                    }
                    for (int k = 1; k <= n - 2; ++k) {
                        vis2.push_back(pii(k, m));
                    }
                } else {
                    vis1 = vis2;
                    for (int k = 1; k <= n; ++k) {
                        vis2.push_back(pii(k, m + 1 + (k + 1) % 2));
                        vis2.push_back(pii(k, m + 1 + (k + 2) % 2));
                    }
                    m += 2;
                }
            }
            int pos = 0;
            for (int i = 1; i <= nn - 1; ++i) {
                for (int j = 1; j <= i; ++j) {
                    cout << vis2[pos].first << " " << vis2[pos].second << " \n"[j == i];
                    pos++;
                }
            }
        }
    }
    return 0;
}
