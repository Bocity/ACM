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
    list<int> l;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = n; i; i--)
    {
        int pos = n - i + 1;// 1 -- n
        int index = pos - s[i];
        if (index >= l.size())
            l.push_back(i);
        else
        {
            list<int>::iterator it = l.begin();
            for (int j = 0; j < index; j++)
                it++;
            l.insert(it, i);
        }
    }
    int cnt = 1;
    for (list<int>::iterator it = l.begin(); it != l.end(); it++, cnt++)
        ans[*it] = cnt;
    for (int i = 1; i <= n; i++)
        if (i == 1)
            cout << ans[i];
        else
            cout << ' ' << ans[i];
    cout << endl;
    return 0;
}