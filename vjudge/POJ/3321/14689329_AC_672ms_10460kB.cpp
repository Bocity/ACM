#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
vector<int> v[N];
int bitree[N];
int dfn[N][2], stamp, n;
struct EDGE{
	int next;   //下一条边的存储下标(默认0) 
	int to;     //这条边的终点 
	int w;      //权值 
}; 
EDGE edge[N << 1];
int head[N << 1];
int cnt;
void Add(int u, int v, int w) {  //起点u, 终点v, 权值w 
	//cnt为边的计数，从1开始计 
	edge[++cnt].next = head[u];
	edge[cnt].w = w;
	edge[cnt].to = v;
	head[u] = cnt;    //第一条边为当前边 
} 

void dfs(int now, int pre) {
    dfn[now][0] = ++stamp;
    int sz = v[now].size();
    for(int i=head[now]; i!=0; i=edge[i].next)
        if (edge[i].to != pre) dfs(edge[i].to, now);
    dfn[now][1] = stamp;
}
int query(int l, int r) {
    int ans = 0;
    for (int i = l - 1; i; i -= i & -i) ans -= bitree[i];
    for (int i = r; i; i -= i & -i) ans += bitree[i];
    return ans;
}
int a[N]{0};
void update(int x) {
    int val = (a[x] == 1 ? -1 : 1);
    a[x] = -a[x];
    for (int i = x; i <= n; i += i & -i) bitree[i] += val;
}

int main() {
    scanf("%d", &n);
    memset(a, -1, sizeof a);
    cnt = 0;
    for (int i = 1; i <= n; i++) update(i);
    for (int i = 1; i < n; i++) {
        int p1, p2;
        scanf("%d%d", &p1, &p2);
        Add(p1,p2,1);
        Add(p2,p1,1);
    }
    dfs(1, 0);
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        char tp[2];
        int val;
        scanf("%s %d", tp, &val);
        if (tp[0] == 'Q')
            printf("%d\n", query(dfn[val][0], dfn[val][1]));
        else
            update(dfn[val][0]);
    }
    return 0;
}