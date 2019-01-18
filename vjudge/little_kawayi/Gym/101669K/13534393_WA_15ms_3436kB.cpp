#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int *s = new int[n+1];
    int *ans = new int[n+1];
    deque<int> d;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    int msh = 0;
    for (int i = n; i; i--)
    {
        int pos = n - i + 1 - s[i];
        if (s[i] == 1)
            d.push_back(i);
        else
            d.insert(d.begin() + pos, i);
    }
    int cnt = 1;
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++, cnt++)
        ans[*it] = cnt;
    for (int i = 1; i <= n; i++)
        if (i == 1)
            cout << ans[i];
        else
            cout << ' ' << ans[i];
    cout << endl;
    return 0;
}
