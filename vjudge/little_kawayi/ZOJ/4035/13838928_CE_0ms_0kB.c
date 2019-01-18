#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
const int maxn = 100 + 10;
struct node {
    int num;
    string s;
};
bool cmp(const node &a, const node &b) {
    if(a.num == b.num) return a.s < b.s;
    return a.num > b.num;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        node x[maxn];
        for(int i = 0; i < n; i++) cin >> x[i].s >> x[i].num;
        sort(x, x + n, cmp);
        ll ans = 0;
        for(int i = 0; i < m; i++) {
            ans += (m - i) * x[i].num;
        }
        cout << ans << ' ';
        for(int i = 0; i < m; i++) {
            cout << x[i].s;
            if(i == m - 1) cout << endl;
            else cout << ' ';
        }
    }
    return 0;
}