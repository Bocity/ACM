#include <bits/stdc++.h>
#define endl "\n"
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
typedef long long ll;
using namespace std;
ll n, a, b;
string s;
int main() {
    // ios::sync_with_stdio(0);
    while (getline(cin, s)) {
        bool flag = false;
        cin >> a >> b;
        char pp = getchar();
        int size = s.size();
        REP(i, 1, size) {
            if (s[i] < '0' || s[i] > '9') {
                flag = true;
            }
        }
        // cout << "--" << s << "--" << a << "--" << endl;
        if ((s[0] == '-' && size == 1) || (s[0] == '-' && s[1] == '0')) flag = true;
        if (s[0] == '0' && size > 1) flag = true;
        if (size > 12) flag = true;
        if ((s[0] < '0' || s[0] > '9') && s[0] != '-') flag = true;
        ll p = 0, f = 1, n = 0;
        if (flag) {
            cout << "NO" << endl;
        } else {
            char ch = s[0];
            if (ch == '-') {
                f = -1;
                REP(i, 1, size) {
                    ch = s[i];
                    n = n * 10 + ch - '0';
                }
            } else {
                REP(i, 0, size) {
                    ch = s[i];
                    n = n * 10 + ch - '0';
                }
            }
            n = n * f;
            if (n < a || n > b)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}