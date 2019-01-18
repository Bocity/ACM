#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,k,k1,k2;
    cin >> n >> k1 >> k2;
    k = k1 + k2;
    int *s = new int[n+1];
    s[0] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        s[i] = abs(s[i] - tmp);
    }
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(s[i]);
    while (k--)
    {
        int tmp = q.top();
        if (tmp)
        {
            q.pop();
            q.push(tmp-1);
        }
    }
    ll ans = 0;
    while (!q.empty())
    {
        ans += q.top() * q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}
