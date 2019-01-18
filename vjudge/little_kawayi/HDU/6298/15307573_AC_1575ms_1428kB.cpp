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
const int maxn = 100000 + 10;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n % 3 == 0) cout << (n / 3) * (n / 3) * (n / 3) << endl;
        else if(n % 4 == 0) cout << (n / 4) * (n / 4) * (n / 2) << endl;
        else cout << "-1" << endl;
    }
    return 0;
}