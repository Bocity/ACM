#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define Pair pair<long long, Node>
#define ll long long
#define inf 1000000000
#define Sqrt2(x) (x) * (x)
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int n, m, root, idx, k;
struct Node {
    int fea[7], mn[7], mx[7], l, r;
    int &operator[](int x) {
        return fea[x];
    }
    Node(int x = 0, int y = 0) {
        l = 0, r = 0;
        fea[0] = x, fea[1] = y;
    }
} _data[500010];

bool operator<(Node a, Node b) {
    return a[idx] < b[idx];
}
priority_queue<Pair> Q;
inline ll dis(Node a, Node b) {
    ll tmp = 0;
    for (int i = 0; i < k; i++) tmp += Sqrt2(a[i] - b[i]);
    return tmp;
}
struct kdtree {
    int ans1, ans2;
    Node data[500010], T;
    void update(int rt) {
        Node l = data[data[rt].l], r = data[data[rt].r];
        for (int i = 0; i < k; i++) {
            if (data[rt].l)
                data[rt].mn[i] = min(data[rt].mn[i], l.mn[i]), data[rt].mx[i] = max(data[rt].mx[i], l.mx[i]);
            if (data[rt].r)
                data[rt].mn[i] = min(data[rt].mn[i], r.mn[i]), data[rt].mx[i] = max(data[rt].mx[i], r.mx[i]);
        }
    }
    int build(int l, int r, int dep) {
        // idx = dep % k;
        idx = dep % k;
        int mid = (l + r) >> 1;
        nth_element(_data + l, _data + mid, _data + r + 1); // nth_element()为STL中的函数
        data[mid] = _data[mid];
        for (int i = 0; i < k; i++) data[mid].mn[i] = data[mid].mx[i] = data[mid][i];
        if (l < mid) data[mid].l = build(l, mid - 1, idx + 1);
        if (r > mid) data[mid].r = build(mid + 1, r, idx + 1);
        update(mid);
        return mid;
    }
    ll get1(int rt, Node p) {
        ll tmp = 0;
        for (int i = 0; i < k; i++) tmp += max(0, data[rt].mn[i] - p[i]) + max(0, p[i] - data[rt].mx[i]);
        return tmp;
    }
    ll get2(int rt, Node p) {
        ll tmp = 0;
        for (int i = 0; i < k; i++) tmp += max(abs(data[rt].mx[i] - p[i]), abs(p[i] - data[rt].mn[i]));
        return tmp;
    }
    void insert(int rt, int dep) {
        // idx = dep % k;
        if (T[dep] >= data[rt][dep]) {
            if (data[rt].r)
                insert(data[rt].r, dep ^ 1);
            else {
                data[rt].r = ++n;
                data[n] = T;
                for (int i = 0; i < k; i++) data[n].mn[i] = data[n].mx[i] = data[n][i];
            }
        } else {
            if (data[rt].l)
                insert(data[rt].l, dep ^ 1);
            else {
                data[rt].l = ++n;
                data[n] = T;
                for (int i = 0; i < k; i++) data[n].mn[i] = data[n].mx[i] = data[n][i];
            }
        }
        update(rt);
    }
    void query1(int rt) {
        int d, dl = inf, dr = inf;
        Pair cur(0, data[rt]); //获取当前节点的数据和到p的距离
        for (int i = 0; i < k; i++) cur.first += (ll) abs((ll) cur.second.fea[i] - (ll) T.fea[i]); //估计距离 容易爆
        if (ans1 > cur.first && (data[rt].fea[0] != T.fea[0] || data[rt].fea[1] != T.fea[1])) ans1 = cur.first;
        if (data[rt].l) dl = get1(data[rt].l, T);
        if (data[rt].r) dr = get1(data[rt].r, T);
        if (dl < dr) {
            if (dl < ans1) query1(data[rt].l);
            if (dr < ans1) query1(data[rt].r);
        } else {
            if (dr < ans1) query1(data[rt].r);
            if (dl < ans1) query1(data[rt].l);
        }
    }
    void query2(int rt) {
        int d, dl = inf, dr = inf;
        Pair cur(0, data[rt]); //获取当前节点的数据和到p的距离
        for (int i = 0; i < k; i++) cur.first += (ll) abs((ll) cur.second.fea[i] - (ll) T.fea[i]); //估计距离 容易爆
        //  cur.first = cur.first;
        cur.first = -cur.first;
        if (ans2 > cur.first && (data[rt].fea[0] != T.fea[0] || data[rt].fea[1] != T.fea[1])) ans2 = cur.first;
        if (data[rt].l) dl = -get2(data[rt].l, T);
        if (data[rt].r) dr = -get2(data[rt].r, T);
        if (dl < dr) {
            if (dl < ans2) query2(data[rt].l);
            if (dr < ans2) query2(data[rt].r);
        } else {
            if (dr < ans2) query2(data[rt].r);
            if (dl < ans2) query2(data[rt].l);
        }
    }
    int query1(Node p) {
        ans1 = inf;
        T = p;
        query1(root);
        return ans1;
    }
    int query2(Node p) {
        ans2 = inf;
        T = p;
        query2(root);
        return -ans2;
    }
    void insert(Node p) {
        T = p;
        insert(root, 0);
    }
    void init() {
        memset(_data, 0, sizeof _data);
        memset(data, 0, sizeof data);
    }
} kd;
void Print(Node data) {
    for (int i = 0; i < k; i++) printf("%d%c", data.fea[i], i == k - 1 ? '\n' : ' ');
}
int ans;
int main() {
    n = read();
    k = 2;
    kd.init();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++) {
            _data[i].fea[j] = read();
        }
    int T;
    T = 1;
    ans = inf;
    root = kd.build(1, n, 0);
    while (T <= n) {
        int x;
        int y;
        int ans1, ans2;
        Node p;
        p = _data[T];
        ans1 = kd.query1(p);
        ans2 = kd.query2(p);
        // cout << ans1 << endl;
        // cout << ans2 << endl;
        // cout << "-------" << endl;
        ans = min(ans, ans2 - ans1);
        T++;
    }
    printf("%d", ans);
    return 0;
}
