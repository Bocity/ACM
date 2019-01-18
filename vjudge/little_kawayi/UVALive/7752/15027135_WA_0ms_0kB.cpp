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
int a[maxn], b[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n) {
        int rcd[maxn * 2];
        int k = 0, ans = 0;
        memset(rcd, 0, sizeof(rcd));
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            if(a[i] != b[i]) {
                if(b[i] == 0 && a[i] != 0) ans += 1;
                if(b[i] != 0 && a[i] != 0) ans += 2;
                if(b[i] != 0 && a[i] == 0) ans += 1;
                // rcd[k++] = a[i];
                // rcd[k++] = b[i];
            }
        }
        sort(rcd, rcd + k);
        // for(int i = 0; i < k; i++) cout << rcd[i] << ' ';
        // cout << endl;
        // for(int i = 1; i < k; i++) {
        //     if(rcd[i] != 0) {
        //         ans++;
        //     }
        // }
        cout << ans << endl;
    }
    return 0;
}