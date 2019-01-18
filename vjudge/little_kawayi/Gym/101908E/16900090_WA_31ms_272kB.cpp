#include <bits/stdc++.h>
using namespace std;
char a[10005], b[10005];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> a >> b;
    int lena = strlen(a);
    int lenb = strlen(b);
    int ans = 0;
    for (int i = 0; i < lena - lenb; i++)
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
