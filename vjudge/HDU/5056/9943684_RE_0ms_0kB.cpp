#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define PER(i, n) for (int i = (n) -1; i >= 0; i--)
#define DE cout << '---------' << endl
using namespace std;
long long N, M, x, y, n;
map<char, int> num;
deque<char> q;
string s;
int T, k;
long long ans = 0;
int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> s;
        cin >> k;
        ans = 0;
        num.clear();
        q.clear();
        int sz = s.size();
        REP(i, sz) {
            if (num[s[i]] == k) {
                while (q.front() != s[i]) {
                    q.pop_front();
                }
                q.pop_front();
                ans += q.size() + 1;
                q.push_back(s[i]);
            } else {
                ans += q.size() + 1;
                q.push_back(s[i]);
                num[s[i]]++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}