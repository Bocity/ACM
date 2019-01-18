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
const int maxn = 100000 + 10;
int a[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        cin >> a[0];
        for(int i = 1; i < n; i++) {
            cin >> a[i];
            ans += a[i] - a[i - 1] - 1;
        }
        cout << ans - min(a[1] - a[0], a[n - 1] - a[n - 2]) + 1 << endl;
    }
    return 0;
}