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
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
namespace fastIO {
#define BUF_SIZE 100000
// fread -> read
bool IOerror = 0;
inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if (p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if (pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
    char ch;
    while (blank(ch = nc()))
        ;
    if (IOerror) return;
    for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
        ;
}
#undef BUF_SIZE
};
using namespace fastIO;
const int N = 1010;
priority_queue<int> q;
vector<int> v[N];
int num[N], topo[N], nn, mm;
bool toposort() {
    while (cin >> nn >> mm) {
        memset(num, 0, sizeof num);
        int uu, vv, cnt = 0;
        for (int i = 1; i <= nn; i++) v[i].clear();
        for (int i = 0; i < mm; i++) {
            cin >> uu >> vv;
            v[vv].push_back(uu);
            num[uu]++;
        }
        while (!q.empty()) q.pop();
        for (int i = 1; i <= nn; i++)
            if (!num[i]) q.push(i);
        vv = nn;
        while (!q.empty()) {
            uu = q.top();
            q.pop();
            cnt++;
            topo[--vv] = uu;
            for (auto i : v[uu]) {
                num[i]--;
                if (!num[i]) q.push(i);
            }
        }
        if (cnt != nn)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        // if (cnt != nn - 1) return false;
        // return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    toposort();
    return 0;
}