#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n) - 1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7;
const int maxn = 200 + 10;
struct node {
    string s;
    int k;
    int fi;
    int se;
};
bool cmp(const node &x, const node &y) {
    if(x.k == y.k) return x.s < y.s;
    return x.k > y.k;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin >> n) {
        node a[maxn];
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            cin >> a[i].s >> a[i].k;
        }
        sort(a, a + n, cmp);
        for(int i = 0; i < n; i++) {
            cout << a[i].s << ' ' << a[i].k << endl;
        }
        cin >> m;
        string ss;
        for(int i = 0; i < m; i++) {
            cin >> ss;
            if(ss == a[0].s) {
                cout << 1 << endl;
                continue;
            }
            int fi = 1, se = 0;
            for(int j = 1; j < n; j++) {
                if(a[j].k == a[j - 1].k) se++;
                else se = 0;
                if(a[j].s != ss) fi++;
                else {
                    if(se != 0) cout << fi - se + 1;
                    else cout << fi + 1;
                    if(se != 0) cout << ' ' << se + 1;
                    cout << endl;
                    continue;
                }
            }
        }
    }
    return 0;
}