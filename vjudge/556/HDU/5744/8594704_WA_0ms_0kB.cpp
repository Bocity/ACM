#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    ll n, t, temp, qt;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    vector<ll> v;
    cin >> t;
    while (t--) {
        cin >> n;
        while (!q.empty()) q.pop();
        v.clear();
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp & 1) {
                q.push(temp);
            } else {
                v.push_back(temp);
            }
        }
        for (auto i : v) {
            if (!q.empty()) {
                qt = q.top();
                q.pop();
                q.push(qt + i);
            } else {
                q.push(i);
            }
        }
        cout << q.top() << endl;
    }
    return 0;
}