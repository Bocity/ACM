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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= (a); i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 4000;
bool vis[maxn];
int a[maxn];
int st[maxn][20];
int n;
void initRMQIndex() {
    for (int i = 0; i < n; i++) st[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            st[i][j] = a[st[i][j - 1]] <= a[st[i + (1 << (j - 1))][j - 1]] ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1];
}

int RMQIndex(int s, int v) //返回最小值的下标
{
    int k = log(v - s + 1.0) / log(2.0);
    return a[st[s][k]] <= a[st[v - (1 << k) + 1][k]] ? st[s][k] : st[v - (1 << k) + 1][k];
}
int main() {
    ios::sync_with_stdio(false);
    string str;
    int m;
    while (cin >> str >> m) {
        n = str.size();
        int cnt = 0;
        REP(i, 0, n) {
            a[i] = str[i] - '0';
            if (a[i]) cnt++;
        }
        if (cnt <= m) {
            cout << 0 << endl;
            continue;
        }
        initRMQIndex();
        int pos = 0, pre = -1;
        vector<int> v;
        bool flag = false;
        while (m) {
            pos = RMQIndex(pre + 1, pre + m + 1);
            m -= pos - pre - 1;
            v.push_back(a[pos]);
            pre = pos;
            if (n - pos - 1 <= m) {
                flag = true;
                break;
            }
        }
        if (!flag) REP(i, pos + 1, n) v.push_back(a[i]);
        flag = false;
        for (auto i : v) {
            if (i || flag) cout << i;
        }
        cout << endl;
    }
}