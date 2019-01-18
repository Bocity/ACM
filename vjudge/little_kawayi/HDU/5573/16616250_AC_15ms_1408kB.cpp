#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        int n, k;
        cin >> n >> k;
        cout << "Case #" << cas << ":" << endl;
        if (n <= 1 << k)
        {
            int tmp = n - 1 >> 1;
            for (int i = 0; i < k - 1; i++)
                cout << (1 << i) << ' ' << (((tmp >> i) & 1) ? '+' : '-') << endl;
            cout << ((1 << k - 1) + (n % 2 ? 0 : 1)) << " +" << endl;
        }
        else
        {
            int sgn, rst;
            int l = 1, r = 1 << k - 1;
            while (l <= r)
            {
                int m = l + r >> 1, num = 1, ans = 1;
                int mid = m;
                for (int i = 2; i <= k; i++)
                {
                    if (m <= (1 << k - i))
                    {
                        ans += num *= 2;
                    }
                    else
                    {
                        m -= (1 << k - i);
                        ans += num = num * 2 + 1;
                    }
                }
                if (ans < n)
                {
                    l = mid + 1;
                }
                else if (ans > n)
                {
                    r = mid - 1;
                }
                else
                {
                    sgn = 1;
                    rst = l;
                    break;
                }
            }

            l = 1, r = 1 << k - 1;
            while (l <= r)
            {
                int m = l + r >> 1, num = 1, ans = -1;
                int mid = m;
                for (int i = 2; i <= k; i++)
                {
                    if (m <= (1 << k - i))
                    {
                        ans += num *= 2;
                    }
                    else
                    {
                        m -= (1 << k - i);
                        ans += num = num * 2 + 1;
                    }
                }
                if (ans < n)
                {
                    l = mid + 1;
                }
                else if (ans > n)
                {
                    r = mid;
                }
                else
                {
                    sgn = -1;
                    rst = l;
                    break;
                }
            }
            cout << 1 << ' ' << (sgn == 1 ? '+' : '-') << endl;
                int m = rst, num = 1;
                for (int i = 1; i < k; i++)
                {
                    if (m <= (1 << k - i - 1))
                    {
                        cout << (num *= 2) << ' ' << '+' << endl;;

                    }
                    else
                    {
                        m -= (1 << k - i - 1);
                        cout << (num = num * 2 + 1) << ' ' << '+' << endl;
                    }
                }
        }
    }

}
