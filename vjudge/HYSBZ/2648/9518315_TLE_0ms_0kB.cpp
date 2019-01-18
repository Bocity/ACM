#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 500010
#define inf 1000000000
//#define lson rt << 1
//#define rson rt << 1 | 1
#define Pair pair<long long, Node>
//#define Sqrt2(x) (x) * (x)
typedef long long ll;
int n, k, idx, m, root; // k维度,按照编号为idx的属性进行划分
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
struct Node {
    int fea[5], mn[5], mx[5], l, r; //定义属性数组
    bool operator<(const Node &u) const {
        return fea[idx] < u.fea[idx];
    }
    Node() {
        l = 0, r = 0;
    }
    int id; //出现顺序
} _data[N]; //_data[]数组代表输入的数据
inline ll dis(Node a, Node b) {
    ll tmp = 0;
    for (int i = 0; i < k; i++) tmp += abs(a.fea[i] - b.fea[i]);
    return tmp;
}
priority_queue<Pair> Q; //队列Q用于存放离p最近的m个数据

class KDTree {
  public:
    int Build(int, int, int);        //建树
    void Query(Node, int, int, int); //查询
    void update(int);                //记录最值
    void insert(Node, int, int);
    void init();
    ll cal(Node, int); //估价函数
  private:
    Node data[2 * N]; // data[]数组代表K-D树的所有节点数据
                      // int flag[2 * N];  //用于标记某个节点是否存在，1表示存在，-1表示不存在
} kd;

void KDTree::update(int rt) {
    Node l = data[data[rt].l];
    Node r = data[data[rt].r];
    for (int i = 0; i < k; i++) {
        if (data[rt].l) data[rt].mn[i] = min(data[rt].mn[i], l.mn[i]), data[rt].mx[i] = max(data[rt].mx[i], l.mx[i]);
        if (data[rt].r) data[rt].mn[i] = min(data[rt].mn[i], r.mn[i]), data[rt].mx[i] = max(data[rt].mx[i], r.mx[i]);
    }
    return;
}
void KDTree::insert(Node p, int rt, int dept) { //把p插进去.
    int idx = dept % k;
    if (p.fea[idx] >= data[rt].fea[idx]) {
        if (data[rt].r) {
            insert(p, data[rt].r, idx + 1);
        } else {
            data[rt].r = ++n;
            data[n] = p;
            // cout << (rson) << "  1111111\n";
            for (int i = 0; i < k; i++) data[n].mn[i] = data[n].mx[i] = data[n].fea[i];
        }

    } else {
        if (data[rt].l) {
            insert(p, data[rt].l, idx + 1);
        } else {
            data[rt].l = ++n;
            data[n] = p;
            // cout << (lson) << "  22222222222\n";
            for (int i = 0; i < k; i++) data[n].mn[i] = data[n].mx[i] = data[n].fea[i];
        }
    }
    update(rt);
    return;
}
//建树步骤，参数dept代表树的深度
int KDTree::Build(int l, int r, int dept) {
    idx = dept % k; //按照编号为idx的属性进行划分
    int mid = (l + r) >> 1;
    nth_element(_data + l, _data + mid, _data + r + 1); // nth_element()为STL中的函数
    data[mid] = _data[mid];
    for (int i = 0; i < k; i++) data[mid].mn[i] = data[mid].mx[i] = data[mid].fea[i];
    if (l < mid) {
        data[mid].l = Build(l, mid - 1, dept + 1);
    } //递归左子树
    if (r > mid) {
        data[mid].r = Build(mid + 1, r, dept + 1); //递归右子树
    }
    update(mid);
    return mid;
}
ll KDTree::cal(Node p, int rt) {
    ll tmp = 0;
    for (int i = 0; i < k; i++) tmp += max(0, data[rt].mn[i] - p.fea[i]);
    for (int i = 0; i < k; i++) tmp += max(0, p.fea[i] - data[rt].mx[i]);
    return tmp;
}
//查询函数，寻找离p最近的m个特征属性
// void KDTree::Query(Node p, int m, int rt, int dept) {
//     if (!data) return;   //不存在的节点不遍历
//     Pair cur(0, data[rt]);        //获取当前节点的数据和到p的距离
//     cur.first = dis(p, data[rt]); //估计距离 容易爆
//     int dim = dept % k; //跟建树一样，这样能保证相同节点的dim值不变 。 只需要使用用到的维度
//     bool fg = 0;        //用于标记是否需要遍历右子树
//     int x = lson;
//     int y = rson;
//     if (p.fea[dim] >= data[rt].fea[dim]) //数据p的第dim个特征值大于等于当前的数据，则需要进入右子树
//         swap(x, y);
//     if (~flag[x]) Query(p, m, x, dept + 1); //如果节点x存在，则进入子树继续遍历

//     //以下是回溯过程，维护一个优先队列
//     if (Q.size() < m) //如果队列没有满，则继续放入     //点使用限制
//     {
//         Q.push(cur);
//         fg = 1;
//     } else {
//         if (cur.first < Q.top().first) //如果找到更小的距离，则用于替换队列Q中最大的距离的数据 。／／点使用限制
//         {
//             Q.pop();
//             Q.push(cur);
//         }
//         if (cal(p, rt) < Q.top().first) {
//             fg = 1;
//         }
//     }
//     if (~flag[y] && fg) Query(p, m, y, dept + 1);
// }

void KDTree::Query(Node p, int m, int rt, int dept) {
    int dl = inf, dr = inf;
    int dim = dept % k;
    Pair cur(0, data[rt]);        //获取当前节点的数据和到p的距离
    cur.first = dis(p, data[rt]); //估计距离 容易爆
    // cout << rt << "  ----. " << cur.first << "\n";
    if (Q.size() < m) {
        Q.push(cur);
    } else {
        if (cur.first < Q.top().first) //如果找到更小的距离，则用于替换队列Q中最大的距离的数据 。／／点使用限制
        {
            Q.pop();
            Q.push(cur);
        }
    }
    //  cout << flag[lson] << " " << flag[rson] << "-----flag\n";
    if (data[rt].l) dl = cal(p, data[rt].l);
    if (data[rt].r) dr = cal(p, data[rt].r);
    //  cout << dl << " " << dr << "dldr" << Q.top().first << "\n";
    if (dl < dr) {
        if (dl < Q.top().first) Query(p, m, data[rt].l, dim + 1);
        if (dr < Q.top().first) Query(p, m, data[rt].r, dim + 1);
    } else {
        if (dr < Q.top().first) Query(p, m, data[rt].r, dim + 1);
        if (dl < Q.top().first) Query(p, m, data[rt].l, dim + 1);
    }
}
// void KDTree::init() {
//     memset(flag, -1, sizeof flag);
//     return;
// }

int main() {
    k = 2, m = 1;
    int mm;
    n = read();
    mm = read();
    // kd.init();
    for (int i = 1; i <= n; i++) _data[i].fea[0] = read(), _data[i].fea[1] = read();
    root = kd.Build(1, n, 0);
    while (mm--) {
        Node pp;
        int opt = read();
        pp.fea[0] = read();
        pp.fea[1] = read();
        if (opt == 1)
            kd.insert(pp, root, 0);
        else {
            while (!Q.empty()) Q.pop();
            kd.Query(pp, 1, root, 0);
            printf("%lld\n", Q.top().first);
            // cout << "\n" << Q.top().second.fea[0] << " " << Q.top().second.fea[1] << " " << Q.top().first <<
            // endl;
        }
    }
    return 0;
}