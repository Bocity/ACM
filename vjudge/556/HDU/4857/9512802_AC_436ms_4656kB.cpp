#include <bits/stdc++.h>
using namespace std;
const int N = 30010;
priority_queue<int> q;
vector<int> v[N];
int num[N], topo[N], nn, mm;
bool toposort() {
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
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) toposort();
}