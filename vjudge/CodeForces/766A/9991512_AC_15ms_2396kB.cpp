#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
#define endl "\n"
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << -1 << endl;
    } else {
        if (a.find(b) != string::npos)
            cout << a.size() << endl;
        else if (b.find(a) != string::npos)
            cout << b.size() << endl;
        else
            cout << max(a.size(), b.size()) << endl;
    }
    return 0;
}