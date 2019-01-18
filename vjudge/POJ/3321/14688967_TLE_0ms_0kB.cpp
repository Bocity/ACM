#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;
vector<int> v[N];
int bitree[N];
int dfn[N][2], stamp, n;
void dfs(int now, int pre) {
    dfn[now][0] = ++stamp;
    for (int i = v[now].size() - 1; i >= 0; i--)
        if (v[now][i] != pre) dfs(v[now][i], now);
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
    //for (int i = 1; i <= n; i++) v[i].reserve(100);
    memset(a, -1, sizeof a);
    for (int i = 1; i <= n; i++) update(i);
    for (int i = 1; i < n; i++) {
        int p1, p2;
        scanf("%d%d", &p1, &p2);
        v[p1].push_back(p2);
        v[p2].push_back(p1);
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