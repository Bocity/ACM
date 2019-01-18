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
const int maxn = 200000 + 10;
int n, m, a[maxn];
bool ck(int x) {
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        if(tmp >= a[i]) tmp++;
        else if(x > 0) x--, tmp++;
        if(tmp == m) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = m, ans = m, mid;
    while(l < r) {
        mid = l + (r - l) / 2;
        if(ck(mid)) {
            r = mid;
            ans = mid;
            // cout << "T " << ans << " " << l << " " << r << endl;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
7 4
2 1 3 3 4 2 3
7 4
2 1 3 3 4 3 2
*/