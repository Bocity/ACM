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
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
#define N 100010 // range to screen

int main() {
    ios::sync_with_stdio(false);
    ll a, b;
    string s;
    while (cin >> a >> s) {
        b = 0;
        REP(i, 0, s.size()) {
            b = b * 10 + s[i] - '0';
        }
        ll temp = max(b, (ll) pow(10, s.size() - 1));
        ll st = a;
        if (temp > a) {
            st = (temp + a - 1) / a * a;
        }
        // cout << st << endl;
        for (;; st += a) {
            ostringstream o;
            o << st;
            if (o.str().find(s) != string::npos) {
                break;
            }
        }
        cout << st / a << endl;
    }
    return 0;
}