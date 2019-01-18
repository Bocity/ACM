#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        int ans = 0, st = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int pos = lower_bound(b + st, b + n, k - a[i]) - b;
            if (a[i] + b[pos] >= k)
            {
                ans += 1;
                st = pos + 1;
            }
            else
                break;
        }
        cout << ans << endl;

    }
    return 0;
}
