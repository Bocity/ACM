#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int a[N];
map<char, int> mp;
vector<pair<int, char>> v;
int main() {
    ios::sync_with_stdio(false);
    int t, n, m;
    while (cin >> n >> m) {
        if (n == m && !n) break;
        char c;
        mp.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c;
                mp[c]++;
            }
        }
        map<char, int>::iterator it = mp.end();
        it--;
        v.clear();
        for (;; it--) {
            v.push_back(pair<int, char>(it->second, -it->first));
            if (it == mp.begin()) break;
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        cout << (char) (-v[0].second) << " " << v[0].first;
        for (int i = 1; i < v.size(); i++) {
            cout << " " << (char) (-v[i].second) << " " << v[i].first;
        }
        cout << endl;
    }
}