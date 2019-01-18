#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct edge
{
    int t, a, b;
};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<edge> *s = new vector<edge>[n+1];
        while (k--)
        {
            int be, e, a, b;
            cin >> be >> e >> a >> b;
            b = b == 0 ? 0 : a / (((ull)1 << b)-1);
            s[be].push_back(edge{e,a,b});
        }
        ull *level = new ull[n+1];
        memset(level, 0x3f, 8*n+8);
        level[1] = 1;
        auto cmp = [&level](int a, int b)->bool{return level[a] > level[b];};
        priority_queue<int,vector<int>,decltype(cmp)> q(cmp);
        q.push(1);
        while (!q.empty())
        {
            int now = q.top();
            q.pop();
            if (now == n)
                break;
            for (edge i : s[now])
                if (level[now] <= i.b && level[now] + i.a < level[i.t])
                {
                    level[i.t] = level[now] + i.a;
                    q.push(i.t);
                }
        }
        if (level[n] == 0x3f3f3f3f3f3f3f3f)
            cout << -1 << endl;
        else
            cout << logb(level[n]) << endl;
        delete[] level,s;
    }
    return 0;
}