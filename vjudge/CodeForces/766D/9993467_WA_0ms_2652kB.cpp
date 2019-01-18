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
    if (pre[x] == x) {
        return x;
    }
    int order = pre[x];
    pre[x] = find(pre[x]);
    relation[x] = (relation[x] + relation[order]) % 2;
    return pre[x];
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> s1;
        num[s1] = i;
    }
    for (int i = 0; i < n; ++i) {
        pre[i] = i;
        relation[i] = 0;
    }
    int x, y, z;
    for (int i = 0; i < m; ++i) {
        cin >> z >> s1 >> s2;
        --z;
        x = num[s1], y = num[s2];
        int a = find(x), b = find(y);
        if (a != b) {
            cout << "YES" << endl;
            pre[b] = a;
            relation[b] = (relation[x] - relation[y] + z + 2) % 2;
        } else {
            int p = (relation[x] - relation[y] + 2) % 2;
            if (p == z)
                cout << "YES";
            else
                cout << "NO" << endl;
        }
    }
    for (int i = 0; i < q; ++i) {
        cin >> s1 >> s2;
        x = num[s1], y = num[s2];
        int a = find(x), b = find(y);
        if (a != b)
            cout << "2" << endl;
        else
            cout << (relation[x] - relation[y] + 2) % 2 + 1 << endl;
    }
    return 0;
}