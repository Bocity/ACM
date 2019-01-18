#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 400010
#define inf 0x3f3f3f3f
struct node {
    int y, next;
} e[maxn * 2];
int n, len, root, sum, Link[maxn], f[maxn], vis[maxn], son[maxn], c[maxn];
ll ans;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void insert(int x, int y) {
    e[++len].next = Link[x];
    Link[x] = len;
    e[len].y = y;
}
void getroot(int x, int fa) {
    son[x] = 1;
    f[x] = 0;
    for (int i = Link[x]; i; i = e[i].next) {
        if (e[i].y == fa || vis[e[i].y]) continue;
        getroot(e[i].y, x);
        son[x] += son[e[i].y]; //节点个数
        f[x] = max(f[x], son[e[i].y]);
    }
    //    printf("%d %d\n",x,f[x]);
    f[x] = max(f[x], sum - son[x]);
    if (f[x] < f[root]) root = x; //返回重心
}
int num[maxn], p;
ll s;
vector<int> vec;
void getdeep(int x, int fa) {
    vec.push_back(c[x]);
    int t = p - num[c[x]];
    num[c[x]] = p;
    s += t;
    ans += s;
    for (int i = Link[x]; i; i = e[i].next) {
        if (e[i].y == fa || vis[e[i].y]) continue;
        getdeep(e[i].y, x);
    }
    num[c[x]] = p - t;
    s -= t;
}
int used[maxn];
int dfs(int x, int fa) {
    used[c[x]]++;
    int o = 1;
    for (int i = Link[x]; i; i = e[i].next) {
        if (e[i].y == fa || vis[e[i].y]) continue;
        o += dfs(e[i].y, x);
    }
    used[c[x]]--;
    if (used[c[x]] == 0) {
        num[c[x]] += o;
        s += o;
    }
    return o;
}
void cal(int x) {
    s = p = 1;
    used[c[x]]++;
    num[c[x]]++;
    vec.push_back(c[x]);
    for (int i = Link[x]; i; i = e[i].next) {
        if (vis[e[i].y]) continue;
        getdeep(e[i].y, x);
        //        printf("--%d %lld\n",x,ans);
        int t = dfs(e[i].y, x);
        num[c[x]] += t;
        s += t;
        p += t;
    }
    used[c[x]]--;
    for (int i = 0; i < vec.size(); i++) num[vec[i]] = 0;
    vec.clear();
}
void solve(int x) {
    vis[x] = 1;
    cal(x); //递归计算  答案储存j在 ans中
    for (int i = Link[x]; i; i = e[i].next) {
        if (vis[e[i].y]) continue;
        root = 0;
        sum = son[e[i].y];
        getroot(e[i].y, 0);
        solve(root);
    }
}
int main() {
    int kase = 0;
    while (scanf("%d", &n) != EOF) {
        len = ans = 0;
        memset(Link, 0, sizeof(Link));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) c[i] = read();
        int x, y;
        for (int i = 1; i < n; i++) {
            int x = read(), y = read();
            insert(x, y);
            insert(y, x);
        }
        sum = n;
        f[0] = n;
        root = 0;
        getroot(1, 0);
        solve(root);
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}