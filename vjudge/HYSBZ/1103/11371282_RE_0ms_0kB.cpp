#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = x; i < n; ++i)
using namespace std;
int n,m,cnt,top,tim;
int t[500005],head[500005];
int st[250005],fa[250005],l[250005],r[250005];
struct data{
    int to,next;
}e[500005];
void insert(int u,int v){
    e[++cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
inline int lowbit(int x){
    return x&(-x);
}
void update(int x,int val){
    for(int i = x; i <= n+n;i+=lowbit(i))
        t[i]+=val;
}
void ask(int x){
    int ans = -1;
    for (int i = x; i; i -= lowbit(i)){
        ans +=t[i];
    }
    cout << ans << endl;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    REP(i,0,n-1){
        cin >> a >> b;
        insert(a,b);
        insert(b,a);
    }
    dfs();
    for(int i = 1; i <= n; ++i){
        update(l[i],1);
        update(r[i],-1);
        cout << l[i] << " " << r[i] << " " << t[i] << endl;
    }
    cin >> m;
    REP(i,0,n+m-1){
        cin >> c;
        if(c == 'W'){
            cin >> x;
            ask(l[x]);
        }else{
            cin >> x >> y;
            update(l[y],-1);
            update(r[y],1);
        }
    }

    return 0;
}