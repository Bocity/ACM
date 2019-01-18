#include <iostream>
#include <cstring>
#include <map>
using namespace std;
long long B[1000000] = {0};
long long A[1000000] = {0};
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
//to calculate the longest contiguous increasing sequence
long long length(long long nums[], long long size)
{
    map<long long, bool> q;
    long long n = 0;
    long long ans = 1;
    while (n < size)
    {
        if (!q[nums[n] + 2000000000])
        {

            q[nums[n] + 2000000000] = true;
            n++;
        }
        else
        {
            q.erase(q.begin(), q.end());
            q[nums[n] + 2000000000] = true;
            ans++;
            n++;
        }
    }
    return ans;
}
long long T, n, a[1000000];
int main()
{
    T = readT();
    while (T--)
    {
        n = readT();
        memset(B, 0, sizeof(B));
        memset(A, 0, sizeof(A));
        for (int i = 0; i < n; i++)
            a[i] = readT();
        cout << length(a, n) << "\n";
    }
    return 0;
}