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
deque<bool> dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, ccnt = 1;
    string str;
    cin >> t;
    while (t--) {
        cout << "Case #" << ccnt++ << ":" << endl;
        cin >> n;
        bool op = true, it;
        while (n--) {
            cin >> str;
            if (str == "PUSH") {
                cin >> it;
                if (op)
                    dp.push_back(it);
                else
                    dp.push_back(it);
            } else if (str == "POP") {
                if (op)
                    dp.pop_back();
                else
                    dp.pop_front();
            } else if (str == "QUERY") {
                if (!dp.size()) {
                    cout << "Invalid." << endl;
                } else if (op) {
                    bool temp = dp[0];
                    REP(i, 1, dp.size()) {
                        temp = (!temp) | (!dp[i]);
                    }
                    cout << temp << endl;
                } else {
                    bool temp = dp.back();
                    PER(i, 0, dp.size() - 1) {
                        temp = (!temp) | (!dp[i]);
                    }
                    cout << temp << endl;
                }
            } else
                op = !op;
        }
    }
}