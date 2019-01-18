#include <bits/stdc++.h>
using namespace std;
string s;
char rcd[1000010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        char *ans = new char[n+1];
        ans[n-1] = '>';
        char *s = new char[n+1];
        cin >> s;
        for (int i = n-2; i>=0; i--)
        {
            if (s[i] > s[i+1])
                ans[i] = '>';
            else if (s[i] < s[i+1])
                ans[i] = '<';
            else
                ans[i] = ans[i+1];
        }
        for (int i = 0; i < n-1; i++)
            cout << ans[i];
        cout << endl;
        delete[] s,ans;
    }
    return 0;
}