#include <bits/stdc++.h>
#define endl "\n"
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
typedef long long ll;
using namespace std;
ll n;
set<ll> q;
set<ll> p;
int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        bool flag = false;
        q.clear();
        p.clear();
        REP(i, 0, n) {
            ll x;
            cin >> x;
            q.insert(x);
        }
        REP(i, 0, n) {
            ll x;
            cin >> x;
            p.insert(x);
            if (q.find(x) == q.end()) {
                flag = true;
            }
        }
        if (flag || q.size() != p.size()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}