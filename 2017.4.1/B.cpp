#include <iostream>
#include <string>
#include <cstring>
using namespace std;
inline long long readT()
{
    char c;
    long long ret = 0, flag = 0;
    while (c = getchar(), (c < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        flag = 1;
    else
        ret = c ^ 48;
    while (c = getchar(), c >= '0' && c <= '9')
        ret = ret * 10 + (c ^ 48);
    return flag ? -ret : ret;
}
int T, n, m, a[100] = {0}, ans;
string s;
int main()
{
    T = readT();
    while (T--)
    {
        memset(a, 0, sizeof(a));
        n = readT();
        m = readT();
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
        }
        for (int i = 0; i < s.length(); i++)
        {
            a[s[i] - '0' % 3]++;
            ans += (s[i] - '0' % 3);
        }
        ans %= 3;
    }
    return 0;
}