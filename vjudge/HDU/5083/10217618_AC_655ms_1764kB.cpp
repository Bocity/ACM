#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define endl "\n"
#define maxn 2000000
#define N 1500015
#define MOD 998244353
#define mems(a, x) memset(a, (x), sizeof a)
typedef long long ll;
using namespace std;
string ss[100] = {"ADD", "SUB", "DIV", "MUL", "MOVE", "SET"};
string sss[100] = {"000001", "000010", "000011", "000100", "000101", "000110"};

string tra(int x) {
    string ans = "00000";
    int pos = 4;
    while (x > 0) {
        ans[pos] += (x % 2);
        x /= 2;
        pos--;
    }
    return ans;
}
int main() {
    // ios::sync_with_stdio(0);
    int op;
    string s1, s2, s3;
    while (cin >> op) {
        if (op) {
            cin >> s1;
            char aa, bb;
            int a, b;
            bool flag = false;
            REP(i, 0, 6) {
                if (s1 == ss[i]) {
                    flag = true;
                    s2 = sss[i];
                    break;
                }
            }
            if (!flag) {
                cin >> s2;
                cout << "Error!\n";
                continue;
            }
            if (s1 != ss[5]) {
                char ch = getchar();
                scanf("%c%d,%c%d", &aa, &a, &bb, &b);
                // cout << aa << a << "," << bb << b << endl;
                cout << s2 << tra(a) << tra(b) << endl;
            } else {
                char ch = getchar();
                scanf("%c%d", &aa, &a);
                cout << s2 << tra(a) << "00000" << endl;
                continue;
            }
        } else {
            cin >> s1;
            bool flag = false;
            REP(i, 0, 6) {
                if (s1.substr(0, 6) == sss[i]) {
                    flag = true;
                    s2 = ss[i];
                    break;
                }
            }
            if (!flag) {
                cout << "Error!\n";
                continue;
            }
            if (s1.substr(0, 6) == sss[5]) {
                if (s1.substr(11, 5) == "00000") {
                    bool fa = false;
                    REP(i, 1, 32) {
                        if (tra(i) == s1.substr(6, 5)) {
                            cout << s2 << " R" << i << endl;
                            fa = true;
                            break;
                        }
                    }
                    if (!fa) {
                        cout << "Error!\n";
                        continue;
                    }
                } else {
                    cout << "Error!\n";
                    continue;
                }
            } else {
                bool flag = false;
                int ii = 0, jj = 0;
                REP(i, 1, 32) {
                    if (tra(i) == s1.substr(6, 5)) {
                        flag = true;
                        ii = i;
                    }
                }
                if (!flag) {
                    cout << "Error!\n";
                    continue;
                }
                flag = false;
                REP(i, 1, 32) {
                    // cout << "----";
                    if (tra(i) == s1.substr(11, 5)) {
                        //  cout << i;
                        flag = true;
                        jj = i;
                        break;
                    }
                }
                if (!flag) {
                    cout << "Error!\n";
                } else {
                    cout << s2 << " R" << ii << ",R" << jj << endl;
                }
            }
        }
    }
    return 0;
}