#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

#define N 500010

#define lson rt << 1
#define rson rt << 1 | 1
#define Pair pair<long long, Node>
#define Sqrt2(x) (x) * (x)

int n, k, idx;
typedef long long ll;
struct Node {
    ll feature[5]; //定义属性数组
    bool operator<(const Node &u) const {
        return feature[idx] < u.feature[idx];
    }
    int cost;
} _data[N]; //_data[]数组代表输入的数据

priority_queue<Pair> Q; //队列Q用于存放离p最近的m个数据

class KDTree {
  public:
    void Build(int, int, int, int);  //建树
    void Query(Node, int, int, int); //查询
    void add(Node, int, int); //查
  private:
    Node data[4 * N]; // data[]数组代表K-D树的所有节点数据
    int flag[4 * N];  //用于标记某个节点是否存在，1表示存在，-1表示不存在
} kd;

//建树步骤，参数dept代表树的深度
void KDTree::Build(int l, int r, int rt, int dept) {
    if (l > r) return;
    flag[rt] = 1;                 //表示编号为rt的节点存在
    flag[lson] = flag[rson] = -1; //当前节点的孩子暂时标记不存在
    idx = dept % k;               //按照编号为idx的属性进行划分
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
    for (int i = 0; i < k; i++) cur.first += (ll) abs((ll) cur.second.feature[i] - (ll) p.feature[i]);
    int dim = dept % k; //跟建树一样，这样能保证相同节点的dim值不变
    bool fg = 0;        //用于标记是否需要遍历右子树
    int x = lson;
    int y = rson;
    if (p.feature[dim] >= data[rt].feature[dim]) //数据p的第dim个特征值大于等于当前的数据，则需要进入右子树
        swap(x, y);
    if (~flag[x]) Query(p, m, x, dept + 1); //如果节点x存在，则进入子树继续遍历

    //以下是回溯过程，维护一个优先队列
    if (Q.size() < m) //如果队列没有满，则继续放入
    {
        Q.push(cur);
        fg = 1;
    } else {
        if ((cur.first < Q.top().first)) //如果找到更小的距离，则用于替换队列Q中最大的距离的数据
        {
            Q.pop();
            Q.push(cur);
        }
        if ((ll) abs((ll) p.feature[dim] - (ll) data[rt].feature[dim]) < Q.top().first) {
            fg = 1;
        }
    }
    if (~flag[y] && fg) Query(p, m, y, dept + 1);
}
void KDTree::add(Node p, int rt, int dept) // 添加操作
{
    if (flag[rt] == -1) {
        flag[rt] = 1;
        data[rt] = p;
        flag[lson] = flag[rson] = -1;
        return;
    }
    int dim = dept % k; //跟建树一样，这样能保证相同节点的dim值不变;
    int x = lson;
    int y = rson;
    if (p.feature[0]==data[rt].feature[0]&&p.feature[1]==data[rt].feature[1])
    return ;
    if (p.feature[dim] < data[rt].feature[dim])
        add(p, x, dept + 1);
    else
        add(p, y, dept + 1);
}
int t, m;
int main() {
        k = 2;
        scanf("%d %d",&n,&t);
        for(int i=0;i<n;i++)
        for (int j = 0; j < 2; j++) scanf("%lld", &_data[i].feature[j]);
        kd.Build(0, n - 1, 1, 0);
        Node p;
        m = 1;
        int c;
        for(int i=0;i<t;i++){
            scanf("%d %lld %lld",&c,&p.feature[0],&p.feature[1]);
            if (c==1){
                kd.add(p,1,0);
            }
            if (c==2){
                kd.Query(p, m, 1, 0);
                while (!Q.empty()) Q.pop(); //事先需要清空优先队
               // cout<<Q.top().second.feature[0]<<" "<<Q.top().second.feature[1]<<endl;
               printf("%lld\n",Q.top().first);
            }

        }
    return 0;
}