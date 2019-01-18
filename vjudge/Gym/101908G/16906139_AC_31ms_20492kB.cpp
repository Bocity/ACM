#include<bits/stdc++.h>
using namespace std;

#define llp(i,a,b) for (int i = a;i<b;++i)
#define mem(a,x) memset(a,x,sizeof a)

struct node{
    int u,v,T;
    bool operator < (const node& x) const {
        return T < x.T;
    }
}ed[20050];
bool used[1050];
// const int INF = 1e6;
int TT[1050][1050];

const int MAXN = 2010;
const int MAXM = 1e6+10;
const int INF = 0x3f3f3f3f;

struct Edge{
    int to,cap,flow,next;
    Edge(){}
    Edge(int _v,int _c,int _f,int _ne):to(_v),cap(_c),flow(_f),next(_ne){}
}E[MAXM];
#define fore(x) for(int i = x;~i;i = E[i].next)

struct ISAP{
    int head[MAXN], tot;
    int dep[MAXN], gap[MAXN];
    int sz;
    queue<int> Q;
    int S[MAXN], top = 0, cur[MAXN];
    void init(int size){
        sz = size;
        tot = 0;
        mem(head,-1);
    }
    void add_arc(int u,int v,int c){
        E[tot] = Edge(v,c,0,head[u]); head[u] = tot++;
        E[tot] = Edge(u,0,0,head[v]); head[v] = tot++;
    }
    void bfs(int s,int t){
        mem(dep, -1);
        mem(gap,  0);
        dep[t] = 0;
        gap[0] = 1;
        Q.push(t);
        while(!Q.empty()){
            int u = Q.front();Q.pop();
            fore(head[u]){
                int v = E[i].to;
                if (dep[v] == -1){
                    Q.push(v);
                    dep[v] = dep[u] + 1;
                    gap[dep[v]] ++ ;
                }
            }
        }
    }
    int go(int s,int t){
        bfs(s,t);
        memcpy(cur,head,sizeof head);

        int ans = 0;
        int u = s;
        while(dep[s] < sz){
            if (u == t){
                int inser, tflow = INF;
                llp(i,0,top){
                    if (tflow > E[S[i]].cap - E[S[i]].flow){
                        tflow = E[S[i]].cap - E[S[i]].flow;
                        inser = i;
                    }
                }
                llp(i,0,top){
                    E[S[i]].flow += tflow;
                    E[S[i]^1].flow -= tflow;
                }
                ans += tflow;
                top = inser;
                u = E[S[top]^1].to;
            }

            int tmp = -1;
            fore(cur[u]){
                if (E[i].cap - E[i].flow && dep[u] == dep[E[i].to]+1){
                    tmp = i;
                    break;
                }
            }

            if (~tmp){
                cur[u] = tmp;
                S[top++] = tmp;
                u = E[tmp].to;
            }
            else{
                int mindep =sz;
                fore(head[u]){
                    if (E[i].cap - E[i].flow && mindep > dep[E[i].to]){
                        mindep = dep[E[i].to];
                        cur[u] = i;
                    }
                }
                if (! -- gap[dep[u]]) break;
                dep[u] = mindep+1;
                gap[dep[u]] ++;
                if (u!=s) u = E[S[--top]^1].to;
            }
        }
        return ans;
    }
}solver;

int main()
{
    // solver.init(2);
    // solver.add_arc(1,2,10);
    // cout<<solver.go(1,2)<<endl;
    // return 0;

    int P,R,C;
    scanf("%d%d%d",&P,&R,&C);
    int s = P+R+1, t = P+R+2;
    solver.init(t);
    // P+1..P+R -> 1..P
    int sum =  0, sum2 = 0;
    int D,EE;
    llp(i,1,P+1) {
        scanf("%d",&D);
        solver.add_arc(i,t,D);
        sum += D;
    }
    llp(i,P+1,P+R+1){
        scanf("%d",&EE);
        solver.add_arc(s,i,EE);    
        sum2 += EE;
    }
    
    if (sum > sum2) {
        puts("-1");
        return 0;
    }

    llp(i,0,C){
        scanf("%d%d%d",&ed[i].v, &ed[i].u, &ed[i].T);
        TT[ed[i].u][ed[i].v] = ed[i].T;
        ed[i].u += P;//!!!!!!
    }
    sort(ed,ed+C);

    sum2 = sum+1;
    int pos =0, cnt = 0;
    mem(used,0);
    while(pos < C && (sum2<sum || cnt < P) ){
        solver.add_arc(ed[pos].u, ed[pos].v, INF);
        if (!used[ed[pos].v]) used[ed[pos].v] = 1, cnt++;
        // if (!used2[ed[pos].u]) used2[ed[pos].u] = 1, sum2 += ;
        pos++;
    }
    if (cnt<P || sum2<sum) {
        puts("-1");
        return 0;
    }
    // cout<<"yes"<<endl;

    int flow = solver.go(s,t);
    int ans = ed[pos-1].T;
    if (flow < sum) llp(i,pos,C){
        solver.add_arc(ed[i].u, ed[i].v, INF);
        flow += solver.go(s,t);
        if (flow >= sum) {
            ans = ed[i].T;
            break;
        }
    }

    if (flow >= sum){
        printf("%d\n",ans);
    }
    else puts("-1");

    return 0;
}