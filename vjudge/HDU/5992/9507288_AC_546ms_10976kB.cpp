#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

#define N 200010

#define lson rt << 1
#define rson rt << 1 | 1
#define Pair pair<long long, Node>
#define Sqrt2(x) (x) * (x)
typedef long long ll;
int n, k, idx;
inline int read() {
    int x(0), f(1);
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
struct Node {
    int feature[3]; //定义属性数组
    bool operator<(const Node &u) const {
        return feature[idx] < u.feature[idx];
    }
    int cost;
} _data[N]; //_data[]数组代表输入的数据

// priority_queue<Pair> Q; //队列Q用于存放离p最近的m个数据
pair<ll, Node> res;

class KDTree {
  public:
    void Build(int, int, int, int);  //建树
    void Query(Node, int, int, int); //查询

  private:
    Node data[N << 2]; // data[]数组代表K-D树的所有节点数据
    int flag[N << 2];  //用于标记某个节点是否存在，1表示存在，-1表示不存在
} kd;

//建树步骤，参数dept代表树的深度
void KDTree::Build(int l, int r, int rt, int dept) {
    if (l > r) return;
    flag[rt] = 1;                 //表示编号为rt的节点存在
    flag[lson] = flag[rson] = -1; //当前节点的孩子暂时标记不存在
    idx = dept % 2;               //按照编号为idx的属性进行划分
    int mid = (l + r) >> 1;
    nth_element(_data + l, _data + mid, _data + r + 1); // nth_element()为STL中的函数
    data[rt] = _data[mid];
    Build(l, mid - 1, lson, dept + 1); //递归左子树
    Build(mid + 1, r, rson, dept + 1); //递归右子树
}
//查询函数，寻找离p最近的m个特征属性
void KDTree::Query(Node p, int m, int rt, int dept) {
    if (flag[rt] == -1) return; //不存在的节点不遍历
    Pair cur(0, data[rt]);      //获取当前节点的数据和到p的距离
    for (int i = 0; i < 2; i++) cur.first += (ll) Sqrt2((ll) p.feature[i] - (ll) cur.second.feature[i]);
    int dim = dept % 2; //跟建树一样，这样能保证相同节点的dim值不变
    bool fg = 0;        //用于标记是否需要遍历右子树
    int x = lson;
    int y = rson;
    if (p.feature[dim] >= data[rt].feature[dim]) //数据p的第dim个特征值大于等于当前的数据，则需要进入右子树
        swap(x, y);
    if (~flag[x]) Query(p, m, x, dept + 1); //如果节点x存在，则进入子树继续遍历

    //以下是回溯过程，维护一个优先队列
    if (res.first == -1) //如果队列没有满，则继续放入
    {
        if (cur.second.feature[2] <= p.feature[2]) {
            res.first = cur.first, res.second = cur.second;
        }
        fg = 1;
    } else {
        if (cur.second.feature[2] <= p.feature[2] &&
            (cur.first < res.first || (cur.first == res.first && cur.second.cost < res.second.cost))) //如果找到更小的距离，则用于替换队列Q中最大的距离的数据
        {
            res.first = cur.first, res.second = cur.second;
        }
        if ((ll) Sqrt2(data[rt].feature[dim] - p.feature[dim]) < res.first) {
            fg = 1;
        }
    }
    if (~flag[y] && fg) Query(p, m, y, dept + 1);
}
int T, tt;
int main() {
    T = read();

    while (T--) {
        k = 3;
        n = read();
        tt = read();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) _data[i].feature[j] = read();
            _data[i].cost = i;
        }
        kd.Build(0, n - 1, 1, 0);
        int t, m;
        // scanf("%d", &t);
        t = tt;
        while (t--) {
            Node p;
            for (int i = 0; i < k; i++) p.feature[i] = read();
            m = 1;
            res.first = -1;
            kd.Query(p, m, 1, 0);
            // // printf("the closest %d points are:\n", m);
            // Node tmp[25];
            // for (int i = 0; !Q.empty(); i++) {
            //     tmp[i] = Q.top().second;
            //     Q.pop();
            // }
            printf("%d %d %d\n", res.second.feature[0], res.second.feature[1], res.second.feature[2]);
        }
    }
    return 0;
}
