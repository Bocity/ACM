#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1005;
struct data {
    int next , to;
}edge[MAXN * 6];
int head[MAXN] , st[MAXN] , low[MAXN] , dfn[MAXN] , block[MAXN] , du[MAXN];
int top , ord , sccnum , cont;
bool instack[MAXN];
vector <int> G[MAXN];

inline void add(int u , int v) {
    edge[cont].next = head[u];
    edge[cont].to = v;
    head[u] = cont++;
}

void init() {
    memset(head , -1 , sizeof(head));
    memset(dfn , 0 , sizeof(dfn));
    memset(du , 0 , sizeof(du));
    memset(instack , false , sizeof(instack));
    top = sccnum = ord = cont = 0;
}

void tarjan(int u) {
    low[u] = dfn[u] = ++ord;
    st[++top] = u;
    instack[u] = true;
    for(int i = head[u] ; ~i ; i = edge[i].next) {
        int v = edge[i].to;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u] , low[v]);
        }
        else if(instack[v]) {
            low[u] = min(low[u] , low[v]);
        }
    }
    if(low[u] == dfn[u]) {
        int v;
        sccnum++;
        do {
            v = st[top--];
            instack[v] = false;
            block[v] = sccnum;
        }while(u != v);
    }
}

void top_sort() {
    queue <int> que;
    while(!que.empty()) {
        que.pop();
    }
    cont = 0;
    for(int i = 1 ; i <= sccnum ; i++) {
        if(!du[i]) {
            que.push(i);
            cont++;
        }
    }
    if(cont > 1) {
        printf("Light my fire!\n");
        return ;
    }
    while(!que.empty()) {
        int temp = que.front() , cnt = 0;
        que.pop();
        for(int i = 0 ; i < G[temp].size() ; i++) {
            du[G[temp][i]]--;
            if(!du[G[temp][i]]) {
                cnt++;
                cont++;
                que.push(G[temp][i]);
            }
        }
        if(cnt > 1) {
            printf("Light my fire!\n");
            return ;
        }
    }
    if(cont != sccnum) {
        printf("Light my fire!\n");
    }
    else {
        printf("I love you my love and our love save us!\n");
    }
}

int main()
{
    int t , n , m , u , v;
    scanf("%d" , &t);
    while(t--) {
        scanf("%d %d" , &n , &m);
        init();
        for(int i = 0 ; i < m ; i++) {
            scanf("%d %d" , &u , &v);
            add(u , v);
        }
        for(int i = 1 ; i <= n ; i++) {
            G[i].clear();
            if(!dfn[i])
                tarjan(i);
        }
        if(sccnum == 1) {
            printf("I love you my love and our love save us!\n");
            continue;
        }
        for(int u = 1 ; u <= n ; u++) {
            for(int i = head[u] ; ~i ; i = edge[i].next) {
                int v = edge[i].to;
                if(block[u] != block[v]) {
                    du[block[v]]++;
                    G[block[u]].push_back(block[v]);
                }
            }
        }
        top_sort();
    }
}