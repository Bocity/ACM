#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b;
    int t;
    cin >> t;
    int cas = 1;

    while (t--) {
        long long nn;
        __int128 n;
        cin >> nn;
        n = nn;
        n = 8 * n * n - 7 * n + 1;
        cout << "Case #" << cas++ << ": ";
        v.clear();
        while (n) {
            v.push_back(n % 10);
            n /= 10;
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            cout << v[i];
        }
        cout << endl;
    }
}