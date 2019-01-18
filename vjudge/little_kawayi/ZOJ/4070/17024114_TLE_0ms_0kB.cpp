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
int num[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    ll x, k;
    cin >> t;
    while(t--) {
        cin >> x >> k;
        ll ans = 0;
        ll tmp = x;
        if(k == 0) {
            cout << x << endl;
            continue;
        }
        while(tmp) {
            ans += num[tmp % 10];
            tmp /= 10;
        }
        k--;
        if(k == 0) {
            cout << ans << endl;
            continue;
        }
        // cout << "ans " << ans << endl;
        while(k) {
            if(ans >= 10) {
                tmp = ans, ans = 0;
                while(tmp) {
                    ans += num[tmp % 10];
                    tmp /= 10;
                }
            }
            else {
                ans = num[ans];
            }
            k--;
            if(ans == 0) break;
        }
        if(k % 2) cout << k % 2 << endl;
        else cout << ans << endl;
    }
    return 0;
}