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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll a, b;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        cout << 2 * max(a, b) + min(a, b) << endl;
    }
    return 0;
}