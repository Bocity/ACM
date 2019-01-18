#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int s[N], seg[N << 2], tag[N << 2];
void pushup(int rt)
{
    seg[rt] = min(seg[rt << 1], seg[rt << 1 | 1]);
}
void pushdown(int rt)
{
    if (tag[rt])
    {
        seg[rt << 1] -= tag[rt];
        seg[rt << 1 | 1] -= tag[rt];
        tag[rt << 1] += tag[rt];
        tag[rt << 1 | 1] += tag[rt];
        tag[rt] = 0;
    }
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        seg[rt] = s[l];
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1,r ,rt << 1 | 1);
    pushup(rt);
}
int query(int l, int r, int rt, int L, int R)
{
    if (L <= l && r <= R)
        return seg[rt];
    int m = l + r >> 1;
    int ans = 0x3f3f3f3f;
    pushdown(rt);
    if (L <= m)
        ans = min(ans, query(l, m, rt << 1, L, R));
    if (m < R)
        ans = min(ans, query(m + 1, r , rt << 1 | 1, L, R));
    pushup(rt);
    return ans;
}
void update(int l, int r, int rt, int L, int R, int V)
{
    if (L <= l && r <= R)
    {
        seg[rt] -= V;
        tag[rt] += V;
        return;
    }
    int m = l + r >> 1;
    pushdown(rt);
    if (L <= m)
        update(l, m, rt << 1, L, R, V);
    if (m < R)
        update(m + 1, r, rt << 1 | 1, L, R, V);
    pushup(rt);
}
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(tag, 0, sizeof tag);
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        build(1, n, 1);
        int ans = 0;
        for (int i = 1; i + k - 1 <= n; i++)
        {
            int num = query(1, n, 1, i, i + k - 1);

            if (num)
            {
                ans += num;
                update(1, n, 1, i, i + k - 1, num);

            }
        }
        cout << ans << endl;
    }
}
