#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1005;
int col[N], Map[N][N];
int p1[N], p2[N], n, a, b, m;
bool ff[N] = {0};

// 0为白色，1为黑色
bool BFS(int s, int n) {
    queue<int> p;
    p.push(s);
    col[s] = 1; //将搜索起始点涂成黑色
    while (!p.empty()) {
        int from = p.front();
        p.pop();
        for (int i = 1; i <= n; i++) {
            if (Map[from][i] && col[i] == -1) //如果从from到i的边存在（为邻接点） && i点未着色
            {
                p.push(i);           //将i点加入队列
                col[i] = !col[from]; //将i点染成不同的颜色
            }
            if (Map[from][i] &&
                col[from] ==
                    col[i]) //如果从from到i的边存在（为邻接点） && i点和from点这一对邻接点颜色相同，则不是二分图
                return false;
        }
    }
    return true; //搜索完s点和所有点的关系，并将邻接点着色，且邻接点未发现相同色则返回true
}

int main() {
    int c1, c2, c3, c4;
    while (cin >> c1 >> c2 >> c3 >> c4) {
        memset(col, -1, sizeof(col));
        memset(ff, 0, sizeof(ff));
        memset(Map, 0, sizeof(Map));
        n = c1;
        m = c2;
        int anss = n;
        // cin >> n >> m;  //n 为有多少点，m为有多少边
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (!ff[a]) {
                ff[a] = true;
                anss--;
            }
            if (!ff[b]) {
                ff[b] = true;
                anss--;
            }
            Map[a][b] = Map[b][a] = 1;
        }
        for (int i = 0; i < c3; i++) {
            cin >> p1[i];
            col[p1[i]] = 1;
            int a = p1[i];
            if (!ff[a]) {
                ff[a] = true;
                anss--;
            }
        }
        for (int i = 0; i < c4; i++) {
            cin >> p2[i];
            col[p2[i]] = 0;
            int a = p2[i];
            if (!ff[a]) {
                ff[a] = true;
                anss--;
            }
        }
        bool flag1 = false;
        bool flag2 = false;
        if (anss > 0) {
            flag1 = true;
            flag2 = true;
            n = 0;
        }
        for (int i = 1; i <= n; i++) //遍历并搜索各个连通分支
        {
            if (col[i] == -1 && !BFS(i, n)) //每次找没有着色的点进行判断，如果从它开始BFS发现相同色邻接点则不是二分图
            {
                flag1 = true;
                break;
            }
        }
        memset(col, -1, sizeof(col));
        for (int i = 0; i < c3; i++) {
            col[p1[i]] = 0;
        }
        for (int i = 0; i < c4; i++) {
            col[p2[i]] = 1;
        }
        for (int i = 1; i <= n; i++) //遍历并搜索各个连通分支
        {
            if (col[i] == -1 && !BFS(i, n)) //每次找没有着色的点进行判断，如果从它开始BFS发现相同色邻接点则不是二分图
            {
                flag2 = true;
                break;
            }
        }
        bool flag = ((!flag1) || (!flag2));
        if (anss == 0) flag = true;
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}