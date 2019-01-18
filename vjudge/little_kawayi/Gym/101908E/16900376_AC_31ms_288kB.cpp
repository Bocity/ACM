#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    int lena = a.size();
    int lenb = b.size();
    int ans = 0;
    // cout << lena << ' ' << lenb << ' ' << lena - lenb << endl;
    for (int i = 0; i < lena - lenb + 1; i++)
    {
        bool flag = 1;
        for (int j = 0; j < lenb; j++)
            if (b[j] == a[i + j])
            {
                flag = 0;
                break;
            }
        ans += flag;
    }
    cout << ans << endl;
    return 0;
}