#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
int mini, maxi;
int t, n, k, a[100005];
priority_queue<pii> q;
priority_queue<pii, vector<pii>, greater<pii> > q2;
void solve2(int);
void solve1(int i) {
    bool flag = false;
    int rmaxi = maxi;
    while (!q.empty() && (q.top().first >= a[i] + k || q.top().second < maxi)) {
        maxi = max(maxi, q.top().second);
        q.pop();
    }
    if (q.empty())
        maxi = i;
    else
        maxi = q.top().second;
    mini = i;
    // while (!q2.empty() && q2.top().second < mini) q2.pop();
}
void solve2(int i) {
    bool flag = false;
    int rmini = mini;
    while (!q2.empty() && (q2.top().first <= a[i] - k || q2.top().second < mini)) {
        mini = max(mini, q2.top().second);
        q2.pop();
    }
    if (q2.empty())
        mini = i;
    else
        mini = q2.top().second;
    maxi = i;
    // while (!q.empty() && q.top().second < maxi) q.pop();
}
int main() {
    ll ans;
    cin >> t;
    while (t--) {
        while (!q.empty()) q.pop();
        while (!q2.empty()) q2.pop();
        cin >> n >> k;
        ans = 0;
        mini = 1, maxi = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (!q.empty() && (q.top().first >= a[i] + k)) {
                // cout << q.top().first << '!';
                solve1(i);
            }
            if (!q2.empty() && (q2.top().first <= a[i] - k)) {
                // cout << q.top().first << '!';
                solve2(i);
            }
            q.push(make_pair(a[i], i));
            q2.push(make_pair(a[i], i));
            // cout << mini << " " << maxi << endl;
            ans += i - min(mini, maxi) + 1;
            // cout << ans << endl;
        }
        cout << ans << endl;
    }
}