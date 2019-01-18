#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define stack Stack
#define pii pair<int, int>
#define SZ(x) ((int) (x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

const int N = 1010000;
int stack[N], top, l[N], r[N], vis[N], n, x, _;
PII a[N];
ll inv[N], ret;
struct node {
    pii val, key;
    int l, r, f;
} d[N];
int dfs(int u) {
    int s = 1;
    // if (u == 0) s--;
    if (d[u].l) s += dfs(d[u].l);
    if (d[u].r) s += dfs(d[u].r);
    ret = ret * inv[s] % mod;
    return s;
}
// void build() {
//     int top = 0;
//     rep(i, 1, n + 1) l[i] = 0, r[i] = 0, vis[i] = 0;
//     rep(i, 1, n + 1) {
//         int k = top;
//         while (k > 0 && a[stk[k - 1]] > a[i]) --k;
//         if (k) r[stk[k - 1]] = i;
//         if (k < top) l[i] = stk[k];
//         stk[k++] = i;
//         top = k;
//     }
//     rep(i, 1, n + 1) vis[l[i]] = vis[r[i]] = 1;
//     int rt = 0;
//     rep(i, 1, n + 1) if (vis[i] == 0) rt = i;
//     dfs(rt);
// }
void build(int n) {
    for(int i = 1; i <= n; ++i){
        d[i].val = a[i];
        d[i].l = 0;
        d[i].r = 0;
        d[i].f = 0;
    }
    int top = 1;
    stack[top] = 1;
    for (int i = 2; i <= n; i++) {
        while (top > 0 && d[i].val < d[stack[top]].val) //小根堆则改成小于
            top--;
        if (top > 0) // 右链中的节点
        {
            d[i].f = stack[top];
            d[i].l = d[stack[top]].r;
            d[d[stack[top]].r].f = i;
            d[stack[top]].r = i;
            stack[++top] = i;
        } else // 根节点
        {
            d[stack[1]].f = i;
            d[i].l = stack[1];
            stack[++top] = i;
        }
    }
    dfs(stack[1]);
}
int main() {
    inv[1] = 1;
    rep(i, 2, 1000001) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    for (scanf("%d", &_); _; _--) {
        scanf("%d", &n);
        rep(i, 1, n + 1) {
            scanf("%d", &x);
            a[i] = mp(-x, i);
        }
        ret = inv[2] * n % mod;
        build(n);
        printf("%lld\n", ret);
    }
}
