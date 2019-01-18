//hdu 5668 circle
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int c[25], vis[25], a[25], m[25];

void ex_gcd(int a, int b, int &d, int &x, int &y)
{
    if(!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        ex_gcd(b, a%b, d, y, x);
        y -= (a / b) * x;
    }
}
int CRT(int n)
{
    int c = a[1], l = m[1];
    int d, x, y;
    for(int i = 2; i <= n; i++)
    {
        ex_gcd(l, m[i], d, x, y);
        if((a[i]-c)%d)
            return -1;
        int tt = m[i] / d;
        x = (a[i] - c) / d * x % (m[i] / d);
        c += l * x;
        l = l / d * m[i];
        c %= l;
    }
     return (c + l) % l ? (c + l) % l : l;  
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--)
    {
        int tmp, n;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> tmp;
            c[tmp] = i;
        }
        memset(vis, 0, sizeof(vis));
        int j = 0;
        for(int i = 1; i <= n; i++)
        {
            int k = 0;
            while(j != c[i])
            {
                j++;
                if(j > n)
                    j = 1;
                if(!vis[j])
                    k++;
            }
            vis[c[i]] = 1;
            a[i] = k;
            m[i] = n - i + 1;
            a[i] %= m[i];
        }

        int ans = CRT(n);
        if(ans != -1)
            printf("%d\n", ans);
        else
            printf("Creation August is a SB!\n");
    }
    return 0;
}