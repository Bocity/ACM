#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (x); i >= (n); i--)
#define endl "\n"
typedef long long ll;
using namespace std;
map<string, int> num;
int n, m, q;
int pre[100005], relation[100005];
string s1, s2;

int find(int x) {
    if (pre[x] == x) return x;
    int order = pre[x];
    pre[x] = find(pre[x]);
    relation[x] = (relation[x] + relation[order]) % 2; // 修改
    return pre[x];
}

int main() {
    cin >> n >> m >> q;
    REP(i, 0, n) {
        cin >> s1;
        num[s1] = i;
    }
    REP(i, 0, n) {
        pre[i] = i;
        relation[i] = 0;
    }
    int x, y, z;
    REP(i, 0, m) {
        cin >> z >> s1 >> s2;
        --z;
        x = num[s1], y = num[s2];
        int a = find(x), b = find(y);
        if (a != b) {
            cout << "YES" << endl;
            pre[b] = a;
            relation[b] = (relation[x] - relation[y] + z + 2) % 2;
        } else {
            int p = (relation[x] - relation[y]) % 2;
            if (p == z)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    REP(i, 0, q) {
        cin >> s1 >> s2;
        x = num[s1], y = num[s2];
        int a = find(x), b = find(y);
        if (a != b)
            cout << "3" << endl;
        else
            cout << (relation[x] - relation[y] + 2) % 2 + 1 << endl;
    }
    return 0;
}