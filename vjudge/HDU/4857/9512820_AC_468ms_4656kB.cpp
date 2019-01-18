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
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 30010;
priority_queue<int> q;
vector<int> v[N];
int num[N], topo[N], nn, mm;
void toposort() {
    memset(num, 0, sizeof num);
    cin >> nn >> mm;
    int uu, vv, cnt = 0;
    for (int i = 1; i <= nn; i++) v[i].clear();
    for (int i = 0; i < mm; i++) {
        cin >> uu >> vv;
        v[vv].push_back(uu);
        num[uu]++;
    }
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
        for (int i = 0; i < nn; i++) cout << topo[i] << " \n"[i == nn - 1];
}

int main() {
    int T;
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        toposort();
    }
    return 0;
}