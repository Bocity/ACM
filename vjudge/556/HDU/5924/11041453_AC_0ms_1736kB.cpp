#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int mp[50][50];
bool vis[50][50];
int _x[] = {0, 1};
int _y[] = {1, 0};
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int ccnt = 1;
    cin >> t;
    ll a, b;
    while (t--) {
        cin >> a >> b;

        cout << "Case #" << ccnt++ << ":" << endl;
        if (a == b) {
            cout << 1 << endl;
            cout << a << " " << b << endl;
        } else {
            cout << 2 << endl;
            cout << a << " " << b << endl;
            cout << b << ' ' << a << endl;
        }
    }
}