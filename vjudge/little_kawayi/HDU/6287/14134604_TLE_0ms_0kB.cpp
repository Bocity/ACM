#include <bits/stdc++.h>
#define REP(i,x,n) for(int i= x;i < n; ++i)
#define endl "\n"
#define hash Hasdhfiuew
#define maxn  100005
#define N 100005
using namespace std;
typedef long long ll;
struct node{
    int l,r,id,d;
}Q[maxn];
int n,m,k;
int L = 1, R = 0;
int pos[maxn];
int a[maxn];
int ans[maxn];
int prime[N],tot = 0;
bool vis[N] = {true,true};
vector<int> A[maxn];
unordered_map<int,int> hash;
bool cmp(node a, node b){
    if (pos[a.l] == pos[b.l])
    return a.r < b.r;
    return pos[a.l] < pos[b.l];
}
int fuck[maxn << 1]{0};
void add(int x){
    //cout <<" + " << a[x] << endl;
    for(auto &y:A[a[x]]){
        fuck[y]++;
        //cout << y << endl;
    }
}
void del(int x){
    //cout <<"-" <<a[x] << endl;
    for(auto &y:A[a[x]]){
        fuck[y]--;
        //cout << y << endl;
    }
}
bool check(int x){
    int ppos = 0;
    while (x > 1){
        if (x % prime[ppos] == 0){
            int z = 0;
            while (x % prime[ppos] == 0){
                x /= prime[ppos];
                z++;
            }
            if (fuck[prime[ppos]] < z) return 0;
        }
        ppos++;
    }
    return 1;
}
void screen(){
    for(int i = 2; i < N; ++i){
        if (!vis[i]) prime[tot++] = i;
        for(int j = 0; j < tot && (ll) i * prime[j] < N;j ++){
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
int t;
void stay(){
    cin >> n >> m;
    int sz = sqrt(n);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        int temp = a[i];
        int ppos = 0;
        if (A[a[i]].size() == 0){
        while(temp > 1 && temp >= prime[ppos]){
            //if (A[a[i]].size() > 0) break;
            if (!vis[temp]) {A[a[i]].push_back(temp);break;}
            while (temp % prime[ppos] == 0){
                temp /= prime[ppos];
                A[a[i]].push_back(prime[ppos]);
            }
            ppos ++;
        }
        }
        pos[i] = i / sz;
    }
    for(int i = 1; i <= m; ++i){
        cin >> Q[i].l >> Q[i].r >> Q[i].d;
        Q[i].id = i;
    }
    sort(Q + 1, Q + 1 + m,cmp);
    L = 1, R = 0;
    for(int i = 1; i <= m; ++i){
        while(R > Q[i].r){
            del(R);
            R--;
        }
        while(R < Q[i].r){
            R++;
            add(R);
        }
        while(L < Q[i].l){
            del(L);
            L++;
        }
        while(L > Q[i].l){
            L--;
            add(L);
        }
        //cout << L << " " << R << endl;
        ans[Q[i].id] = check(Q[i].d);
    }
    for(int i = 1; i <=m; ++i){
        cout << (ans[i]?"Yes":"No") << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin >> t;
    screen();
    //cout << tot;
   // cin >> tot;
    REP(i,0,tot){
        hash[prime[i]] = i;
    }
    while(t--){
        stay();
    }
    return 0;
}
/*
1
5 4
6 4 7 2 5
1 2 24
1 3 18
2 5 17
3 5 35
*/