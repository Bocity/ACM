#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[300005], ans[300005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    for (int i = m + 1; i <= n; i++)
        ans[i] = max(ans[i - 1], ans[i - m] + s[i]);
    cout << ans[n] << endl;
}
