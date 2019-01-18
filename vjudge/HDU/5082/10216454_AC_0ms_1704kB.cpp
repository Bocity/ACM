#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define endl "\n"
#define maxn 2000000
#define N 1500015
#define MOD 998244353
#define mems(a, x) memset(a, (x), sizeof a)
typedef long long ll;
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    string s1, s2;
    while (cin >> s1 >> s2) {
        bool flag = false;
        REP(i, 0, s1.size()) {
            if (flag) cout << s1[i];
            if (s1[i] == '_') flag = true;
        }
        cout << "_";
        cout << "small";
        cout << "_";
        flag = false;
        REP(i, 0, s2.size()) {
            if (flag) cout << s2[i];
            if (s2[i] == '_') flag = true;
        }
        cout << endl;
    }
    return 0;
}
// 999999000000 1000000000000 10000000c