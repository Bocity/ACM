#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6;
ll qpow(ll a, ll b, ll p) { // return a^b %p
    ll t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
vector<short> v;
int main() {
    ios::sync_with_stdio(false);
    int t, n, temp, m;
    string str;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        v.clear();
        int cnt = 0;
        REP(i, 0, m) {
            cin >> str >> temp;
            if (str == "O") {
                if (temp == 3)
                    cnt++;
                else
                    v.push_back(temp);
            } else {
                ll now = temp;
                PER(i, 0, v.size()) {
                    if (v[i] == 1) {
                        if (now <= (n + 1) / 2) {
                            now = 1 + (now - 1) * 2;
                        } else {
                            now -= (n + 1) / 2;
                            now *= 2;
                        }
                    } else {
                        now = n - now + 1;
                    }
                }
                REP(i, 0, cnt) {
                    now = now * now % MOD;
                }
                cout << now << endl;
            }
        }
    }
}