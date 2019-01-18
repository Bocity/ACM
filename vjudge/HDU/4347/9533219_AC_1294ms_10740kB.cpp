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
} _data[50010];

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
    int ans;
    Node data[50010], T;
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
    ll get(int rt, Node p) {
        ll tmp = 0;
        for (int i = 0; i < k; i++) tmp += Sqrt2(max(p[i] - data[rt].mx[i], 0) + max(data[rt].mn[i] - p[i], 0));
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
    void query(int rt) {
        int d, dl = inf, dr = inf;
        Pair cur(0, data[rt]); //获取当前节点的数据和到p的距离
        for (int i = 0; i < k; i++) cur.first += (ll) Sqrt2((ll) cur.second.fea[i] - (ll) T.fea[i]); //估计距离 容易爆
        //  cur.first = cur.first;
        if (Q.size() < m) //如果队列没有满，则继续放入     //点使用限制
        {
            Q.push(cur);
        } else {
            if (cur.first < Q.top().first) //如果找到更小的距离，则用于替换队列Q中最大的距离的数据 。／／点使用限制
            {
                Q.pop();
                Q.push(cur);
            }
        }
        if (data[rt].l) dl = get(data[rt].l, T);
        if (data[rt].r) dr = get(data[rt].r, T);
        if (dl < dr) {
            if (dl < Q.top().first || Q.size() < m) query(data[rt].l);
            if (dr < Q.top().first || Q.size() < m) query(data[rt].r);
        } else {
            if (dr < Q.top().first || Q.size() < m) query(data[rt].r);
            if (dl < Q.top().first || Q.size() < m) query(data[rt].l);
        }
    }
    int query(Node p) {
        ans = inf;
        T = p;
        query(root);
        return ans;
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

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        kd.init();
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < k; j++) {
                _data[i].fea[j] = read();
            }
        int T;
        T = read();
        root = kd.build(1, n, 0);
        while (T--) {
            int x;
            int y;
            Node p;
            for (int i = 0; i < k; i++) {
                p.fea[i] = read();
            }
            scanf("%d", &m);
            while (!Q.empty()) Q.pop(); //事先需要清空优先队列
            kd.query(p);
            printf("the closest %d points are:\n", m);
            Node tmp[25];
            for (int i = 0; !Q.empty(); i++) {
                tmp[i] = Q.top().second;
                Q.pop();
            }
            for (int i = m - 1; i >= 0; i--) Print(tmp[i]);
        }
    }
    return 0;
}
