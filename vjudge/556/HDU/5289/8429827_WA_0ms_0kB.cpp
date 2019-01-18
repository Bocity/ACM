#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
ll solve(int n)
{
    ll ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans;
}
int main() {
    priority_queue<pii> q;
    priority_queue<pii, vector<pii >, greater<pii > > q2;

    int t, n, k, a[100005];
    ll ans;
    cin >> t;
    while (t--) {
        while(!q.empty()) q.pop();
        while(!q2.empty()) q2.pop();
        cin >> n >> k;
        ans = 0;
        int mini = 1, maxi = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (!q.empty() && (q.top().first >= a[i] + k)) {
                // cout << q.top().first << '!';
                mini = q.top().second;
                while (!q.empty() && (q.top().first >= a[i] + k || q.top().second < mini)) {
                    q.pop();
                }
                if (q.empty()) maxi = i;
                else
                    maxi = q.top().second;
                mini = i;
                while(!q2.empty() && q2.top().second < mini) q2.pop();
            }
            else if (!q2.empty() && (q2.top().first <= a[i] - k)) {
                // cout << q.top().first << '!';
                maxi = q2.top().second;
                while (!q2.empty() && (q2.top().first <= a[i] - k || q2.top().second < maxi)) {
                    q2.pop();
                }
                if (q2.empty())
                    mini = i;
                else
                    mini = q2.top().second;
                maxi = i;
                while(!q.empty() && q.top().second < maxi) q.pop();
            }
            q.push(make_pair(a[i], i));
            q2.push(make_pair(a[i], i));
            // cout << mini << " " << maxi << endl;
            ans += i - min(mini, maxi) + 1;
        }
        cout << ans << endl;
    }
}