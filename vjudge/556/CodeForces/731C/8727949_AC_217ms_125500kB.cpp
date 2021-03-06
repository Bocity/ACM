#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
struct trees
{
    int c;
    int f;
} q[2000000];
bool cmp(trees x, trees y)
{
    if (x.f == y.f)
        return x.c > y.c;
    return x.f > y.f;
}
int n, m, k, c[20000000], x, y, ans = 0;
bool vis[20000000];
int fa[2000000];
void init()
{
    for (int i = 1; i <= n + 2; i++)
    {
        fa[i] = i;
    }
}
int cha(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = cha(fa[x]);
}
void Union(int x, int y)
{
    x = cha(x);
    y = cha(y);
    if (x != y)
        fa[x] = y;
    else
        return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    init();
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        Union(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        q[i].f = cha(i);
        q[i].c = c[i];
    }
    sort(q + 1, q + 1 + n, cmp);
    int sum = 1, maxn = 1, maxx = 1;
    for (int i = 2; i <= n + 1; i++)
    {
        if (q[i].f == q[i - 1].f)
        {
            sum++;
            if (q[i].c == q[i - 1].c)
            {
                maxn++;
                continue;
            }
            else
            {
                maxx = max(maxx, maxn);
                maxn = 1;
                continue;
            }
        }
        else
        {
            maxx = max(maxx, maxn);
            // cout << sum << " " << maxx << " " << i << endl;
            ans += sum - maxx;
            maxx = 1;
            maxn = 1;
            sum = 1;
        }
    }
    cout << ans;
    return 0;
}
/*
15 14 2
1 2 1 1 2 1 1 2 2 1 1 2 2 1 2
1 2
2 3
3 4
4 5
5 6
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 13
*/