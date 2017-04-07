#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
int a[300000];
long long b1, q, l, m, x;

int main()
{
    map<long long, bool> qq;
    ios::sync_with_stdio(false);
    cin >> b1 >> q >> l >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        qq[x] = true;
    }
    if (b1 == 0 || q == 0)
    {
        // if (qq[0]==0)
        // {
        //     printf("inf\n");
        //     return 0;
        // }
        if (b1 == 0)
        {
            if (qq[0] == 1)
            {
                printf("0\n");
            }
            else
            {
                printf("inf\n");
            }
            return 0;
        }
        if (q == 0)
        {
            if (abs(b1) > l)
            {
                printf("0\n");
            }
            else if (qq[0] == 1 && qq[b1] == 1)
            { //少了这个else,码力的重要性
                printf("0\n");
            }
            else if (qq[0] == 1)
            {
                printf("1\n");
            }
            else
            {
                printf("inf\n");
            }
            return 0;
        }
    }
    if (q == 1)
    {
        if (abs(b1) > l)
        {
            printf("0\n");
        }
        else if (qq[b1] == 1)
        {
            printf("0\n");
        }
        else
        {
            printf("inf\n");
        }
        return 0;
    }
    if (q == -1)
    {
        if (abs(b1) > l)
        {
            printf("0\n");
        }
        else if (qq[b1] == 1 && qq[-b1] == 1)
        {
            printf("0\n");
        }
        else
        {
            printf("inf\n");
        }
        return 0;
    }
    int sum = 0;
    while (abs(b1) <= l)
    {
        if (!qq[b1])
            sum++;
        b1 *= q;
    }
    cout << sum;
    return 0;
}