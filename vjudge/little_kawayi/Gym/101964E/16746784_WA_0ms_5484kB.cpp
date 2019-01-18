#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, l;
int s[N], id[N], srt[N], fx[N], fy[N];
int val[N], tag[N];
void pushup(const int& rt)
{
    val[rt] = val[rt << 1] + val[rt << 1 | 1];
}
void pushdown(const int& ln, const int& rn, const int& rt)
{
    if (tag[rt])
    {
        val[rt << 1] += tag[rt];
        val[rt << 1 | 1] += tag[rt];
        tag[rt << 1] += tag[rt];
        tag[rt <<1 | 1] += tag[rt];
        tag[rt] = 0;
    }
}
void update(const int& l, const int& r, const int& rt, const int& L, const int& R)
{

    if (L <= l && r <= R)
    {
        val[rt] += r - l + 1;
        tag[rt] += 1;
        return;
    }
    int m = l + r >> 1;
    pushdown(m - l + 1, r - m, rt);
    if (L <= m)
        update(l, m, rt << 1, L, R);
    if (m < R)
        update(m + 1, r, rt << 1 | 1, L, R);
    pushup(rt);
}
int query(const int& l, const int& r, const int& rt, const int& p)
{
    if (l == r)
        return val[rt];
    int m = l + r >> 1;
    pushdown(m - l + 1, r - m, rt);
    if (p <= m)
        return query(l, m, rt << 1, p);
    else
        return query(m + 1, r, rt << 1 | 1, p);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++)
        cin >> fx[i] >> fy[i];
    for (int i = 1; i <= m; i++)
        cin >> s[i],
        srt[i] = s[i];
    sort(srt + 1, srt + m + 1);

    int len = unique(srt + 1, srt + 1 + m) - srt - 1;
    //cout << "len:" << len << endl;
    for (int i = 1; i <= m; i++)
        id[i] = lower_bound(srt + 1, srt + 1 + len, s[i]) - srt;
    for (int i = 1; i <= n; i++)
    {
        int ra = l - fy[i];
        if (ra >= 0)
        {
            int l, r;
            l = lower_bound(srt + 1, srt + 1 + len, fx[i] - ra) - srt;
            r = upper_bound(srt + 1, srt + 1 + len, fx[i] + ra) - srt;
            //cout << "--" << l << ' ' << r << endl;
            update(1, len, 1, l, r);
        }
    }
    for (int i = 1; i <= m; i++)
            cout << query(1, len, 1, id[i]) << '\n';
    return 0;
}
/*
8 4 4
7 2
3 3
4 5
5 1
2 2
1 4
8 4
9 4
6 1 4 9
*/
