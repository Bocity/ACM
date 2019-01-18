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
bool dp[400002];
deque<int> dp0;
const int mid = 200001;
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
        int l = mid, r = mid;
        dp0.clear();
        while (n--) {
            cin >> str;
            if (str == "PUSH") {
                cin >> it;
                if (op) {
                    dp[r++] = it;
                    if (!it) {
                        dp0.push_back(r - 1);
                    }
                } else {
                    dp[--l] = it;
                    if (!it) {
                        dp0.push_front(l);
                    }
                }
            } else if (str == "POP") {
                if (op) {
                    r--;
                    if (!dp[r]) {
                        dp0.pop_back();
                    }
                } else {
                    l++;
                    if (!dp[l - 1]) {
                        dp0.pop_front();
                    }
                }
            } else if (str == "QUERY") {
                if (l == r) {
                    cout << "Invalid." << endl;
                } else if (!op) {
                    if (dp0.size()) {
                        int r0 = dp0.back();
                        int ans;
                        if (r0 == l)
                            ans = 0;
                        else
                            ans = 1;
                        if (r - r0 == 1) {
                            cout << 0 + ans << endl;
                        } else {
                            if ((r - r0 - 1 + ans) & 1) {
                                cout << 1 << endl;
                            } else {
                                cout << 0 << endl;
                            }
                        }
                    } else {
                        if (r - l & 1)
                            cout << 1 << endl;
                        else
                            cout << 0 << endl;
                    }
                } else {
                    if (dp0.size()) {
                        int l0 = dp0.front();
                        int ans;
                        if (l0 + 1 == r)
                            ans = 0;
                        else
                            ans = 1;
                        if (l0 == l) {
                            cout << 0 + ans << endl;
                        } else {
                            if ((l0 - l + ans) & 1) {
                                cout << 1 << endl;
                            } else {
                                cout << 0 << endl;
                            }
                        }
                    } else {
                        if (r - l & 1)
                            cout << 1 << endl;
                        else
                            cout << 0 << endl;
                    }
                }
            } else
                op = !op;
        }
    }
}