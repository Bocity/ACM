#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
#define inf 1000000000
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
    int fea[2], mn[2], mx[2], l, r;
    int &operator[](int x) {
        return fea[x];
    }
    Node(int x = 0, int y = 0) {
        l = 0, r = 0;
        fea[0] = x, fea[1] = y;
    }
} _data[500005];
bool operator<(Node a, Node b) {
    return a[idx] < b[idx];
}
inline int dis(Node a, Node b) {
    int tmp = 0;
    for (int i = 0; i < k; i++) tmp += abs(a[i] - b[i]);
    return tmp;
}
struct kdtree {
    int ans;
    Node data[1000005], T;
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
        idx = dep % k;
        int mid = (l + r) >> 1;
        nth_element(_data + l, _data + mid, _data + r + 1); // nth_element()为STL中的函数
        data[mid] = _data[mid];
        for (int i = 0; i < k; i++) data[mid].mn[i] = data[mid].mx[i] = data[mid][i];
        if (l < mid) data[mid].l = build(l, mid - 1, idx);
        if (r > mid) data[mid].r = build(mid + 1, r, idx);
        update(mid);
        return mid;
    }
    int get(int rt, Node p) {
        int tmp = 0;
        for (int i = 0; i < k; i++) tmp += max(0, data[rt].mn[i] - p[i]);
        for (int i = 0; i < k; i++) tmp += max(0, p[i] - data[rt].mx[i]);
        return tmp;
    }
    void insert(int rt, int dep) {
        idx = dep % k;
        if (T[dep] >= data[rt][dep]) {
            if (data[rt].r)
                insert(data[rt].r, idx);
            else {
                data[rt].r = ++n;
                data[n] = T;
                for (int i = 0; i < k; i++) data[n].mn[i] = data[n].mx[i] = data[n][i];
            }
        } else {
            if (data[rt].l)
                insert(data[rt].l, idx);
            else {
                data[rt].l = ++n;
                data[n] = T;
                for (int i = 0; i < k; i++) data[n].mn[i] = data[n].mx[i] = data[n][i];
            }
        }
        update(rt);
    }
    void query(int rt, int now) {
        int d, dl = inf, dr = inf;
        d = dis(data[rt], T);
        ans = min(ans, d);
        if (data[rt].l) dl = get(data[rt].l, T);
        if (data[rt].r) dr = get(data[rt].r, T);
        if (dl < dr) {
            if (dl < ans) query(data[rt].l, now ^ 1);
            if (dr < ans) query(data[rt].r, now ^ 1);
        } else {
            if (dr < ans) query(data[rt].r, now ^ 1);
            if (dl < ans) query(data[rt].l, now ^ 1);
        }
    }
    int query(Node p) {
        ans = inf;
        T = p;
        query(root, 0);
        return ans;
    }
    void insert(Node p) {
        T = p;
        insert(root, 0);
    }
} kd;
int main() {
    k = 2;
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) _data[i][0] = read(), _data[i][1] = read();
    root = kd.build(1, n, 0);
    while (m--) {
        int opt = read(), x = read(), y = read();
        if (opt == 1)
            kd.insert(Node(x, y));
        else
            printf("%d\n", kd.query(Node(x, y)));
    }
    return 0;
}