#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll t, n;
string s, S[20000];
ll mp[100000][20];
bool cmp(string x, string y) {
    return x.length() > y.length();
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        memset(mp, 0, sizeof(mp));
        cin >> n;
        bool flag = false;
        for (int i = 1; i <= n; i++) cin >> S[i];
        sort(S + 1, S + 1 + n, cmp);
        // for (int i = 1; i <= n; i++) cout << S[i] << "\n";
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            ll p = 0;
            for (int j = 0; j <= S[i].length() - 1; j++) {
                int t = S[i][j] - '0';
                if (mp[p][t] == 0) {
                    sum++;
                    mp[p][t] = sum;
                    p = sum;
                } else {
                    if (j == S[i].length() - 1) flag = true;
                    p = mp[p][t];
                    continue;
                }
            }
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}