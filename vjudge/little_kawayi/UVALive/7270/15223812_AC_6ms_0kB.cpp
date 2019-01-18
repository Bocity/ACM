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
const ll mod = 1e9+7;
const int maxn = 10000 + 10;
int x[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n) {
        char c;
        int k = 0, ans = 1;
        for(int p = 0; p < n; p++) {
            cin >> c;
            if(c == 'C' || c == 'B') cin >> x[k++];
            if(c == 'S') x[k++] = 0;
        }
        for(int i = 1; i < k; i++) {
            if(x[i - 1] == 0) ans++;
            else if(x[i] <= x[i - 1]) ans++;
        }
        // for(int i = 0; i < k; i++) cout << x[i] << ' ';
        // cout << endl;
        if(n == 0) ans = 0;
        cout << ans << endl;
    }
    return 0;
}