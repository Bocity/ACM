#include <bits/stdc++.h>
#define maxn 100010
#define inf 0x7fffffff
using namespace std;
int n, m, root, cmpd;
struct data
{
    int l, r, d[3], mx[3], mn[3], sum, w; // sum:以此为根节点数目和  w:节点上数字
    data() {}
    data(int a, int b, int c, int val)
    {
        l = r = 0;
        d[0] = mx[0] = mn[0] = a;
        d[1] = mx[1] = mn[1] = b;
        d[2] = mx[2] = mn[2] = c;
        w = sum = val;
    }
} tr[maxn];
void update(int x)
{
    int l = tr[x].l, r = tr[x].r;
    if (l) // 维护以此为根的子树各个维度范围与节点数目和
    {
        tr[x].mx[0] = max(tr[x].mx[0], tr[l].mx[0]);
        tr[x].mn[0] = min(tr[x].mn[0], tr[l].mn[0]);
        tr[x].mx[1] = max(tr[x].mx[1], tr[l].mx[1]);
        tr[x].mn[1] = min(tr[x].mn[1], tr[l].mn[1]);
        tr[x].mx[2] = max(tr[x].mx[2], tr[l].mx[2]);
        tr[x].mn[2] = min(tr[x].mn[2], tr[l].mn[2]);
        tr[x].sum += tr[l].sum;
    }
    if (r)
    {
        tr[x].mx[0] = max(tr[x].mx[0], tr[r].mx[0]);
        tr[x].mn[0] = min(tr[x].mn[0], tr[r].mn[0]);
        tr[x].mx[1] = max(tr[x].mx[1], tr[r].mx[1]);
        tr[x].mn[1] = min(tr[x].mn[1], tr[r].mn[1]);
        tr[x].mx[2] = max(tr[x].mx[2], tr[r].mx[2]);
        tr[x].mn[2] = min(tr[x].mn[2], tr[r].mn[2]);
        tr[x].sum += tr[r].sum;
    }
}
int cmp(data a, data b)
{
    if (a.d[cmpd] == b.d[cmpd])
    {
        if (a.d[(cmpd + 1) % 3] == b.d[(cmpd + 1) % 3])
        {
            return a.d[(cmpd + 2) % 3] < b.d[(cmpd + 2) % 3];
        }
        return a.d[(cmpd + 1) % 3] < b.d[(cmpd + 1) % 3];
    }
    return a.d[cmpd] < b.d[cmpd];
}
int build(int l, int r, int d)
{
    int mid = (l + r) >> 1;
    cmpd = d;
    //不对整体排序，只求第n小的元素并放在其位置上
    nth_element(tr + l, tr + mid, tr + r + 1, cmp);
    tr[mid].mx[0] = tr[mid].mn[0] = tr[mid].d[0];
    tr[mid].mx[1] = tr[mid].mn[1] = tr[mid].d[1];
    tr[mid].mx[2] = tr[mid].mn[2] = tr[mid].d[2];
    tr[mid].sum = tr[mid].w;
    tr[mid].l = 0;
    tr[mid].r = 0;
    if (l < mid)
    {
        tr[mid].l = build(l, mid - 1, (d + 1) % 3);
    }
    if (r > mid)
    {
        tr[mid].r = build(mid + 1, r, (d + 1) % 3);
    }
    update(mid);
    return mid;
}
void kdinsert(int now)
{
    if (now == root)
    {
        return;
    }
    int D, p;
    D = 0;
    p = root;
    while (true)
    {
        //插入到P中，维护信息
        if (tr[now].mx[0] > tr[p].mx[0])
        {
            tr[p].mx[0] = tr[now].mx[0];
        }
        if (tr[now].mx[1] > tr[p].mx[1])
        {
            tr[p].mx[1] = tr[now].mx[1];
        }
        if (tr[now].mx[2] > tr[p].mx[2])
        {
            tr[p].mx[2] = tr[now].mx[2];
        }
        if (tr[now].mn[0] < tr[p].mn[0])
        {
            tr[p].mn[0] = tr[now].mn[0];
        }
        if (tr[now].mn[1] < tr[p].mn[1])
        {
            tr[p].mn[1] = tr[now].mn[1];
        }
        if (tr[now].mn[2] < tr[p].mn[2])
        {
            tr[p].mn[2] = tr[now].mn[2];
        }
        tr[p].sum += tr[now].sum;
        if (tr[p].d[0] == tr[now].d[0] && tr[p].d[1] == tr[now].d[1] && tr[p].d[2] == tr[now].d[2]) //相等时只更新不插入
        {
            tr[p].w += tr[now].w;
            m--;
            return;
        }
        if (tr[now].d[D] >= tr[p].d[D])
        {
            if (tr[p].r == 0)
            {
                tr[p].r = now;
                return;
            }
            else
            {
                p = tr[p].r;
            }
        }
        else
        {
            if (tr[p].l == 0)
            {
                tr[p].l = now;
                return;
            }
            else
            {
                p = tr[p].l;
            }
        }
        D = (D + 1) % 3;
    }
}
int query(int now, int x1, int y1, int z1, int x2, int y2, int z2)
{
    // 当前节点范围与查询矩形不相交
    if (!now || tr[now].mx[0] < x1 || tr[now].mn[0] > x2 || tr[now].mx[1] < y1 || tr[now].mn[1] > y2 || tr[now].mx[2] < z1 || tr[now].mn[2] > z2)
    {
        return 0;
    }
    // 当前节点范围包含查询矩形
    if (tr[now].mx[0] <= x2 && tr[now].mn[0] >= x1 && tr[now].mx[1] <= y2 && tr[now].mn[1] >= y1 && tr[now].mx[2] <= z2 && tr[now].mn[2] >= z1)
    {
        return tr[now].sum;
    }
    int ret = 0;
    // 查询矩形包含当前节点
    if (tr[now].d[0] >= x1 && tr[now].d[0] <= x2 && tr[now].d[1] >= y1 && tr[now].d[1] <= y2 && tr[now].d[2] >= z1 && tr[now].d[2] <= z2)
    {
        ret += tr[now].w;
    }
    ret += query(tr[now].l, x1, y1, z1, x2, y2, z2) + query(tr[now].r, x1, y1, z1, x2, y2, z2);
    return ret;
}
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int op;
        m = 0;
        int mod = 10000;
        root = 1;
        while (n--)
        {
            scanf("%d", &op);
            if (op == 1)
            {
                int x, y, z;
                scanf("%d %d %d", &x, &y, &z);
                tr[++m] = data(x, y, z, 1);
                kdinsert(m);
                if (m % mod == 0) //每mod次重建KD树
                {
                    root = build(1, m, 0);
                }
            }
            else
            {
                int x1, y1, z1, x2, y2, z2;
                scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
                int ans = query(root, x1, y1, z1, x2, y2, z2);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}