#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
using namespace std;
const int maxn = 1111;
struct node {
    int u, v, next;
} edge[20005];
struct E {
    int w, id;
};
queue<E> q;
int head[1005], cnt, vis[1005];
void addedge(int u, int v) {
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].u = v;
    edge[cnt].v = u;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}
int main() {
    ios::sync_with_stdio(false);
    int T;
    int n, m, x, y;
    while (cin >> n >> m >> x >> y) {
        cnt = 0;
        memset(head, -1, sizeof(head));
        memset(vis, -1, sizeof(vis));

        for (int i = 0; i < m; i++) {
            int c, d;
            cin >> c >> d;
            addedge(c, d);
        }
        int xx;
        E a;
        int flag = 0;
        while (!q.empty()) q.pop();
        for (int i = 0; i < x; i++) {
            cin >> xx;
            a.w = xx;
            a.id = 0;
            vis[xx] = 0;
            q.push(a);
        }
        for (int i = 0; i < y; i++) {
            cin>>xx;
            vis[xx] = 1;
            a.w = xx;
            a.id = 1;
            q.push(a);
        }
        while (!q.empty()) //有给出的好坏人去区分比赛中的好坏人。
        {
            a = q.front();
            q.pop();
            int u = a.w, id = a.id;
            for (int i = head[u]; i != -1; i = edge[i].next) {
                int v = edge[i].v;
                if (vis[v] == -1) {
                    vis[v] = !vis[u];
                    a.w = v;
                    a.id = vis[v];
                    q.push(a);
                } else if (vis[v] == vis[u]) {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
            for (int i = 1; i <= n; i++) //无法区分的好坏人，先判断是否是独立的个体，是则直接no,否则任意标记一个属性，进行再一轮推断。
            {
                if (vis[i] == -1) {
                    if (flag) break;
                    if (head[i] == -1) {
                        flag = 1;
                        break;
                    }
                    vis[i] = 0;
                    a.w = i;
                    a.id = 0;
                    q.push(a);
                    while (!q.empty()) {
                        a = q.front();
                        q.pop();
                        int u = a.w, id = a.id;
                        for (int j = head[u]; j != -1; j = edge[j].next) {
                            int v = edge[j].v;
                            if (vis[v] == -1) {
                                vis[v] = !vis[u];
                                a.w = v;
                                a.id = vis[v];
                                q.push(a);
                            } else if (vis[v] == vis[u]) {
                                flag = 1;
                                break;
                            }
                        }
                    }
                }
            }
        if (flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;

}