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
int rcd[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, m = 0; 
    cin >> n;
    for(int i = 0; i < n ;i++) {
        cin >> x;
        rcd[x]++;
        m = max(m, x);
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        if(rcd[i] >= 2) {
            ans += rcd[i] / 2;
        }
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}