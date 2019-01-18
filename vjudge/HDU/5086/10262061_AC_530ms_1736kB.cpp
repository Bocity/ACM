#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
int t;
long long a;
void stay() {
    long long ans = 0, n;
    cin >> n;
    REP(i, 0, n) {
        cin >> a;
        ans = ans + a * (i + (n - i - 1) + i * (n - i - 1) % MOD + 1) % MOD;
    }
    cout << ans % MOD << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) stay();
    return 0;
}