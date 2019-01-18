#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll mod = 1e9+7;
const int maxn = 100000 + 10;
ll dp[maxn];
ll LIS(ll arr[], ll n) {
    ll lis = 1;
    dp[1] = arr[0];
    for(ll i = 1; i < n; i++){
        ll pos = upper_bound(dp + 1, dp + lis + 1, arr[i]) - dp;    
        dp[pos] = arr[i];
        lis = max(lis, pos);
    }
    return lis;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t, x, n, f[maxn], r[maxn];
    cin >> t;
    while(t--) {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        ll k = 0;
        for(int i = 0; i < n; i++) cin >> f[i];
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(f[i] == 1) r[k++] = x;
        }
        // for(int i = 0; i < k; i++) cout << r[i] << ' ';
        // cout << endl;
        ll len = LIS(r, k);
        // cout << len << ' ' << k << endl;
        if(len >= k - 1) cout << "#laughing_arjun" << endl;
        else cout << "#itsnot_arjun" << endl;
    }
    return 0;
}