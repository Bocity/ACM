#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define endl '\n'
#define LSON l, m, rt << 1
#define RSON m + 1, r, rt << 1 | 1
#define lson rt << 1
#define rson rt << 1 | 1
#define REP(i,x,n) for(int i = x; i < n; ++i)
using namespace std;
typedef long long ll;
int n,m,cnt,top,tim;
const int N = 250005;
int t[N << 1],head[N << 1];
int st[N],fa[N],l[N],r[N];
ll sum[N << 2], add[N << 2];
struct data{
    int to,next;
}e[500005];
void insert(int u,int v){
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void Maintain(int rt) {
    sum[rt] = sum[lson] + sum[rson];
      //  cout << sum[rt] << endl;
    return;
}
// 延时标记下传
void Pushdown(int rt,int l,int r) {
    if ((add[rt]%2) != 0) { // 倍数变化 add[rt] != 1
        add[lson]++;
        add[rson]++;
        add[rt] = 0;
        sum[lson] =  (r - l + 1) / 2 - sum[lson];
        sum[rson] = (r - l + 1) / 2 - sum[rson];
        return;
    }
    add[rt] = 0;
}
void build(int l, int r, int rt = 1) {
    add[rt] = 0; // 倍数变化更改为1
    if (l == r) {
        sum[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(LSON);
    build(RSON);
    Maintain(rt);
  //  cout << l << " " << r<<" " << sum[rt] << endl;
    return;
}
void update(int L, int R, int c, int l, int r, int rt = 1) {
    if (L > r || R < l) return ;
    if (L <= l && r <= R) {
        Pushdown(rt,l,r);
        Maintain(rt);
        return;
    }
    Pushdown(rt , l , r);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, LSON);
    if (m < R) update(L, R, c, RSON);
    Maintain(rt);
    return;
}
int query(int L, int R, int l, int r, int rt = 1) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    Pushdown(rt,l,r);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query(L, R, LSON);
    if (m < R) ret += query(L, R, RSON);
    return ret;
}
void dfs(){
    st[++top] = 1;
    while(top){
        int now = st[top],f = fa[top--];
        if (!l[now]){
            l[now] = ++tim;
            st[++top] = now;
            for(int i = head[now]; i; i = e[i].next){
                if (e[i].to == f) continue;
                st[++top] = e[i].to;
                fa[top] = now;
            }
        }
        else{
            r[now] = ++tim;
        }
    }
}
int x,y,a,b;
char c;
int main(){
    scanf("%d",&n);
    REP(i,0,n-1){
        scanf("%d%d",&a,&b);
        insert(a,b);
        insert(b,a);
    }
    dfs();
    scanf("%d",&m);
    build(1,2*n,1);
    // for(int i = 1;i <= n ; ++i){
    //     cout << l[i] << " " << r[i] << endl;
    // }
    REP(i,0,m){
        c = getchar();
        scanf("%c",&c);
        if(c == 'Q'){
            scanf("%d",&x);
            printf("%d\n",query(l[x],r[x],1,2*n,1)/2);
        }else{
            scanf("%d",&x);
            update(l[x],r[x],0,1,2*n,1);
        }
    }

    return 0;
}
